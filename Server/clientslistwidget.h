#pragma once

#include <QWidget>
namespace Ui { class ClientsListWidget; };

class ClientsListModel;

class ClientsListWidget : public QWidget
{
	Q_OBJECT

public:
	ClientsListWidget(QWidget *parent = Q_NULLPTR);
	~ClientsListWidget();

	bool insertData(QString data);
	void removeClients();
	QString data(int index);

	int clients() const;

private:
	Ui::ClientsListWidget *ui;

	ClientsListModel* m_model;
};
