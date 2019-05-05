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
