#ifndef _PISO_H
#define _PISO_H

#include <iostream>
/************************************************************************
CLASES Y TYPEDEFS
************************************************************************/
typedef unsigned int uint;

typedef struct {
	double x;
	double y;
}position_t;

class Robot
{
public:
	void create(uint maxFils, uint maxCols);
	void update(uint maxFils, uint maxCols);
	position_t getPos();
	void allegro_robot(const char * nombre_archivo, double x, double y); //////AGREGADO POR RUBIDIO, VERIFICAR

private:
	position_t location;
	double dir;
};

#endif