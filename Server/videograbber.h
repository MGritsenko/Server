#pragma once

#include <QObject>
#include <QPixmap>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class VideoGrabber : public QObject
{
	Q_OBJECT

public:
	VideoGrabber(QObject *parent = 0, int device = 0);
	~VideoGrabber();

	bool isOpened();
	void grabFrame();

private:
	void process(cv::Mat& frame);

signals:
	void sendFrame(QPixmap, QByteArray);

private:
	cv::VideoCapture* m_videoCapture;

	int m_device;
};
