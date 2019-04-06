#include "server.h"

Server::Server(QWidget *parent)
	: QWidget(parent)
{
	m_ui.setupUi(this);

	m_server = new QTcpServer(this);

	connect(m_server, SIGNAL(newConnection()), this, SLOT(newConnection()));

	if (!m_server->listen(QHostAddress::Any, 1990))
	{
		m_ui.serverStatusLabel->setText("Server could not start");
	}
	else
	{
		m_ui.serverStatusLabel->setText("Server started");
	}
}

void Server::newConnection()
{
	while (m_server->hasPendingConnections())
	{
		QTcpSocket *socket = m_server->nextPendingConnection();

		connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
		connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));

		QByteArray *buffer = new QByteArray();
		qint32 *s = new qint32(0);
		m_buffers.insert(socket, buffer);
		m_sizes.insert(socket, s);
	}
}

void Server::readyRead()
{
	QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
	QByteArray *buffer = m_buffers.value(socket);
	qint32 *s = m_sizes.value(socket);
	qint32 size = *s;
	while (socket->bytesAvailable() > 0)
	{
		buffer->append(socket->readAll());

		//while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) //While can process data, process it
		//{
		//	if (size == 0 && buffer->size() >= 4) //if size of data has received completely, then store it on our global variable
		//	{
		//		size = arrayToString(buffer->mid(0, 4));
		//		*s = size;
		//		buffer->remove(0, 4);
		//	}

		//	if (size > 0 && buffer->size() >= size) // If data has received completely, then emit our SIGNAL with the data
		//	{
		//		QByteArray data = buffer->mid(0, size);
		//		buffer->remove(0, size);
		//		size = 0;
		//		*s = size;
		//		
		//		//emit dataReceived(data);
		//		m_ui.serverStatusLabel->setText(data);
		//	}
		//}
	}	

	m_ui.serverStatusLabel->setText(QString(*buffer));
}

QString Server::arrayToString(QByteArray source)
{
	QString temp;
	QDataStream data(&source, QIODevice::ReadWrite);
	data >> temp;

	return temp;
}

void Server::disconnected()
{
	QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
	QByteArray *buffer = m_buffers.value(socket);
	qint32 *s = m_sizes.value(socket);
	socket->deleteLater();

	delete buffer;
	delete s;
}