#include "corptablemodel.h"

CorpTableModel::CorpTableModel(QObject* parent): QAbstractTableModel(parent)
{
	std::map<int, Corp> amap;
	corpList = amap;
}

void CorpTableModel::add(Corp& corp)
{
	int newKey = 0;
	auto last = corpList.end();
	if (corpList.begin() != last)
	{
		--last;
		newKey = last->first;
		newKey++;
	}


	corpList[newKey] = corp;
}

int CorpTableModel::rowCount(const QModelIndex &parent) const
{
	return corpList.size();
}

int CorpTableModel::columnCount(const QModelIndex &parent) const
{
	return COLUMNS;
}

QVariant CorpTableModel::data(const QModelIndex& index, int role ) const
{
	switch(index.column())
	{

		case 0:
			return QString(std::to_string(corpList.at(index.row()).corp_id).c_str());

		break;
		case 1:
			return corpList.at(index.row()).title;
		break;
		case 2:
			return corpList.at(index.row()).added.toString("dd.MM.yyyy");
		break;
		case 3:
			return corpList.at(index.row()).result;
		break;
		case 4:
			return corpList.at(index.row()).keywords;
		break;


	}
	return "";
}

QModelIndex CorpTableModel::index(int row, int column, const QModelIndex &parent) const
{
	QModelIndex newIndex = QAbstractItemModel::createIndex(row, column);
return newIndex;
}

QModelIndex CorpTableModel::parent(const QModelIndex &index) const
{
	return QModelIndex();
}

Qt::ItemFlags CorpTableModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags flags;
	flags &= Qt::ItemIsUserCheckable;
	flags &= Qt::ItemIsSelectable;
	return flags;
}
