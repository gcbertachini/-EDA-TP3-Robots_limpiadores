#include "Simulacion.h"
#include "general.h"
#include <time.h>
#include <iostream>
#include <cmath>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>



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
		destroy();
	}

	return (robs != NULL);

}



uint simulacion::run(uint robotcount, uint fils, uint cols, modetype m)
{
	if (m == mode1)
	{
		//////INICIALIZACION DE ALLEGRO Y DEFINES//////////

		if (!al_init())
		{
			fprintf(stderr, "Allegro not initialized");
			return -1;
		}

		if (!al_init_image_addon())
		{
			fprintf(stderr, "failed to initialize image addon !\n");
			return -1;
		}

		ALLEGRO_DISPLAY *display = NULL;

		display = al_create_display(700, 700);



		for (uint i = 0; i < robotcount; i++)	//Inicializacion de imagen de los robots
		{
			if (i == 0)
			{
				robs[i].allegro_robot("WallE.png");
			}

			else
			{
				if (i == (robotcount - 1))
				{
					robs[i].allegro_robot("Eva.png");
				}

				else
				{
					robs[i].allegro_robot("Limpieza.png");
				}
			}

		}

		while (!pisop.stillDirty())
		{
			for (uint i = 0; i < robotcount; i++)
			{
				robs[i].update(fils, cols);
				position_t coord_actual = robs[i].getPos();
				pisop.update(coord_actual.x, coord_actual.y);
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_flip_display();
			}

			ticks++;
			al_rest(0.003);
		}
	}
	return ticks;
}


void simulacion::destroy()
{
	pisop.destroy();
	free(robs);
}