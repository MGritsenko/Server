#pragma once

#include <QRunnable>
#include <QObject>

class Task : public QObject,  public QRunnable
{
	Q_OBJECT

public:
	Task(int width, int height);
	~Task();

signals:
	void result(QByteArray data);

protected:
	virtual void run() override;

private:
	int m_width;
	int m_height;
};