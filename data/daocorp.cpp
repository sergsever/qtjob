#include "precompiled.h"
#include "daocorp.h"
#include "QxDao/QxDao.h"
DaoCorp::DaoCorp()
{
	qx::QxSqlDatabase::getSingleton()->setDriverName("QODBC");
	qx::QxSqlDatabase::getSingleton()->setDatabaseName("mssql");
	QSqlError err = qx::dao::create_table<Corp>();
}



std::vector<Corp> DaoCorp::getAll()
{
	QList<std::shared_ptr<Corp>> all;
	QSqlError err = qx::dao::fetch_all(all);
	std::vector<Corp> ret;
	for(int i = 0; i < all.count(); i++)
	{
		Corp& c = *all.at(i);
		ret.push_back(c);
	}
	return ret;
}

void DaoCorp::add(Corp &entity)
{
	qx::dao::insert(entity);
}

std::vector<Corp> DaoCorp::findByTitle(QString title)
{
	qx::QxSqlQuery qxquery("WHERE corp.title = :title");
	qxquery.bind(":title", title);
	qx::QxCollection<QString, std::shared_ptr<Corp>> res;
	qx::dao::fetch_by_query(qxquery, res);

	std::vector<Corp> ret;
	for(int i = 0; i < res.count(); i++)
	{
		Corp v = *res.getByIndex(i);
		ret.push_back(v);
	}

	return ret;
}
