#ifndef ALLEGRO_STRATUP_H
#define ALLEGRO_STRATUP_H

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define D_WIDTH		1000
#define D_HEIGHT	600

bool allegro_startup(void);
void allegro_shut_down(void);

ALLEGRO_SAMPLE * loadPlayMusic(void);
void stopMusic(ALLEGRO_SAMPLE *music);


#endif