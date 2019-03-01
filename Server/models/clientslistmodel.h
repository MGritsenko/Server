#pragma once

#include <QAbstractTableModel>

class ClientsListModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	ClientsListModel(QObject *parent = nullptr);
	~ClientsListModel();

	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
	QList<QPair<QString, QString>> m_data;
};
