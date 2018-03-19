#include "Simulacion.h"
#include <time.h>
#include <iostream>
#include <cmath>
#include <allegro5\allegro.h>
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


		uint tickscount = 0;

	}

	else

	{
		pisop.destroy();
		destroy();
	}

	return (robs != NULL);

}



void simulacion::avanzar(uint robotcount, uint fils, uint cols)
{
	for (uint i = 0; i < robotcount; i++)
	{
		robs[i].update(fils, cols);
		position_t coord_actual = robs[i].getPos();
		pisop.update(coord_actual.x, coord_actual.y);
	}
}



uint simulacion::run(uint robotcount, uint fils, uint cols, modetype m)
{
	if (m = modo1)	//Si es el modo 1, debe graficarse en Allegro

	{
		if (!al_init()) //Inicializar Allegro
		{
			fprintf(stderr, "Error al inicializar Allegro."); // Imprimir errores en stream STDERR
			exit(-1);
		}

		al_init_image_addon();

		dis = al_create_display(fils, cols);
	}
}