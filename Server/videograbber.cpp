#include "videograbber.h"

#include <QDebug>
#include<QBuffer>

VideoGrabber::VideoGrabber(QObject *parent, int device)
	: QObject(parent)
	, m_device(device)
	, m_videoCaptureCamera(nullptr)
	, m_videoCaptureFile(nullptr)
{
	m_videoCaptureCamera = new cv::VideoCapture();
	m_videoCaptureCamera->open(m_device);
	m_videoCaptureCamera->set(cv::CAP_PROP_FRAME_WIDTH, 640);
	m_videoCaptureCamera->set(cv::CAP_PROP_FRAME_HEIGHT, 360);

	qDebug() << "Created";
}

VideoGrabber::VideoGrabber(QString fileName)
	: QObject(nullptr)
	, m_fileName(fileName)
{
	m_videoCaptureFile = new cv::VideoCapture();
	m_videoCaptureFile->open(m_fileName.toStdString());

	if (!m_videoCaptureFile->isOpened())
	{
		qDebug() << "Error opening video file" << endl;
		return;
	}

	m_videoCaptureFile->set(cv::CAP_PROP_FRAME_WIDTH, 640);
	m_videoCaptureFile->set(cv::CAP_PROP_FRAME_HEIGHT, 360);
}

VideoGrabber::~VideoGrabber()
{
	if (m_videoCaptureCamera != nullptr)
	{
		delete m_videoCaptureCamera;
	}

	if (m_videoCaptureFile != nullptr)
	{
		delete m_videoCaptureFile;
	}
}

bool VideoGrabber::isOpened()
{
	return m_videoCaptureCamera->isOpened();
}

void VideoGrabber::grabFrameFromCamera()
{
	cv::Mat outframe;
	m_videoCaptureCamera->read(outframe);

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

void VideoGrabber::grabFrameFromFile()
{
	cv::Mat outframe;
	m_videoCaptureFile->read(outframe);

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
	//cv::flip(outframe, outframe, cv::ROTATE_180);
	cv::cvtColor(outframe, outframe, cv::COLOR_BGR2RGB);
}
