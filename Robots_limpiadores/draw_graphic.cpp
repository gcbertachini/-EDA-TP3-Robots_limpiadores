
#include "allegro_startup.h"

void print_num(int i, float desp, ALLEGRO_FONT* font2, ALLEGRO_DISPLAY_MODE* disp_data, float section_width);

int draw_graphic(uint i, uint * arr) 
{
	ALLEGRO_DISPLAY *mi_display= NULL;
	ALLEGRO_BITMAP *display_background=NULL,*paper=NULL;
	ALLEGRO_SAMPLE * background_music= NULL;
	ALLEGRO_FONT * font = NULL,* font2=NULL;
	unsigned int control = 0;
	ALLEGRO_DISPLAY_MODE   disp_data;

	//uint i = 9;
	//double arr[10] = { 25463.612000000001 ,12780.572000000000 ,8680.572000000000,6480.572000000000,6180.572000000000,1280.572000000000,4280.572000000000,3680.572000000000,3180.572000000000,2880.572000000000 };

	uint frames_availables = FPS * GRAPHIC_LIFE_SPAN;
	double total_amount_of_ticks = 0;
	uint graphic_unit=0;
	uint *large_columns =(uint *) malloc(i*sizeof(uint));
	
	
	for (int j = 0; j <= i; j++)
		total_amount_of_ticks = total_amount_of_ticks + arr[i];


	graphic_unit = total_amount_of_ticks / frames_availables; //cantidad de ticks que hay que dibujar por frame para llegar a dibujar el dibujo en 10 segundos


	for (int n = 0; n <= i; n++)
	{
		large_columns[n] = arr[n] / graphic_unit; //cuantos frames voy a tardar en dibujar cada columna
		printf("Cantidad de frames que necesito para dibujar la columna%d:%d\n",n, large_columns[n]);
	}

	if (1)
	{
	}
	else if(! (display_background = al_load_bitmap("robot.png")) )
	{
		fprintf(stderr,"Unable to load background\n"); 
		al_uninstall_system();
		al_shutdown_image_addon();
		al_destroy_display(mi_display);
		return -1;
	}
	else if (!(paper = al_load_bitmap("papel_milimetrado.png")))
	{
		fprintf(stderr, "Unable to load paper\n");
		al_uninstall_system();
		al_shutdown_image_addon();
		al_destroy_display(mi_display);
		return -1;
	}
	font = al_load_ttf_font("disney.ttf", 30, 0);   //cargo letra de Disney
	if (!font) {
		fprintf(stderr, "Could not load 'disney.ttf'.\n");
		return -1;
	}
	font2 = al_load_ttf_font("5ceta_mono.ttf", 10, 0);  //Cargo letra de la escala
	if (!font2) {
		fprintf(stderr, "Could not load 'disney.ttf'.\n");
		return -1;
	}


	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);   //configuro allegro en modo pantalla completa
	mi_display = al_create_display(disp_data.width, disp_data.height);

	background_music = loadPlayMusic();


	printf("Alto del gráfico:%d\n", (9*disp_data.height)/20);
	printf("Tamaño de un segmento:%f\n", ((9 * (float)disp_data.height) / 20)/ large_columns[0]);
	
	float graph_height = (9 * disp_data.height) / 20; //altura de la barra más alta
	float graph_width = (disp_data.width) / 2;   //ancho del gráfico
	float section_width = graph_width / (1.5*i);  //ancho de una sección de pantalla


	while (1)
	{
		al_clear_to_color(al_map_rgb(255, 255, 255));

		al_draw_tinted_bitmap(display_background, al_map_rgba_f(1, 1, 1, 0.5), 0, 0, 0);  //Imprimo robots
		al_draw_tinted_bitmap(display_background, al_map_rgba_f(1, 1, 1, 0.5), disp_data.width - al_get_bitmap_width(display_background), disp_data.height - al_get_bitmap_height(display_background), ALLEGRO_FLIP_HORIZONTAL);
		al_draw_tinted_bitmap(display_background, al_map_rgba_f(1, 1, 1, 0.5), disp_data.width - al_get_bitmap_width(display_background), 0, ALLEGRO_FLIP_HORIZONTAL);
		al_draw_tinted_bitmap(display_background, al_map_rgba_f(1, 1, 1, 0.5), 0, disp_data.height - al_get_bitmap_height(display_background), 0);
		al_draw_scaled_bitmap(display_background, 0, 0, al_get_bitmap_width(display_background), al_get_bitmap_height(display_background), 0.75* disp_data.width, 0.75 *disp_data.height, disp_data.width / 20, disp_data.height / 15, 0);

		al_draw_text(font, al_map_rgb(0, 0, 0), disp_data.width / 2, (disp_data.height / 16), ALLEGRO_ALIGN_CENTER, "Modo 2 - Gráfico de eficiencia");

		al_draw_scaled_bitmap(paper, 0, 0, al_get_bitmap_width(paper), al_get_bitmap_height(paper), disp_data.width / 4, disp_data.height / 4, disp_data.width / 2, disp_data.height / 2, 0); //imprimo papel milimetrico

		al_draw_line(disp_data.width / 4, disp_data.height / 4, disp_data.width / 4, 3 * disp_data.height / 4, al_map_rgb(0, 0, 0), 2);  //dibujo ejey
		al_draw_line(3 * disp_data.width / 4, 3 * disp_data.height / 4, disp_data.width / 4, 3 * disp_data.height / 4, al_map_rgb(0, 0, 0), 2);//dibujo eje x

		al_draw_line(disp_data.width / 4, disp_data.height / 4, disp_data.width / 4.1, disp_data.height / 3.7, al_map_rgb(0, 0, 0), 2);  //flecha
		al_draw_line(disp_data.width / 4, disp_data.height / 4, disp_data.width / 3.9, disp_data.height / 3.7, al_map_rgb(0, 0, 0), 2);

		al_draw_line(3 * disp_data.width / 4, 3 * disp_data.height / 4, 3 * disp_data.width / (4.05), 3 * disp_data.height / (4.05), al_map_rgb(0, 0, 0), 2);//flecha
		al_draw_line(3 * disp_data.width / 4, 3 * disp_data.height / 4, 3 * disp_data.width / (4.05), 3 * disp_data.height / (3.95), al_map_rgb(0, 0, 0), 2);
	
		for (int m = 0,   desp = 0; m <= i ;  m++, desp+= (1.25*section_width))
		{
			print_num(m+1, desp,font2,&disp_data,section_width);

			for (int j = 0; j < large_columns[m]; j++)
			{
				al_draw_line(disp_data.width / 4  + desp + (section_width), 3 * disp_data.height / 4 - 1, disp_data.width / 4 + desp + section_width, (3 * disp_data.height / 4) - 1 - ((((arr[m]*graph_height)/arr[0]) / large_columns[m])*(j + 1)), al_map_rgb(rand()%200, rand() % 200, rand() % 200),  section_width);
				al_rest(REST);
				al_flip_display();
			}
		}

	}


	stopMusic(background_music);
	al_destroy_display(mi_display);
	allegro_shut_down();
	free(large_columns); 

	return EXIT_SUCCESS;
}


//Función que imprime los números en la escala de robots
void print_num(int i, float desp,ALLEGRO_FONT* font2, ALLEGRO_DISPLAY_MODE* disp_data, float section_width)
{
	switch (i)
	{
	case(1):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "1");
		break;

	case(2):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "2");
		break;

	case(3):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "3");
		break;

	case(4):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "4");
		break;

	case(5):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "5");
		break;

	case(6):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "6");
		break;

	case(7):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "7");
		break;

	case(8):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "8");
		break;

	case(9):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "9");
		break;

	case(10):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "10");
		break;

	case(11):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "11");
		break;

	case(13):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "12");
		break;

	case(14):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "13");
		break;
	case(15):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "14");
		break;
	case(16):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "15");
		break;
	case(17):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "16");
		break;
	case(18):
		al_draw_text(font2, al_map_rgb(0, 0, 0), disp_data->width / 4 + desp + (section_width), 3 * disp_data->height / 4 + 10, ALLEGRO_ALIGN_CENTER, "17");
		break;


	}

}
