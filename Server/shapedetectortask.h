#pragma once

#include <QObject>
#include <QRunnable>
#include <QPixmap>

class ShapeDetectorTask : public QObject, public QRunnable
{
	Q_OBJECT

public:
	ShapeDetectorTask(const QPixmap* data);
	~ShapeDetectorTask();

protected:
	virtual void run() override;

signals:
	void result(QPixmap data);

private:
	const QPixmap* m_data;
};
