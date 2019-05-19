#pragma once

#include <QObject>
#include <QPixmap>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class VideoGrabber : public QObject
{
	Q_OBJECT

public:
	VideoGrabber(QObject *parent, int device);
	VideoGrabber(QString fileName);
	~VideoGrabber();

	bool isOpened();
	void grabFrameFromCamera();
	void grabFrameFromFile();

private:
	void process(cv::Mat& frame);

signals:
	void sendFrame(QPixmap, QByteArray);

private:
	cv::VideoCapture* m_videoCaptureCamera;
	cv::VideoCapture* m_videoCaptureFile;

	int m_device;
	QString m_fileName;
};
