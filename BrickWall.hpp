#ifndef BRICK_H
#define	BRICK_H

#include "ATarget.hpp"

class BrickWall: public ATarget
{
public:
	BrickWall();
	~BrickWall();
	BrickWall* clone();
};



#endif