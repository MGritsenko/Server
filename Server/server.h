#pragma once

#include <QWidget>
#include "ui_server.h"

#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QWidget
{
	Q_OBJECT

public:
	Server(QWidget *parent = Q_NULLPTR);

private:
	QString arrayToString(QByteArray source);

signals:
	void dataReceived(QByteArray);

private slots:
	void newConnection();
	void readyRead();
	void disconnected();

private:
	Ui::Server m_ui;
	
	QTcpServer* m_server;

	QHash<QTcpSocket*, QByteArray*> m_buffers;
	QHash<QTcpSocket*, qint32*> m_sizes;
};
