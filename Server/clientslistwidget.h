#pragma once

#include <QWidget>
namespace Ui { class ClientsListWidget; };

class ClientsListWidget : public QWidget
{
	Q_OBJECT

public:
	ClientsListWidget(QWidget *parent = Q_NULLPTR);
	~ClientsListWidget();

private:
	Ui::ClientsListWidget *ui;
};
