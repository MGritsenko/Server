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

class FindPatternTask : public QObject, public QRunnable
{
	Q_OBJECT

public:
	FindPatternTask(QPixmap image, cv::Scalar from, cv::Scalar to);
	~FindPatternTask();

signals:
	void result(QPixmap);

protected:
	virtual void run() override;

private:
	QImage mat2qImage(cv::Mat const& src);
	cv::Mat qImage2mat(QImage const& src);

private:
	QPixmap m_image;
	cv::Scalar m_from;
	cv::Scalar m_to;
};
