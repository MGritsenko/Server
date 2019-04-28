#include "mainwindow.h"

#include "serverthreadpool.h"
#include "clientslistwidget.h"
#include "videograbber.h"
#include "task.h"
#include "findpatterntask.h"
#include "slidertabwidget.h"

#include <QThreadPool>
#include <QBuffer>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, m_isDoneSetup(false)
{
	init();
	initVideoGrabber();
	initClientsList();
	initSetUpBlock();
	initTabWidget();
}

void MainWindow::createConnection()
{
	m_server.reset(new ServerThreadPool());
	m_server->startServer();

	connect(m_server.get(), &ServerThreadPool::dataReady, this, &MainWindow::onDataReady);
}

void MainWindow::closeVideoGrabber()
{
	m_thread->quit();

	while (!m_thread->isFinished()){}

	m_videoGrabberWorker.reset();
}

void MainWindow::onDataReady(QByteArray data)
{
	m_ui.clientsBox->addItem(data);
	m_clientsListWidget->insertData(data);
}

void MainWindow::receiveFrame(QPixmap frame, QByteArray data)
{
	m_ui.frameWindow->setPixmap(frame);

	findPattern(frame);
	//TODO cut image on several pieces and send on to a particular device 

	//if (m_isDoneSetup)
	{
		for(auto i = 0; i < m_ui.clientsBox->count(); i++)
		{
			sendDataTCP(data, m_ui.clientsBox->itemText(i));
		}
	}
}

void MainWindow::sendDataTCP(QByteArray data, QString client)
{
	if (!m_server)
	{
		return;
	}

	if (!m_server->isListening())
	{
		return;
	}

	m_server->sendDataTCP(data, client);
}

void MainWindow::setUpClient()
{
	auto receiverIp = m_ui.clientsBox->currentText();
	auto command = m_ui.commandsBox->currentText();

	Task* task = new Task(1080, 1920);
	task->setAutoDelete(true);
	connect(task, &Task::result, this, [&, receiverIp](QByteArray data)
	{
		sendDataTCP(data, receiverIp);
	}
	, Qt::QueuedConnection);

	QThreadPool::globalInstance()->start(task);
}

void MainWindow::findPattern(QPixmap img)
{
	QColor fromR = QColor(m_redTabWidget->getFromColor());
	QColor toR = QColor(m_redTabWidget->getToColor());
	QColor fromG = QColor(m_greenTabWidget->getFromColor());
	QColor toG = QColor(m_greenTabWidget->getToColor());
	
	FindPatternTask* task = new FindPatternTask
	(
		img
		, cv::Scalar(fromR.red(), fromR.green(), fromR.blue())
		, cv::Scalar(toR.red(), toR.green(), toR.blue())
		, cv::Scalar(fromG.red(), fromG.green(), fromG.blue())
		, cv::Scalar(toG.red(), toG.green(), toG.blue())
	);

	task->setAutoDelete(true);
	connect(task, &FindPatternTask::result, this, [&](QPixmap red, QPixmap green)
	{
		QPixmap scaledR = red.scaled(m_ui.redWindow->width(), m_ui.redWindow->height(), Qt::KeepAspectRatio, Qt::FastTransformation);
		m_ui.redWindow->setPixmap(scaledR);
		QPixmap scaledG = green.scaled(m_ui.greenWindow->width(), m_ui.greenWindow->height(), Qt::KeepAspectRatio, Qt::FastTransformation);
		m_ui.greenWindow->setPixmap(scaledG);
	}
	, Qt::QueuedConnection);

	QThreadPool::globalInstance()->start(task);
}

void MainWindow::closeConnection()
{
	m_server.reset();
}

MainWindow::~MainWindow()
{
	closeConnection();
	closeVideoGrabber();
}

void MainWindow::init()
{
	m_ui.setupUi(this);

	m_ui.statusbar->addPermanentWidget(m_ui.label, 1);
	m_ui.statusbar->addPermanentWidget(m_ui.label_2);

	connect(m_ui.actionStartServer, &QAction::triggered, this, &MainWindow::createConnection);
	connect(m_ui.actionStopServer, &QAction::triggered, this, &MainWindow::closeConnection);

	connect(m_ui.actionExit, &QAction::triggered, this, &MainWindow::close);
}

void MainWindow::initVideoGrabber()
{
	m_videoGrabberWorker.reset(new VideoGrabber());
	m_thread.reset(new QThread);
	m_timer.reset(new QTimer);

	m_timer->setInterval(1000/30);
	m_videoGrabberWorker->moveToThread(m_thread.get());
	m_timer->start();
	m_timer->moveToThread(m_thread.get());

	connect(m_thread.get(), &QThread::finished, m_videoGrabberWorker.get(), &VideoGrabber::deleteLater);
	connect(m_thread.get(), &QThread::finished, m_timer.get(), &QTimer::deleteLater);

	connect(m_timer.get(), &QTimer::timeout, m_videoGrabberWorker.get(), &VideoGrabber::grabFrame);
	connect(m_videoGrabberWorker.get(), &VideoGrabber::sendFrame, this, &MainWindow::receiveFrame, Qt::QueuedConnection);
	
	m_thread->start();
}

void MainWindow::initClientsList()
{
	m_clientsListWidget.reset(new ClientsListWidget());
	m_ui.clientsListLayout->addWidget(m_clientsListWidget.get());
}

void MainWindow::initSetUpBlock()
{
	m_ui.commandsBox->addItem(QString::number(static_cast<int>(CommandType::SEND_IDENT_IMG)));
	connect(m_ui.sendButton, &QPushButton::clicked, this, &MainWindow::setUpClient);
}

void MainWindow::initTabWidget()
{
	m_redTabWidget = new SliderTabWidget(this, QVector<int>{208, 0, 0, 255, 170, 210});
	m_greenTabWidget = new SliderTabWidget(this, QVector<int>{0, 201, 17, 141, 255, 170});

	m_ui.tabWidget->addTab(m_redTabWidget, "Red");
	m_ui.tabWidget->addTab(m_greenTabWidget, "Green");
}
