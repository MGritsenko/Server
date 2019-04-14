#include "client.h"
#include "task.h"

Client::Client(QObject *parent)
	: QObject(parent)
	, m_socketOut(nullptr)
	, m_socketIn(nullptr)
{}

Client::~Client()
{
	resetConnection(m_socketOut);
	resetConnection(m_socketIn);
}

void Client::setSocket(int descriptor)
{
	m_socketIn = new QTcpSocket(this);

	connect(m_socketIn, &QTcpSocket::connected, this, &Client::connected);
	connect(m_socketIn, &QTcpSocket::disconnected, this, &Client::disconnected);
	connect(m_socketIn, &QTcpSocket::readyRead, this, &Client::readyRead);

	m_socketIn->setSocketDescriptor(descriptor);

	qDebug() << "Client connected";
}

bool Client::sendDataTCP(QByteArray& data)
{
	if (getSocketOutState() != QAbstractSocket::ConnectedState)
	{
		if (createOutConnection() != QAbstractSocket::ConnectedState)
		{
			qDebug() << "CANNOT CREATE CONNECTION";
			return false;
		}
	}

	if (getSocketOutState() == QAbstractSocket::ConnectedState)
	{
		const auto sockOut = getSocketOut();
		sockOut->write(data);
		if (sockOut->waitForBytesWritten())
		{
			sockOut->flush();
			sockOut->close();

			qDebug() << "Write Ok";
		}
		else
		{
			qDebug() << "Write Error";
			return false;
		}
	}

	return true;
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
	emit sendData(m_socketIn->readAll());

	Task* task = new Task();
	task->setAutoDelete(true);

	connect(task, &Task::result, this, &Client::taskResult, Qt::QueuedConnection);

	QThreadPool::globalInstance()->start(task);

}

void Client::taskResult(int number)
{
	QByteArray buffer("Task result: \0");
	buffer.append(QString::number(number));
	buffer.append("\0");
	
	sendDataTCP(buffer);
}

QAbstractSocket::SocketState Client::createOutConnection()
{
	resetConnection(m_socketOut);

	m_socketOut = new QTcpSocket;
	m_socketOut->connectToHost("192.168.0.28", 64499);
	m_socketOut->waitForConnected();

	return getSocketOutState();
}

void Client::resetConnection(QTcpSocket* socket)
{
	if (!socket)
	{
		return;
	}

	socket->flush();
	socket->close();

	delete socket;

	socket = nullptr;
}

QAbstractSocket::SocketState Client::getSocketOutState()
{
	return m_socketOut ? m_socketOut->state() : QAbstractSocket::UnconnectedState;
}

QTcpSocket* Client::getSocketOut() const
{
	return m_socketOut;
}
