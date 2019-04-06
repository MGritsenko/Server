#pragma once

#include <QRunnable>
#include <QObject>

class Task : public QObject,  public QRunnable
{
	Q_OBJECT

public:
	Task();
	~Task();

signals:
	void result(int number);

protected:
	virtual void run() override;
};