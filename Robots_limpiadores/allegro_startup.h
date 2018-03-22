#ifndef ALLEGRO_STRATUP_H
#define ALLEGRO_STRATUP_H
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>


#define FPS	60.0
#define GRAPHIC_LIFE_SPAN 5.0
#define REST (1.0/FPS)

bool allegro_startup(void);
void allegro_shut_down(void);
typedef unsigned int uint;

ALLEGRO_SAMPLE * loadPlayMusic(void);
void stopMusic(ALLEGRO_SAMPLE *music);
int draw_graphic(uint i, uint * arr);


#endif