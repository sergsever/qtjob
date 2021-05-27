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
	int rows = static_cast<int>(corpList.size());
	return rows;
}

int CorpTableModel::columnCount(const QModelIndex &parent) const
{
	return COLUMNS;
}

QVariant CorpTableModel::data(const QModelIndex& index, int role ) const
{
	QString ret = "empty";
	switch(index.column())
	{

		case 0:
			ret = std::to_string(corpList.at(index.row()).corp_id).c_str();

		break;
		case 1:
			ret = corpList.at(index.row()).title;
		break;
		case 2:
			ret = corpList.at(index.row()).added.toString("dd.MM.yyyy");
		break;
		case 3:
			ret = corpList.at(index.row()).result;
		break;
		case 4:
			ret = corpList.at(index.row()).keywords;
		break;


	}
	qDebug() << "curr role:" << role;
	if (role != Qt::CheckStateRole)
	{
	return ret;
	}
	else
	{
		qDebug() << "data:role:" << role;
		return QVariant();
	}
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
	Qt::ItemFlags flags = Qt::ItemFlag::NoItemFlags;
//	flags &= Qt::ItemIsUserCheckable;
//	flags &= Qt::ItemIsSelectable;
//	flags &= Qt::ItemIsEnabled;

	return flags;
}
