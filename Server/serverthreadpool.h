#pragma once

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMap>

class Client;

class ServerThreadPool : public QTcpServer
{
	Q_OBJECT

public:
	ServerThreadPool(QObject *parent = nullptr);
	~ServerThreadPool();

	void startServer();
	void sendDataTCP(QByteArray& data, QString& receiver);

	Q_SIGNAL void dataReady(QByteArray);

protected:
	virtual void incomingConnection(qintptr handle) override;

private:
	QMap<QString, Client*> m_clients;
};
 