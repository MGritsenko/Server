#pragma once

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>

class ServerThreadPool : public QTcpServer
{
	Q_OBJECT

public:
	ServerThreadPool(QObject *parent = nullptr);
	~ServerThreadPool();

	void startServer();

	Q_SIGNAL void dataReady(QByteArray);

protected:
	virtual void incomingConnection(qintptr handle) override;
};
