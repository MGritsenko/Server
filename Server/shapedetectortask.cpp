#include "shapedetectortask.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "findpatterntask.h"

ShapeDetectorTask::ShapeDetectorTask(const QPixmap* data)
	: QRunnable()
	, m_data(data)
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
	auto srcImg = qImage2mat(m_data->toImage());
	cv::Mat converted;
	inRange(srcImg, cv::Scalar(200, 0, 0), cv::Scalar(255, 170, 210), converted);
	cv::blur(converted, converted, cv::Size(3, 3));

	cv::Mat cannyOutput;
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;

	/// Detect edges using canny
	cv::Canny(converted, cannyOutput, thresh, thresh * 2, 3);
	/// Find contours
	cv::findContours(cannyOutput, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	/// Draw contours
	cv::Mat drawing = cv::Mat::zeros(cannyOutput.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		cv::drawContours(drawing, contours, i, cv::Scalar(255, 255, 255), 2, 8, hierarchy, 0, cv::Point());
	}

	auto res = mat2qImage(drawing).rgbSwapped();
	emit result(QPixmap::fromImage(res));
}
