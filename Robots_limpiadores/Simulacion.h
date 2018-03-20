#pragma once

#include "robot.h"
#include "piso.h"
#include "general.h"
typedef unsigned int uint;

//double tick_time = 0.25;

class simulacion
{
public:
	bool create(uint robotcount, uint fils, uint cols, modetype m);
	uint run(uint robotcount, uint fils, uint cols, modetype m);

	void destroy();


private:
	Robot * robs;
	Piso pisop;
	uint ticks;
	modetype mode;

};
