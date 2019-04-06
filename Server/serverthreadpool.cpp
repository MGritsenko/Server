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

void ServerThreadPool::incomingConnection(qintptr handle)
{
	Client* client = new Client(this);
	connect(client, &Client::sendData, this, &ServerThreadPool::dataReady);
	client->setSocket(handle);
}