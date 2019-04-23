#pragma once

#include <QMainWindow>
#include <QThread>
#include <QTimer>

#include "ui_mainwindow.h"

class ServerThreadPool;
class ClientsListWidget;
class VideoGrabber;
class SliderTabWidget;

enum class CommandType
{
	SEND_IDENT_IMG
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
	void init();
	void initVideoGrabber();
	void initClientsList();
	void initSetUpBlock();
	void initTabWidget();

private slots:
	void closeConnection();
	void createConnection();
	void closeVideoGrabber();

	void onDataReady(QByteArray data);
	void receiveFrame(QPixmap frame, QByteArray data);

	void sendDataTCP(QByteArray data, QString client);
	
	void setUpClient();

	void findPattern(QPixmap img);

private:
	Ui::MainWindow m_ui;

	std::unique_ptr<ServerThreadPool> m_server;
	std::unique_ptr<ClientsListWidget> m_clientsListWidget;
	std::unique_ptr<VideoGrabber> m_videoGrabberWorker;
	std::unique_ptr<QThread> m_thread;
	std::unique_ptr<QTimer> m_timer;

	SliderTabWidget* m_redTabWidget;
	SliderTabWidget* m_greenTabWidget;

	bool m_isDoneSetup;
};
