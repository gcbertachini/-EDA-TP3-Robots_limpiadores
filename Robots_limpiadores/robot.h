#ifndef _PISO_H
#define _PISO_H
#include "general.h"
/************************************************************************
                        CLASES Y TYPEDEFS
************************************************************************/

class Robot 
{
public:
	void create(uint maxFils, uint maxCols);
	void update(uint maxFils, uint maxCols);
	position_t getPos();

private:
	position_t location;
	double dir;
};

#endif