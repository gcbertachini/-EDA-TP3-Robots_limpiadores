#include "Simulacion.h"
#include "general.h"
#include <time.h>
#include <iostream>
#include <cmath>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<allegro5\allegro_primitives.h>



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

//		uint ticks = 0;

	}

	else

	{
		destroy();
	}

	return (robs != NULL);

}



uint simulacion::run(uint robotcount, uint fils, uint cols, modetype m)
{
	ticks = 0;
	bool floorIsDirty = true;

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

		if(!al_init_primitives_addon())
		{
			fprintf(stderr, "failed to initialize primitive addon !\n");
			return -1;
		}

		ALLEGRO_DISPLAY *display = NULL;

		display = al_create_display(SCREENSIZE, SCREENSIZE);


		
		 while (floorIsDirty)
		{
		
			 floorIsDirty = pisop.stillDirty();

			 //antes de los robots dibujo el piso
			 
			 for (uint i = 0; i < cols; i++)
			 {
				 for (uint j = 0; j < fils; j++)
				 {


					 if (!pisop.isDirty(i, j))
					 {
						 al_draw_filled_rectangle((SCREENSIZE / cols)*i, (SCREENSIZE / fils)*j, (SCREENSIZE / cols) + (SCREENSIZE / cols)*i, (SCREENSIZE / fils) + (SCREENSIZE / fils)*j, al_map_rgb(155, 155, 140));
					 }
					 else
					 {
						 al_draw_filled_rectangle((SCREENSIZE / cols)*i, (SCREENSIZE / fils)*j, (SCREENSIZE / cols) + (SCREENSIZE / cols)*i, (SCREENSIZE / fils) + (SCREENSIZE / fils)*j, al_map_rgb(255, 255, 240));
					 }

					 al_draw_rectangle((SCREENSIZE / cols)*i, (SCREENSIZE / fils)*j, (SCREENSIZE / cols) + (SCREENSIZE / cols)*i, (SCREENSIZE / fils) + (SCREENSIZE / fils)*j, al_map_rgb(0, 0, 0), 3);// este se dibuja siempre para hacer la divison de baldosas

				 }
			 }
			 
			


			 for (uint i = 0; i < robotcount; i++)
			 {
				 robs[i].update(fils, cols);
				 position_t coord_actual = robs[i].getPos();
				 pisop.update(coord_actual.x, coord_actual.y);
			 }
				 ticks++;
				 al_flip_display();
				 al_clear_to_color(al_map_rgb(0, 0, 0));
				 al_rest(0.003);
			 
		}
		
	}
	else	// MODO2
	{
		while (pisop.stillDirty())
		{
			for (uint i = 0; i < robotcount; i++)
			{
				robs[i].update(fils, cols);
				position_t coord_actual = robs[i].getPos();
				pisop.update(coord_actual.x, coord_actual.y);

			}

			ticks++;
			//if (ticks > 20)
				//break;
		}
	}
	//printf("\nticks:%d", ticks);

	return ticks;
}








void simulacion::destroy()
{
	pisop.destroy();
	free(robs);
}
