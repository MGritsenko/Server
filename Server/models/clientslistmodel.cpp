#include "clientslistmodel.h"

ClientsListModel::ClientsListModel(QObject *parent)
	: QAbstractTableModel(parent)
{}

ClientsListModel::~ClientsListModel()
{}

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

bool ClientsListModel::removeRows(int row, int count, const QModelIndex &parent /* = QModelIndex() */)
{
	beginRemoveRows(parent, row, count - 1);
	m_data.clear();
	endRemoveRows();

	return true;
}

bool ClientsListModel::insertData(QString data)
{
	if (!m_data.contains(qMakePair(data, data)))
	{
		beginInsertRows({}, m_data.size(), m_data.size());
		m_data.append(qMakePair(data, data));
		endInsertRows();

		return true;
	}

	return false;
}
