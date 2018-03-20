#define _USE_MATH_DEFINES
#include <cmath>
#include "robot.h"
#include <time.h>
#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define RADIAN(a) ( (a)/( 180.0/(double)M_PI) )


using namespace std;

void Robot::create(uint maxFils, uint maxCols)
{
	srand(time(NULL));
	location.x = (rand() % maxCols);  //Obtengo una posición en x aleatoria dentro del tablero
	location.y = (rand() % maxFils); //Obtengo una posición en y aleatoria dentro del tablero
	dir = (RADIAN(rand() % 360));  //Obtengo una dirección aleatoria entre 0 y 2Pi para luego pasarla a radianes
	ALLEGRO_BITMAP * imagen = NULL;
}

position_t Robot::getPos()
{
	return location;  //Devuelvo el dato miembro de la locación del robot
}

void Robot::update(uint maxFils, uint maxCols)
{
	bool can_move = true;
	position_t next_location;

	next_location.x = location.x + cos(dir);  //Calculo la futura posición en x
	next_location.y = location.y + sin(dir);  //Calculo la futura posición en y

	if ((maxCols >= floor(next_location.x)) && (maxFils >= floor(next_location.y))) //Me fijo si no se va de la cocina
		can_move = false;
	else  //Si no se va las posciones futuras pasan a ser las actuales
	{
		location.x = next_location.x;
		location.y = next_location.y;
	}

	if (can_move == false) //Si el robot se va del piso, mantengo la posición y consigo una nueva dirección aleatoria
		dir = (RADIAN(rand() % 360));

}

void Robot::allegro_robot(const char * nombre_archivo)	//AGREGADO POR RUBIDIO, VERIFICAR
{
	ALLEGRO_BITMAP * imagen = al_load_bitmap(nombre_archivo);
	al_draw_scaled_bitmap(imagen, 0, 0, 1000, 1000, 0, 0, 0, 100, 100);
}