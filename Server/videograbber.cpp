#include "videograbber.h"

#include <QDebug>
#include<QBuffer>

VideoGrabber::VideoGrabber(QObject *parent, int device)
	: QObject(parent)
	, m_device(device)
{
	m_videoCapture = new cv::VideoCapture();
	m_videoCapture->open(m_device);

	qDebug() << "Created";
}

VideoGrabber::~VideoGrabber()
{
	m_videoCapture->release();

	delete m_videoCapture;
}

bool VideoGrabber::isOpened()
{
	return m_videoCapture->isOpened();
}

void VideoGrabber::grabFrame()
{
	cv::Mat outframe;
	m_videoCapture->read(outframe);

	if (outframe.empty())
	{
		return;
	}

	process(outframe);

	QImage img(outframe.data, outframe.cols, outframe.rows, QImage::Format::Format_RGB888);

	auto pixmap = QPixmap::fromImage(img);
	QByteArray bArray;
	QBuffer buffer(&bArray);
	buffer.open(QIODevice::WriteOnly);
	pixmap.save(&buffer, "JPG");

	emit sendFrame(pixmap, bArray);
}

void VideoGrabber::process(cv::Mat& outframe)
{
	cv::flip(outframe, outframe, cv::ROTATE_180);
	cv::cvtColor(outframe, outframe, cv::COLOR_BGR2RGB);
}
