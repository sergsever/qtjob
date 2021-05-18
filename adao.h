#ifndef ADAO_H
#define ADAO_H
#include "precompiled.h"

template<typename Entity>
class ADAO
{
public:
	ADAO() {;}
	virtual ~ADAO(){;}
std::vector<Entity> getAll();
std::vector<Entity> find(QString request);
void add(Entity entity);
};

#endif // ADAO_H
