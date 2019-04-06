#include "client.h"
#include "task.h"

Client::Client(QObject *parent)
	: QObject(parent)
{}

Client::~Client()
{}

void Client::setSocket(int descriptor)
{
	m_socket = new QTcpSocket(this);

	connect(m_socket, &QTcpSocket::connected, this, &Client::connected);
	connect(m_socket, &QTcpSocket::disconnected, this, &Client::disconnected);
	connect(m_socket, &QTcpSocket::readyRead, this, &Client::readyRead);

	m_socket->setSocketDescriptor(descriptor);

	qDebug() << "Client connected";
}

void Client::connected()
{
	qDebug() << "Client connected event";
}

void Client::disconnected()
{
	qDebug() << "Client disconnected event";
}

void Client::readyRead()
{
	emit sendData(m_socket->readAll());

	Task* task = new Task();
	task->setAutoDelete(true);

	connect(task, &Task::result, this, &Client::taskResult, Qt::QueuedConnection);

	QThreadPool::globalInstance()->start(task);

}

void Client::taskResult(int number)
{
	QByteArray buffer("Task result: ");
	buffer.append(QString::number(number));
	buffer.append("sssxs\0\n\n");

	m_socket->abort();
	m_socket->connectToHost("192.168.0.28", 64499);
	m_socket->waitForConnected();

	if (m_socket->state() == QAbstractSocket::ConnectedState)
	{
		m_socket->write(buffer);
		m_socket->waitForBytesWritten();
	}
}
