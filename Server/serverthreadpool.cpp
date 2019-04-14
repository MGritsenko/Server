#include "serverthreadpool.h"
#include "client.h"

ServerThreadPool::ServerThreadPool(QObject *parent)
	: QTcpServer(parent)
{}

ServerThreadPool::~ServerThreadPool()
{}

void ServerThreadPool::startServer()
{
	if (listen(QHostAddress::Any, 64499))
	{
		qDebug() << "Server started";
	}
	else
	{
		qDebug() << "Not started";
	}
}

void ServerThreadPool::sendDataTCP(QByteArray& data, QString& receiver)
{
	if (m_clients.contains(receiver))
	{
		m_clients.value(receiver)->sendDataTCP(data);
	}
}

void ServerThreadPool::incomingConnection(qintptr handle)
{
	const QString key = "name";

	//if (!m_clients.contains(key))
	{
		Client* client = new Client(this);
		m_clients[key] = client;

		connect(client, &Client::sendData, this, &ServerThreadPool::dataReady);

		client->setSocket(handle);
	}
}