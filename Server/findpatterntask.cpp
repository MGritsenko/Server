#include "findpatterntask.h"

FindPatternTask::FindPatternTask(QPixmap image, cv::Scalar fromR, cv::Scalar toR, cv::Scalar fromG, cv::Scalar toG)
	: m_image(image)
	, m_fromR(fromR)
	, m_toR(toR)
	, m_fromG(fromG)
	, m_toG(toG)
{}

FindPatternTask::~FindPatternTask()
{}

void FindPatternTask::run()
{
	auto matImg = qImage2mat(m_image.toImage());

	cv::Mat convertedR;
	inRange(matImg, m_fromR, m_toR, convertedR);

	cv::Mat convertedG;
	inRange(matImg, m_fromG, m_toG, convertedG);

	auto resImgR = mat2qImage(convertedR).rgbSwapped();
	auto resImgG = mat2qImage(convertedG).rgbSwapped();
		
	emit result(QPixmap::fromImage(resImgR), QPixmap::fromImage(resImgG));
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
