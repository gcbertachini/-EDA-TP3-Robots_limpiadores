#pragma once

#include "robot.h"
#include "piso.h"
typedef unsigned int uint;
typedef enum {modo1, modo2} modetype;

double tick_time = 0.25;

class simulacion
{	public:
		bool create(uint robotcount, uint fils, uint cols, modetype m);
		uint run(uint robotcount, uint fils, uint cols, modetype m);
		void avanzar(uint robotcount, uint fils, uint cols);
		void destroy();


private:
	Robot * robs;
	Piso pisop;
	uint ticks;
	modetype mode;

};
