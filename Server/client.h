#pragma once

#include <QObject>
#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>
#include <QTcpSocket>

class Client : public QObject
{
	Q_OBJECT

public:
	Client(QObject *parent = nullptr);
	~Client();

	void setSocket(int descriptor);

	Q_SIGNAL void sendData(QByteArray);

public slots:
	void connected();
	void disconnected();
	void readyRead();
	void taskResult(int number);

private:
	QTcpSocket* m_socket;
};
