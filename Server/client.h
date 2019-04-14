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
	bool sendDataTCP(QByteArray& data);
	Q_SIGNAL void sendData(QByteArray);

public slots:
	void connected();
	void disconnected();
	void readyRead();
	void taskResult(int number);

private:
	QAbstractSocket::SocketState createOutConnection();
	void resetConnection(QTcpSocket* socket);
	QAbstractSocket::SocketState getSocketOutState();
	QTcpSocket* getSocketOut() const;

private:
	QTcpSocket* m_socketOut;
	QTcpSocket* m_socketIn;
};
