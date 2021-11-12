#ifndef POLYMORH_H
#define	POLYMORH_H

#include "ASpell.hpp"

class Polymorph: public ASpell
{
public:
	Polymorph();
	~Polymorph();
	Polymorph*  clone() ;
};

#endif