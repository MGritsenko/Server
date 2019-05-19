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
	void cropImageAndSend();

private slots:
	void closeConnection();
	void createConnection();
	void closeVideoGrabber();

	void onDataReady(QByteArray data);
	void receiveFrame(QPixmap frame, QByteArray data);

	void sendDataTCP(QByteArray data, QString client);
	
	void setUpClients();
	void tuneClients();
	void findContours(QPixmap frame);

private:
	Ui::MainWindow m_ui;

	std::unique_ptr<ServerThreadPool> m_server;
	std::unique_ptr<ClientsListWidget> m_clientsListWidget;
	std::unique_ptr<VideoGrabber> m_videoGrabberWorker;
	std::unique_ptr<QThread> m_thread;
	std::unique_ptr<QTimer> m_timer;

	SliderTabWidget* m_colorsAdjusterWidget;

	bool m_isDoneSetup;
	bool m_isShapeDetectorTaskFinished;
	bool m_iscropImageAndSendFinished;
	QVector<QVector<QPoint>> m_shapes;

	QVector<QPixmap> m_cropedImages;
	QVector<QByteArray> m_cropedData;
};
