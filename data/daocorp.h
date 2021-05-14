#ifndef DAOCORP_H
#define DAOCORP_H
#include "precompiled.h"
#include "corp.h"

class DaoCorp : ADAO<Corp>
{
public:
	DaoCorp();
	std::vector<Corp> getAll();
	std::vector<Corp> find(QString request);
};

#endif // DAOCORP_H
