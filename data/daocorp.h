#ifndef DAOCORP_H
#define DAOCORP_H
#include "precompiled.h"
#include "corp.h"
#include "adao.h"

class DaoCorp : public ADAO<Corp>
{
public:
	DaoCorp();
	virtual ~DaoCorp(){;}
	std::vector<Corp> getAll();
	std::vector<Corp> findByTitle(QString title);
	void add(Corp& entity );
};

#endif // DAOCORP_H
