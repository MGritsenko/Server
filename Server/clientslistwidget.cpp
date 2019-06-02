#include "clientslistwidget.h"
#include "ui_clientslistwidget.h"

#include "models\clientslistmodel.h"

ClientsListWidget::ClientsListWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::ClientsListWidget();
	ui->setupUi(this);

	m_model = new ClientsListModel(this);
	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->tableView->setModel(m_model);
}

ClientsListWidget::~ClientsListWidget()
{
	delete ui;
}

bool ClientsListWidget::insertData(QString data)
{
	return m_model->insertData(data);
}

void ClientsListWidget::removeClients()
{
	if (clients())
	{
		m_model->removeRows(0, clients(), QModelIndex());
	}
}

QString ClientsListWidget::data(int index)
{
	return m_model->data(m_model->index(index, 0)).toString();
}

int ClientsListWidget::clients() const
{
	return m_model->rowCount();
}
