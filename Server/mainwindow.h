#pragma once

#include <QMainWindow>
#include "ui_mainwindow.h"

#include "server.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void closeConnection();
	void createConnection();

private:
	Ui::MainWindow m_ui;

	std::unique_ptr<Server> m_server;
};
