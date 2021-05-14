#ifndef CORP_H
#define CORP_H
#include "precompiled.h"
class Corp
{
public:
	long corp_id;
	QString title;
	QDateTime added;
	QString result;
	QString keywords;
	Corp() : corp_id(0) {;};
	virtual ~Corp() {;}

};

QX_REGISTER_HPP_MY_TEST_EXE(Corp, qx::trait::no_base_class_defined, 1)

#endif // CORP_H
