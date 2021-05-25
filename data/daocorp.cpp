#include "precompiled.h"
#include "daocorp.h"
#include "QxDao/QxDao.h"
#include <QHostInfo>

DaoCorp::DaoCorp()
{
/*
	QString connectString = "Driver={SQL Server Native Client 11.0};";                     // Driver is now {SQL Server Native Client 11.0}
	QString lpc = "Server=";
	lpc.append(QHostInfo::localHostName() +"\\SQLEXPRESS;");

	connectString.append("Server=lpc:"+ lpc);   // Hostname,SQL-Server Instance
	connectString.append("Database=fjob;");  // Schema
	connectString.append("Uid=sa;");           // User
	connectString.append("Pwd=ssl-2000;");           // Pass
*/
//	qx::QxSqlDatabase::getSingleton()->setDatabaseName(connectString);
	//qx::QxSqlDatabase::getSingleton()->setUserName("sa");
	//qx::QxSqlDatabase::getSingleton()->setPassword("ssl-2000");
db = QSqlDatabase::addDatabase("QODBC");
QString ipserver = "127.0.0.1";
QString dbname = "fjob";
QString user = "sa";
QString pswd = "ssl-2000";

db.setDatabaseName("DRIVER={SQL Server};Server=" + ipserver+ ";Database="+ dbname +";Uid="+ user +";Port=1433;Pwd=" + pswd +";WSID=");
db.setUserName(user);
db.setPassword(pswd);
if (db.open())
{
	qDebug("db is open\n");
}
else
{
	QSqlError err = db.lastError();
	qDebug("db err:");
	qDebug(err.text().toStdString().c_str());
}
}



std::vector<Corp> DaoCorp::getAll()
{
	/*
	QList<std::shared_ptr<corp>> all;
	QSqlError err = qx::dao::fetch_all(all);
	std::vector<corp> ret;
	for(int i = 0; i < all.count(); i++)
	{
		corp& c = *all.at(i);
		ret.push_back(c);
	}
*/
std::vector<Corp> ret;
QSqlQuery query(db);
		query.prepare("select * from dbo.corp");
		query.exec();
while(query.next())
{
	Corp c(query);
	ret.push_back(c);

}
	sql_err = db.lastError();
	return ret;
}

void DaoCorp::add(Corp &entity)
{
	QSqlQuery query(db);
	bool res = false;
	qDebug() << "is preparing title: " << entity.title << " added: " << entity.added;
		res =	query.prepare("INSERT INTO corp (title, added, result, keywords) VALUES(:title, :added, :result, :keywords)");
		qDebug() << "prepare: " << res;
	query.bindValue(":title", entity.title);
	query.bindValue(":added", entity.added);
	query.bindValue(":result", entity.result);
	query.bindValue(":keywords", entity.keywords);
	qDebug() << "exec insert:";
	query.exec();

}

std::vector<Corp> DaoCorp::findByTitle(QString title)
{
/*
	qx::QxSqlQuery query("WHERE corp.title = :title");
	query.bind(":title", title, QSql::In);
//	qxquery.where("title").isEqualTo(title);
	qx::QxSqlQuery raw("SELECT * FROM corp");

	qx::QxCollection<QString, std::shared_ptr<corp>> res;
//	QSqlError err = qx::dao::fetch_all(res);
	QSqlError err = qx::dao::fetch_by_query(raw, res);
	sql_err = err;

	std::vector<corp> ret;
	if (res.count() > 0)
	{
	for(int i = 0; i < res.count(); i++)
	{
		corp v = *res.getByIndex(i);
		if (v.title == title)
			ret.push_back(v);
	}
	}
	*/
	std::vector<Corp> ret;
	QSqlQuery query(db);
			query.prepare("SELECT corp_id, title, added, result, keywords from corp WHERE title=:title");
	query.bindValue(":title", title);
	qDebug() << "exec select:";
	query.exec();
	sql_err = query.lastError();
	qDebug() << "error: " << sql_err.text() << "count:" << query.size();
	while(query.next())
	{
		Corp c(query);
		ret.push_back(c);

	}
	qDebug() << "ret size:" << ret.size();
	return ret;
}

QSqlError DaoCorp::getSqlError()
{
	return sql_err;
}
