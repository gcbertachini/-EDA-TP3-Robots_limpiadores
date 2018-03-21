#define _USE_MATH_DEFINES
#include <cmath>
#include "robot.h"
#include <time.h>
#include <iostream>
#include "general.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


#define RADIAN(a) ( (a)/( 180.0/(double)M_PI) )
#define PNGSIZE 100

using namespace std;

void Robot::create(uint maxFils, uint maxCols)
{

	location.x = (rand() % (SCREENSIZE-PNGSIZE));  //Obtengo una posición en x aleatoria dentro del tablero
	location.y = (rand() % (SCREENSIZE-PNGSIZE)); //Obtengo una posición en y aleatoria dentro del tablero
	dir = (RADIAN(rand() % 360));  //Obtengo una dirección aleatoria entre 0 y 2Pi para luego pasarla a radianes
	
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

	if (!((maxCols-PNGSIZE >= next_location.x) && (maxFils-PNGSIZE >= next_location.y) && (0 <= next_location.y) && (0 <= next_location.x))) //Me fijo si no se va de la cocina
		can_move = false;
	else  //Si no se va las posciones futuras pasan a ser las actuales
	{
		location.x = next_location.x;
		location.y = next_location.y;
	}

	if (can_move == false) //Si el robot se va del piso, mantengo la posición y consigo una nueva dirección aleatoria
		dir = (RADIAN(rand() % 360));

}

void Robot::allegro_robot(const char * nombre_archivo, double x, double y)	//AGREGADO POR RUBIDIO, VERIFICAR
{
	ALLEGRO_BITMAP * imagen = al_load_bitmap(nombre_archivo);

	

	if (imagen != NULL)
	{
		al_draw_bitmap(imagen,x ,y,0 );

	}
}
