#include "mainwindow.h"

#include "serverthreadpool.h"
#include "clientslistwidget.h"
#include "videograbber.h"
#include "task.h"
#include "findpatterntask.h"
#include "slidertabwidget.h"
#include "shapedetectortask.h"
#include "cropimagetask.h"

#include <QThreadPool>
#include <QBuffer>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, m_isDoneSetup(false)
	, m_isShapeDetectorTaskFinished(true)
	, m_iscropImageAndSendFinished(true)
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
	if (m_clientsListWidget->insertData(data))
	{
		m_ui.clientsBox->addItem(data);
	}
}

void MainWindow::receiveFrame(QPixmap frame, QByteArray data)
{
	m_ui.frameWindow->setPixmap(frame);

	if (m_isDoneSetup || m_ui.doneSetup->isChecked())
	{
		cropImageAndSend();
	}
	else
	{
		findContours(frame);
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

void MainWindow::setUpClients()
{
	const auto command = m_ui.commandsBox->currentText();

	for (int i = 0; i < m_clientsListWidget->clients(); i++)
	{
		const auto receiverIp = m_ui.clientsBox->itemText(i);

		SendColorsTask* task = new SendColorsTask(1080, 1920, 1);
		task->setAutoDelete(true);
		connect(task, &SendColorsTask::result, this, [&, receiverIp](QByteArray data)
		{
			sendDataTCP(data, receiverIp);
		}
		, Qt::QueuedConnection);
		QThreadPool::globalInstance()->start(task);
	}
}

void MainWindow::tuneClients()
{
	if (m_shapes.isEmpty())
	{
		return;
	}

	CropImageTask* task = new CropImageTask(m_shapes, *m_ui.frameWindow->pixmap());
	task->setAutoDelete(true);
	connect(task, &CropImageTask::result, this, [&](QVector<QPixmap> images, QVector<QByteArray> data)
	{
		m_cropedImages = images;
		m_cropedData = data;

	}
	, Qt::QueuedConnection);

	QThreadPool::globalInstance()->start(task);
}

void MainWindow::findContours(QPixmap frame)
{
	if (m_isShapeDetectorTaskFinished)
	{
		m_isShapeDetectorTaskFinished = false;

		QColor from = QColor(m_colorsAdjusterWidget->getFromColor());
		QColor to = QColor(m_colorsAdjusterWidget->getToColor());

		auto* task = new ShapeDetectorTask
		(
			frame
			, cv::Scalar(from.red(), from.green(), from.blue())
			, cv::Scalar(to.red(), to.green(), to.blue())
			, 2//m_clientsListWidget->clients()
		);
		task->setAutoDelete(true);
		connect(task, &ShapeDetectorTask::result, this, [&](QPixmap data, QVector<QVector<QPoint>> shapes)
		{
			m_isShapeDetectorTaskFinished = true;
			
			m_shapes = shapes;

			QPixmap scaledG = data.scaled(m_ui.alphaWindow->width(), m_ui.alphaWindow->height(), Qt::KeepAspectRatio, Qt::FastTransformation);
			m_ui.alphaWindow->setPixmap(scaledG);
		}
		, Qt::QueuedConnection);
		QThreadPool::globalInstance()->start(task);
	}
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
	connect(m_ui.sendButton, &QPushButton::clicked, this, &MainWindow::setUpClients);
	connect(m_ui.tuneButton, &QPushButton::clicked, this, &MainWindow::tuneClients);
}

void MainWindow::initTabWidget()
{
	m_colorsAdjusterWidget = new SliderTabWidget(this, QVector<int>{0, 146, 0, 255, 255, 159});
	m_ui.tabWidget->addTab(m_colorsAdjusterWidget, "Green");
}

void MainWindow::cropImageAndSend()
{
	if (m_iscropImageAndSendFinished)
	{
		m_iscropImageAndSendFinished = false;

		CropImageTask* task = new CropImageTask(m_shapes, *m_ui.frameWindow->pixmap());
		task->setAutoDelete(true);
		connect(task, &CropImageTask::result, this, [&](QVector<QPixmap> images, QVector<QByteArray> data)
		{
			m_cropedImages = images;
			m_cropedData = data;

			for (auto i = 0; i < m_ui.clientsBox->count(); i++)
			{
				sendDataTCP(m_cropedData[i], m_ui.clientsBox->itemText(i));
			}

			m_iscropImageAndSendFinished = true;

			QPixmap scaledG = m_cropedImages[0].scaled(m_ui.alphaWindow->width(), m_ui.alphaWindow->height(), Qt::KeepAspectRatio, Qt::FastTransformation);
			m_ui.alphaWindow->setPixmap(scaledG);
		}
		, Qt::QueuedConnection);
		QThreadPool::globalInstance()->start(task);
	}
}
