#ifndef CORP_H
#define CORP_H
//#include "precompiled.h"
class Corp
{
public:
	unsigned int corp_id;
	QString title;
	QDateTime added;
	QString result;
	QString keywords;
	Corp();
	Corp(const QSqlQuery& query);
	virtual ~Corp();
};

//QX_REGISTER_PRIMARY_KEY(corp, long)

//QX_REGISTER_HPP(corp, qx::trait::no_base_class_defined, 0)

#endif // CORP_H
