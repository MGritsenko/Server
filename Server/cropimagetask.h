#pragma once

#include <QObject>
#include <QRunnable>
#include <QVector>
#include <QPoint>
#include <QImage>
#include <QByteArray>
#include <QPixmap>

class CropImageTask : public QObject, public QRunnable
{
	Q_OBJECT

public:
	CropImageTask(QVector<QVector<QPoint>> shapes, QPixmap pixmap);
	~CropImageTask();

signals:
	void result(QVector<QPixmap>, QVector<QByteArray>);

protected:
	virtual void run() override;

private:
	QVector<QVector<QPoint>> m_shapes;
	QImage m_image;
};
