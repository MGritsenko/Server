#pragma once

#include <QObject>
#include <QRunnable>
#include <QVector>
#include <QPoint>
#include <QImage>
#include <QByteArray>
#include <QPixmap>
#include <QMap>
#include <QPair>

class CropImageTask : public QObject, public QRunnable
{
	Q_OBJECT

public:
	CropImageTask(QMap<QString, QVector<QPoint>> shapes, QPixmap pixmap);
	~CropImageTask();

signals:
	void result(QVector<QPair<QPixmap, QString>>, QVector<QPair<QByteArray, QString>>);

protected:
	virtual void run() override;

private:
	QMap<QString, QVector<QPoint>> m_shapes;
	QImage m_image;
};
