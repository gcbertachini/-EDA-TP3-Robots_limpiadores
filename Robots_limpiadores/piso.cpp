#include "piso.h"

#include <iostream>


using namespace std;




bool Piso::create(unsigned int fila, unsigned int columna)
{
	fila_size = fila;
	col_size = columna;

	tiles = (bool **)malloc(fila_size*col_size * sizeof(bool));
	if (tiles == NULL)
	{
		return false;	//esto indica que no se pudo reservar memoria
	}
	else
	{
		for (unsigned int i = 0; i < fila_size; i++)
		{
			for (unsigned int j = 0; j < col_size; j++)
			{
				tiles[i][j] = true;	//seteo la baldosa como sucia

			}

		}
	}

	return true;

}


bool Piso::update(double x, double y)
{
	int new_x = (int)floor(x);	//trunco los numeros para sacar su parte decimal
	int new_y = (int)floor(y);

	if (tiles[new_x][new_y] == true)
	{
		tiles[new_x][new_y] = false;	//actualizo y limpio la baldosa
		return true;	//indico que se limpio una baldosa y hay que actualizar el mapa
	}
	else
	{
		return false;	//indico que la baldosa esta limpia
	}

}

void Piso::destroy()
{
	free(tiles);

}

bool Piso::isDirty(double x, double y)
{
	int new_x = (int)floor(x);	//trunco los numeros para sacar su parte decimal
	int new_y = (int)floor(y);

	if (tiles[new_x][new_y] == true)
	{
		return true;	//indico que la baldosa sigue sucia
	}
	else
	{
		return false;	//indico que la baldosa esta limpia
	}
}


bool Piso::stillDirty()
{
	bool control = false;

	for (unsigned int i = 0; ((i < fila_size) && !control); i++)
	{
		for (unsigned int j = 0; ((j < col_size) && !control); j++)
		{
			if (tiles[i][j] == true)	//me fijo si alguna de la baldosa esta sucia
			{
				control = true;
			}
		}
	}

	return control;
}

