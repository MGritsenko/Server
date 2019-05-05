#pragma once

#include <QObject>
#include <QRunnable>
#include <QByteArray>
#include <QImage>
#include <QPixmap>
#include <QBuffer>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"


static QImage mat2qImage(cv::Mat const& src)
{
	cv::Mat temp;
	cvtColor(src, temp, cv::COLOR_BGR2RGB);
	QImage dest((const uchar *)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
	dest.bits();

	return dest;
}

static cv::Mat qImage2mat(QImage const& src)
{
	cv::Mat tmp(src.height(), src.width(), CV_8UC4, (uchar*)src.bits(), src.bytesPerLine());
	cv::Mat result;
	cvtColor(tmp, result, cv::COLOR_RGB2BGR);

	return result;
}


class FindPatternTask : public QObject, public QRunnable
{
	Q_OBJECT

public:
	FindPatternTask(QPixmap image, cv::Scalar fromR, cv::Scalar toR, cv::Scalar fromG, cv::Scalar toG);
	~FindPatternTask();

signals:
	void result(QPixmap, QPixmap);

protected:
	virtual void run() override;

private:
	QPixmap m_image;
	cv::Scalar m_fromG;
	cv::Scalar m_toG;
	cv::Scalar m_fromR;
	cv::Scalar m_toR;
};
