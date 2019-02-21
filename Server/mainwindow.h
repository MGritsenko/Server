#pragma once

#include <QMainWindow>
#include "ui_mainwindow.h"

class Server;
class ClientsListWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void closeConnection();
	void createConnection();
	void showClientsList();

private:
	Ui::MainWindow m_ui;

	std::unique_ptr<Server> m_server;
	std::unique_ptr<ClientsListWidget> m_clientsListWidget;
};
