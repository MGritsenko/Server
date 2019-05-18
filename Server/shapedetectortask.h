#pragma once

#include <QObject>
#include <QRunnable>
#include <QPixmap>
#include <QVector>
#include <QPoint>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

class ShapeDetectorTask : public QObject, public QRunnable
{
	Q_OBJECT

public:
	ShapeDetectorTask(QPixmap data, cv::Scalar from, cv::Scalar to, int maxCorners);
	~ShapeDetectorTask();

protected:
	virtual void run() override;

signals:
	void result(QPixmap data, QVector<QVector<QPoint>>);

private:
	QPixmap m_data;
	cv::Scalar m_from;
	cv::Scalar m_to;

	int m_devicesConnected;
};
