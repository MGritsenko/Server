#include "findpatterntask.h"

FindPatternTask::FindPatternTask(QPixmap image)
	: m_image(image)
{}

FindPatternTask::~FindPatternTask()
{}

void FindPatternTask::run()
{
	auto matImg = qImage2mat(m_image.toImage());
	auto resImg = mat2qImage(matImg).rgbSwapped();

	emit result(QPixmap::fromImage(resImg));
}

QImage FindPatternTask::mat2qImage(cv::Mat const& src)
{
	cv::Mat temp;
	cvtColor(src, temp, cv::COLOR_BGR2RGB);
	QImage dest((const uchar *)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
	dest.bits();
	
	return dest;
}

cv::Mat FindPatternTask::qImage2mat(QImage const& src)
{
	cv::Mat tmp(src.height(), src.width(), CV_8UC4, (uchar*)src.bits(), src.bytesPerLine());
	cv::Mat result;
	cvtColor(tmp, result, cv::COLOR_RGB2BGR);

	return result;
}
