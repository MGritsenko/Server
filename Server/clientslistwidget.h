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

private:
	Ui::ClientsListWidget *ui;

	ClientsListModel* m_model;
};
