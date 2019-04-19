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
	QMap<QString, QPair<QHostAddress, int>>* getClients() const;

signals:
	void dataReady(QByteArray);

public slots:
	void newIncomingConnection();

private:
	std::unique_ptr<QMap<QString, QPair<QHostAddress, int>>> m_clients;

	int m_port;
	QTcpSocket* m_outSoc;
};
 