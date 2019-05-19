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
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, m_isDoneSetup(false)
	, m_isShapeDetectorTaskFinished(true)
	, m_iscropImageAndSendFinished(true)
{
	init();
	initVideoGrabberCamera();
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

void MainWindow::closeVideoGrabberCamera()
{
	m_threadCamera->quit();

	while (!m_threadCamera->isFinished()){}

	m_videoGrabberCameraWorker.reset();
}

void MainWindow::closeVideoGrabberFile()
{
	m_threadFile->quit();

	while (!m_threadFile->isFinished()) {}

	m_videoGrabberFileWorker.reset();
}

void MainWindow::openFileDialog()
{
	 m_fileName = QFileDialog::getOpenFileName
	 (
		this
		, "Open File"
		, "C:/Users/<USER>/Documents"
		, "Video files (*.avi)"
	);
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
	closeVideoGrabberCamera();
}

void MainWindow::init()
{
	m_ui.setupUi(this);

	m_ui.statusbar->addPermanentWidget(m_ui.label, 1);
	m_ui.statusbar->addPermanentWidget(m_ui.label_2);

	connect(m_ui.actionStartServer, &QAction::triggered, this, &MainWindow::createConnection);
	connect(m_ui.actionStopServer, &QAction::triggered, this, &MainWindow::closeConnection);

	connect(m_ui.actionExit, &QAction::triggered, this, &MainWindow::close);
	connect(m_ui.actionOpenFile, &QAction::triggered, this, &MainWindow::openFileDialog);
}

void MainWindow::initVideoGrabberCamera()
{
	m_videoGrabberCameraWorker.reset(new VideoGrabber(nullptr, 0));
	m_threadCamera.reset(new QThread);
	m_timerCamera.reset(new QTimer);

	m_timerCamera->setInterval(1000/30);
	m_videoGrabberCameraWorker->moveToThread(m_threadCamera.get());
	m_timerCamera->start();
	m_timerCamera->moveToThread(m_threadCamera.get());

	connect(m_threadCamera.get(), &QThread::finished, m_videoGrabberCameraWorker.get(), &VideoGrabber::deleteLater);
	connect(m_threadCamera.get(), &QThread::finished, m_timerCamera.get(), &QTimer::deleteLater);

	connect(m_timerCamera.get(), &QTimer::timeout, m_videoGrabberCameraWorker.get(), &VideoGrabber::grabFrameFromCamera);
	connect(m_videoGrabberCameraWorker.get(), &VideoGrabber::sendFrame, this, &MainWindow::receiveFrame, Qt::QueuedConnection);
	
	m_threadCamera->start();
}

void MainWindow::initVideoGrabberFile()
{
	if (m_fileName.isEmpty())
	{
		QMessageBox::information(this, "Message", "No file has been selected!!");

		return;
	}

	m_timerCamera->stop();

	m_videoGrabberFileWorker.reset(new VideoGrabber(m_fileName));
	m_threadFile.reset(new QThread);
	m_timerFile.reset(new QTimer);

	m_timerFile->setInterval(1000 / 30);
	m_videoGrabberFileWorker->moveToThread(m_threadFile.get());
	m_timerFile->start();
	m_timerFile->moveToThread(m_threadFile.get());

	connect(m_threadFile.get(), &QThread::finished, m_videoGrabberFileWorker.get(), &VideoGrabber::deleteLater);
	connect(m_threadFile.get(), &QThread::finished, m_timerFile.get(), &QTimer::deleteLater);

	connect(m_timerFile.get(), &QTimer::timeout, m_videoGrabberFileWorker.get(), &VideoGrabber::grabFrameFromFile);
	connect(m_videoGrabberFileWorker.get(), &VideoGrabber::sendFrame, this, &MainWindow::receiveFrame, Qt::QueuedConnection);

	m_threadFile->start();
}

void MainWindow::initClientsList()
{
	m_clientsListWidget.reset(new ClientsListWidget());
	m_ui.clientsListLayout->addWidget(m_clientsListWidget.get());
}

void MainWindow::initSetUpBlock()
{
	m_ui.commandsBox->addItem(QString::number(static_cast<int>(CommandType::SEND_IDENT_IMG)));
	connect(m_ui.sendColorButton, &QPushButton::clicked, this, &MainWindow::setUpClients);
	connect(m_ui.sendVideoButton, &QPushButton::clicked, this, &MainWindow::initVideoGrabberFile);
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
