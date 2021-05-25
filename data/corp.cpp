#include "precompiled.h"
#include "corp.h"
#include "QxOrm.h"
#include "QxOrm_Impl.h"

Corp::Corp()
{
	corp_id = 0;
}

Corp::Corp(const QSqlQuery& query)
{
	corp_id = query.value("corp_id").toUInt();
	title = query.value("title").toString();
	added = query.value("added").toDateTime();
	result = query.value("result").toString();
	keywords = query.value("keywords").toString();
}

Corp::~Corp()
{

}

/*
namespace qx
{

template<>
void register_class(QxClass<Corp>& c)
{
	c.id(&Corp::corp_id, "id");
	c.data(&Corp::title, "title");
	c.data(&Corp::added, "added");
	c.data(&Corp::result, "result");
	c.data(&Corp::keywords, "keywords");
	
}


}
*/
