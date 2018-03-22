#include "grafico.h"

int dibujar(double maxrobots, double * ticksmedio)
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_FONT * font = NULL;
	if (!al_init()) {
		fprintf(stderr, "Couldn't initialize allegro!\n");
		return -1;
	}
	if (!al_init_primitives_addon()) {
		fprintf(stderr, "Couldn't initialize primitives addon!\n");
		return -1;
	}
	display = al_create_display(SCREENSIZE, SCREENSIZE);
	if (!display) {
		fprintf(stderr, "Couldn't create allegro display!\n");
		return -1;
	}
	al_init_font_addon();
	if (!al_init_ttf_addon())
	{
		fprintf(stderr, "Couldn't install tff addon!\n");
	}
	font = al_load_ttf_font("5ceta_mono.ttf", 10, 0);  //Cargo letra de la escala
	if (!font) {
		fprintf(stderr, "Could not load 'disney.ttf'.\n");
		return -1;
	}

	al_draw_line(SCREENSIZE*1.0 / 8, SCREENSIZE*7.0 / 8, SCREENSIZE*9.0 / 10, SCREENSIZE*7.0 / 8, al_map_rgb(200, 0, 200), 2);//eje x
	al_draw_line(SCREENSIZE*1.0 / 8, SCREENSIZE*1.0 / 8, SCREENSIZE*1.0 / 8, (SCREENSIZE * 7 / 8), al_map_rgb(200, 0, 200), 2);//eje y
	

	for (int i = 0; i <= maxrobots; i++)
	{
		if (((SCREENSIZE*7.0 / 8) / ticksmedio[i]) > 1)
		{

			al_draw_rectangle((SCREENSIZE*1.0 / 8) + 1 + (((6.0 / 8)*SCREENSIZE) / maxrobots) * i, (SCREENSIZE*7.0 / 8 - ticksmedio[i]), (SCREENSIZE*1.0 / 8) + (((6.0 / 8)*SCREENSIZE) / maxrobots) + (((6.0 / 8)*SCREENSIZE) / maxrobots) * i, SCREENSIZE*7.0 / 8 - 2, al_map_rgb(200, 0, 0), 2);
			al_draw_filled_rectangle((SCREENSIZE*1.0 / 8) + 1 + (((6.0 / 8)*SCREENSIZE) / maxrobots) * i, SCREENSIZE*7.0 / 8 - ticksmedio[i], (SCREENSIZE*1.0 / 8) + (((6.0 / 8)*SCREENSIZE) / maxrobots) + (((6.0 / 8)*SCREENSIZE) / maxrobots) * i, SCREENSIZE*7.0 / 8 - 2, al_map_rgb(255, 255, 255));
		}
		else
		{
			al_draw_rectangle((SCREENSIZE*1.0 / 8) + 1 + (((6.0 / 8)*SCREENSIZE) / maxrobots) * i, ( 1.0/8*SCREENSIZE), (SCREENSIZE*1.0 / 8) + (((6.0 / 8)*SCREENSIZE) / maxrobots) + (((6.0 / 8)*SCREENSIZE) / maxrobots) * i, SCREENSIZE*7.0 / 8 - 2, al_map_rgb(200, 0, 0), 2);
			al_draw_filled_rectangle((SCREENSIZE*1.0 / 8) + 1 + (((6.0 / 8)*SCREENSIZE) / maxrobots) * i, (1.0 / 8 * SCREENSIZE), (SCREENSIZE*1.0 / 8) + (((6.0 / 8)*SCREENSIZE) / maxrobots) + (((6.0 / 8)*SCREENSIZE) / maxrobots) * i, SCREENSIZE*7.0 / 8 - 2, al_map_rgb(255, 255, 255));
		}
	}

	al_draw_text(font, al_map_rgb(255, 255, 255), SCREENSIZE*1.0 / 2, 40, ALLEGRO_ALIGN_CENTER, "Tics vs cantidad de robots");
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREENSIZE*1.0 / 2, SCREENSIZE*(8.0 / 9), ALLEGRO_ALIGN_CENTER, "Cantidad de robots");

	if ((SCREENSIZE*7.0 / 8 - ticksmedio[0]) > 60)
	{
		al_draw_textf(font, al_map_rgb(255, 255, 255), 70, SCREENSIZE*7.0 / 8 - ticksmedio[0]-10, ALLEGRO_ALIGN_CENTER, "%d", (int)ticksmedio[0]);
	}
	else	//por si se pasa de lugar la barra
	{
		al_draw_textf(font, al_map_rgb(255, 255, 255), 70, SCREENSIZE/8.0-10, ALLEGRO_ALIGN_CENTER, "%d", (int)ticksmedio[0]);
	}
	
	al_draw_text(font, al_map_rgb(255, 255, 255), 40, (SCREENSIZE*1.0 / 2), ALLEGRO_ALIGN_CENTER, "T");
	al_draw_text(font, al_map_rgb(255, 255, 255), 40, (SCREENSIZE*1.0 / 2) + 15, ALLEGRO_ALIGN_CENTER, "i");
	al_draw_text(font, al_map_rgb(255, 255, 255), 40, (SCREENSIZE*1.0 / 2) + 30, ALLEGRO_ALIGN_CENTER, "c");
	al_draw_text(font, al_map_rgb(255, 255, 255), 40, (SCREENSIZE*1.0 / 2) + 45, ALLEGRO_ALIGN_CENTER, "s");
	
	
	
	al_flip_display();


	
	printf("Press any key to exit\n");
	getchar();
	
	al_destroy_display(display);
	al_shutdown_primitives_addon();
	return 1;

}
