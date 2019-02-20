#include "clientslistwidget.h"
#include "ui_clientslistwidget.h"

ClientsListWidget::ClientsListWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::ClientsListWidget();
	ui->setupUi(this);
}

ClientsListWidget::~ClientsListWidget()
{
	delete ui;
}
