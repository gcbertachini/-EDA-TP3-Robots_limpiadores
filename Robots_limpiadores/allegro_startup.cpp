#include "allegro_startup.h"

#define BACKGROUND_MUSIC	"shooting_stars.wav"
/*
*	Otra forma de inicializar allegro: util cuando hay muchas inicializaciones
*	ya que al fallar una se va cayendo y destruyendo lo que inicializo. Sin embargo,
*	resulta media confusa por el uso excesivo de indentacion/if anidados.
*
*	"(...). The answer to that is that if you need more than
*	3 levels of indentation, you're screwed anyway, and should fix
*	your program."
*	-Linus Torvalds https://www.kernel.org/doc/Documentation/CodingStyle
*
*   Usar a criterio y gusto de c/u.
*/
bool allegro_startup(void)
{
	if (al_init())
	{
		if (al_init_primitives_addon())
		{
			if (al_install_keyboard())
			{
				if (al_install_mouse())
				{
					if (al_init_image_addon())
					{
						al_init_font_addon();   //Void
						if (al_init_ttf_addon())
						{
							if (al_install_audio())
							{
								if (al_init_acodec_addon())
								{
									if (al_reserve_samples(1))
									{
										return true;

									}
									else
										fprintf(stderr, "ERROR: Failed to reserve samples:(\n");
									//al_shutdown_acodec_addon(); Does not exist
								}
								else
									fprintf(stderr, "ERROR: Failed to initialize acodec addon\n");
								al_uninstall_audio();
							}
							else
								fprintf(stderr, "ERROR: Failed to install audio\n");
							al_shutdown_ttf_addon();
						}
						else
							fprintf(stderr, "ERROR: Failed to initialize ttf addon\n");
						al_shutdown_font_addon();
						al_shutdown_image_addon();
					}
					else
						fprintf(stderr, "ERROR: Failed to initialize image addon\n");
					al_uninstall_mouse();
				}
				else
					fprintf(stderr, "ERROR: Failed to install mouse\n");
				al_uninstall_keyboard();
			}
			else
				fprintf(stderr, "ERROR: Failed to to install keyboard\n");
			al_shutdown_primitives_addon();
		}
		else
			fprintf(stderr, "ERROR: Failed to load primitives addon \n");
	}
	else
		fprintf(stderr, "ERROR: Failed to initialize allegro system\n");
	return false;
}

void allegro_shut_down(void)
{
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
	al_uninstall_audio();
	al_uninstall_system();
}


ALLEGRO_SAMPLE * loadPlayMusic(void)
{
	ALLEGRO_SAMPLE * music = al_load_sample(BACKGROUND_MUSIC);
	if (music)
		al_play_sample(music, 0.7, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	else
		fprintf(stderr, "Unable to load background music\n");

	return music;
}


void stopMusic(ALLEGRO_SAMPLE *music)
{
	al_stop_samples();
	al_destroy_sample(music);

}