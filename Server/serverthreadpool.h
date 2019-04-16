#pragma once

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMap>
#include <QPair>

class ServerThreadPool : public QTcpServer
{
	Q_OBJECT

public:
	ServerThreadPool(QObject *parent = nullptr);
	~ServerThreadPool();

	void startServer(int port = 64499);
	void sendDataTCP(QByteArray& data, QString& receiver);
	QMap<QString, QHostAddress>* getClients() const;

signals:
	void dataReady(QByteArray);

public slots:
	void newIncomingConnection();

private:
	std::unique_ptr<QMap<QString, QHostAddress>> m_clients;

	int m_port;
};
 