#ifndef CORPTABLEMODEL_H
#define CORPTABLEMODEL_H
#include "precompiled.h"

class CorpTableModel: public QAbstractTableModel
{
public:
	CorpTableModel(QObject* parent = nullptr);
	void add(Corp& corp);
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	virtual QVariant data(const QModelIndex& index, int role = Qt::DecorationRole) const override;
	QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex() ) const override;
	QModelIndex parent(const QModelIndex& index) const override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
protected:
	std::map<int, Corp> corpList;
	const unsigned int COLUMNS = 4;
};

#endif // CORPTABLEMODEL_H
