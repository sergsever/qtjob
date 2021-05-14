#ifndef ADAO_H
#define ADAO_H
#include "precompiled.h"

template<class Entity>
class ADAO
{
public:
	ADAO();
virtual ~ADAO();
std::vector<Entity> getAll();
std::vector<Entity> find(QString request);
};

#endif // ADAO_H
