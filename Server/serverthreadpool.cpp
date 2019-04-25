#include "serverthreadpool.h"

ServerThreadPool::ServerThreadPool(QObject *parent)
	: QTcpServer(parent)
	, m_outSoc(nullptr)
{
	m_clients = std::make_unique<QMap<QString, QPair<QHostAddress, int>>>();
}

ServerThreadPool::~ServerThreadPool()
{
	delete m_outSoc;
}

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

	if (m_outSoc == nullptr)
	{
		m_outSoc = new QTcpSocket;
	}

	if (m_clients->contains(receiver))
	{
		m_outSoc->connectToHost(m_clients->value(receiver).first, 64499);

		m_outSoc->waitForConnected();
		m_outSoc->write(data);
		m_outSoc->waitForBytesWritten();
		m_outSoc->disconnectFromHost();
	}
}

QMap<QString, QPair<QHostAddress, int>>* ServerThreadPool::getClients() const
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
		auto ip = inSoc->peerAddress();
		auto port = inSoc->peerPort();
		if (!m_clients->contains(ip.toString()))
		{
			m_clients->insert(ip.toString(), qMakePair(ip, port));
		}
		inSoc->disconnectFromHost();

		emit dataReady(ip.toString().toUtf8());
	});
}