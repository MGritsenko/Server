#include "serverthreadpool.h"

ServerThreadPool::ServerThreadPool(QObject *parent)
	: QTcpServer(parent)
{
	m_clients = std::make_unique<QMap<QString, QHostAddress>>();
}

ServerThreadPool::~ServerThreadPool()
{}

void ServerThreadPool::startServer(int port)
{
	m_port = port;
	if (!listen(QHostAddress::Any, m_port))
	{
		close();
		return;
	}

	connect(this, &QTcpServer::newConnection, this, &ServerThreadPool::newIncomingConnection);
}

void ServerThreadPool::sendDataTCP(QByteArray& data, QString& receiver)
{
	if (!m_clients || m_clients->isEmpty())
	{
		return;
	}

	QTcpSocket *outSoc = new QTcpSocket;
	outSoc->connectToHost(m_clients->begin().value(), m_port);
	outSoc->waitForConnected();
	outSoc->write(data);
	outSoc->waitForBytesWritten();
	outSoc->disconnectFromHost();

	delete outSoc;
}

QMap<QString, QHostAddress>* ServerThreadPool::getClients() const
{
	return m_clients.get();
}

void ServerThreadPool::newIncomingConnection()
{
	QTcpSocket *inSoc = nextPendingConnection();

	connect(inSoc, &QAbstractSocket::disconnected, inSoc, &QObject::deleteLater);
	connect(inSoc, &QAbstractSocket::readyRead, this, [&, inSoc]()
	{
		auto data = inSoc->readAll();
		m_clients->insert(QString(data), inSoc->peerAddress());
		inSoc->disconnectFromHost();

		emit dataReady(data);
	});
}