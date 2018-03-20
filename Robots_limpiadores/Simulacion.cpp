#include "Simulacion.h"
#include <time.h>
#include <iostream>
#include <cmath>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_DISPLAY *dis = NULL;

bool simulacion::create(uint robotcount, uint fils, uint cols, modetype m)
{

	pisop.create(fils, cols);	//Creo el piso

	robs = (Robot*)malloc(robotcount * sizeof(Robot));	//Creo los robots
	if (robs != NULL)
	{
		for (uint i = 0; i < robotcount; i++)
		{
			robs[i].create(fils, cols);
		}


		uint ticks = 0;

	}

	else

	{
		pisop.destroy();
//		destroy();
	}

	return (robs != NULL);

}



uint simulacion::run(uint robotcount, uint fils, uint cols, modetype m)
{
	while (!pisop.stillDirty())
	{
		for (uint i = 0; i < robotcount; i++)
		{
			robs[i].update(fils, cols);
			position_t coord_actual = robs[i].getPos();
			pisop.update(coord_actual.x, coord_actual.y);
		}
	}
	ticks++;

	return ticks;
}