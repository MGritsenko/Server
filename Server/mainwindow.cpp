#include "mainwindow.h"

#include "server.h"
#include "clientslistwidget.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	m_ui.setupUi(this);

	m_ui.statusbar->addPermanentWidget(m_ui.label, 1);
	m_ui.statusbar->addPermanentWidget(m_ui.label_2);

	connect(m_ui.actionStartServer, &QAction::triggered, this, &MainWindow::createConnection);
	connect(m_ui.actionStopServer, &QAction::triggered, this, &MainWindow::closeConnection);
	connect(m_ui.actionClientsList, &QAction::triggered, this, &MainWindow::showClientsList);

	connect(m_ui.actionExit, &QAction::triggered, this, &MainWindow::close);
}

void MainWindow::createConnection()
{
	m_server.reset(new Server());
	m_server->show();
}

void MainWindow::showClientsList()
{
	m_clientsListWidget.reset(new ClientsListWidget());
	m_clientsListWidget->show();
}

void MainWindow::closeConnection()
{
	m_server.reset();
}

MainWindow::~MainWindow()
{
	closeConnection();
}
