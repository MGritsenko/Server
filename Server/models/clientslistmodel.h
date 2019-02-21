#pragma once

#include <QAbstractTableModel>

class ClientsListModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	ClientsListModel(QObject *parent = nullptr);
	~ClientsListModel();
};
