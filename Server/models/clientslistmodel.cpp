#include "clientslistmodel.h"

ClientsListModel::ClientsListModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	m_data.append(qMakePair(QString("one"), QString("two")));
	m_data.append(qMakePair(QString("three"), QString("four")));
	m_data.append(qMakePair(QString("five"), QString("six")));
	m_data.append(qMakePair(QString("seven"), QString("eight")));
	m_data.append(qMakePair(QString("nine"), QString("ten")));
}

ClientsListModel::~ClientsListModel()
{
}

int ClientsListModel::rowCount(const QModelIndex &parent) const
{
	return m_data.size();
}

int ClientsListModel::columnCount(const QModelIndex &parent) const
{
	return 2;
}

QVariant ClientsListModel::data(const QModelIndex& index, int role) const
{
	switch (role)
	{
	case Qt::DisplayRole:
		return m_data.at(index.row()).first;
	default:
		break;
	}

	return QVariant();
}
