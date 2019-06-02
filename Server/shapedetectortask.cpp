#include "shapedetectortask.h"
#include "findpatterntask.h"

cv::RNG rng(12345);

ShapeDetectorTask::ShapeDetectorTask(QPixmap data, cv::Scalar from, cv::Scalar to, int shapesToDetect)
	: QRunnable()
	, m_data(data)
	, m_from(from)
	, m_to(to)
	, m_shapesToDetect(shapesToDetect)
{
}

ShapeDetectorTask::~ShapeDetectorTask()
{
}

void ShapeDetectorTask::run()
{
	auto thresh = 100;
	auto maxThresh = 255;

	/// Load source image and convert it to gray
	auto srcImg = qImage2mat(m_data.toImage());
	cv::Mat converted;
	inRange(srcImg, m_from, m_to, converted);
	cv::blur(converted, converted, cv::Size(3, 3));

	cv::Mat cannyOutput;
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;

	/// Detect edges using canny
	cv::Canny(converted, cannyOutput, thresh, thresh * 2, 3);
	/// Find contours
	cv::findContours(cannyOutput, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	std::vector<std::vector<cv::Point>> smoothCon;
	smoothCon.resize(contours.size());
	for (size_t k = 0; k < contours.size(); k++)
	{
		approxPolyDP(cv::Mat(contours[k]), smoothCon[k], 0.01, true);
	}

	/// Draw contours
	cv::Mat drawing = cv::Mat::zeros(cannyOutput.size(), CV_8UC3);
	for (int i = 0; i < smoothCon.size(); i++)
	{
		cv::drawContours(drawing, smoothCon, i, cv::Scalar(255, 255, 255), 2, 8, hierarchy, 0, cv::Point());
	}

	cv::Mat gray;
	cvtColor(drawing, gray, cv::COLOR_BGR2GRAY);
	cv::blur(gray, gray, cv::Size(3, 3));

	int shapeCorners = 4;
	double qualityLevel = 0.01;
	double minDistance = 10;
	int blockSize = 15;
	bool useHarrisDetector = false;
	double k = 0.04;
	std::vector<cv::Point2f> corners;
	goodFeaturesToTrack(gray,
		corners,
		m_shapesToDetect * shapeCorners,
		qualityLevel,
		minDistance,
		cv::Mat(),
		blockSize,
		useHarrisDetector,
		k);

	for (int i = 0; i < corners.size(); i++)
	{
		cv::circle(drawing, corners[i], 8, cv::Scalar(0, 255, 0), -1, 8, 0);
	}

	std::sort(corners.begin(), corners.end(), [](auto& first, auto& second)
	{
		return first.y < second.y;
	});
	std::sort(corners.begin(), corners.end(), [](auto& first, auto& second)
	{
		return first.x < second.x;
	});

	QVector<QVector<QPoint>> shapes;
	shapes.resize(m_shapesToDetect);

	for (int i = 0, j = 0; j < corners.size(); j++)
	{
		shapes[i].push_back(QPoint(corners[j].x, corners[j].y));
		
		if (j != 0 && (j + 1) % shapeCorners == 0)
		{
			i++;
		}
	}

	auto res = mat2qImage(drawing).rgbSwapped();
	emit result(QPixmap::fromImage(res), shapes);
}
