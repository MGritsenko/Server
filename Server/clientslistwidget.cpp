#include "clientslistwidget.h"
#include "ui_clientslistwidget.h"

#include "models\clientslistmodel.h"

ClientsListWidget::ClientsListWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::ClientsListWidget();
	ui->setupUi(this);

	m_model =  new ClientsListModel(this);
	ui->tableView->setModel(m_model);
}

ClientsListWidget::~ClientsListWidget()
{
	delete ui;
}
