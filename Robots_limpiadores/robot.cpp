#define _USE_MATH_DEFINES
#include <cmath>
#include "robot.h"
#include "general.h"
#include "parameters.h"
#include <time.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>}
#include<allegro5/allegro_primitives.h>

#define RADIAN(a) ( (a)/( 180.0/(double)M_PI) )


using namespace std;

void Robot::create(uint maxFils, uint maxCols)
{
	
	location.x = (rand() % maxCols);  //Obtengo una posici�n en x aleatoria dentro del tablero
	location.y = (rand() % maxFils); //Obtengo una posici�n en y aleatoria dentro del tablero
	dir = (RADIAN(rand() % 360));  //Obtengo una direcci�n aleatoria entre 0 y 2Pi para luego pasarla a radianes
	ALLEGRO_BITMAP * imagen = NULL;
}

position_t Robot::getPos()
{
	return location;  //Devuelvo el dato miembro de la locaci�n del robot
}

void Robot::update(uint maxFils, uint maxCols)
{
	bool can_move = true;
	position_t next_location;

	next_location.x = location.x + cos(dir);  //Calculo la futura posici�n en x
	next_location.y = location.y + sin(dir);  //Calculo la futura posici�n en y

	if ((((double)maxCols) <= floor(next_location.x)) || (0>floor(next_location.x)) || (0>floor(next_location.y)) || (((double)maxFils) <= floor(next_location.y))) //Me fijo si no se va de la cocina
		can_move = false;
	else  //Si no se va las posciones futuras pasan a ser las actuales
	{
		location.x = next_location.x;
		location.y = next_location.y;
	}

	if (can_move == false) //Si el robot se va del piso, mantengo la posici�n y consigo una nueva direcci�n aleatoria
		dir = (RADIAN(rand() % 360));

}

void Robot::allegro_robot(uint fils, uint cols)	//AGREGADO POR RUBIDIO, VERIFICAR
{
	al_draw_filled_circle((SCREENSIZE/cols)*location.x, (SCREENSIZE / fils)*location.y, 10, al_map_rgb(50, 50, 255));
}