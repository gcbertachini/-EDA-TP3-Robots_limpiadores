#include "piso.h"

#include <iostream>


using namespace std;




bool Piso::create(unsigned int fila, unsigned int columna)
{
	fila_size = fila;
	col_size = columna;

	tiles = (bool *)malloc(fila_size*col_size * sizeof(bool));
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
				tiles[i*col_size + j] = sucio;	//seteo la baldosa como sucia

			}

		}
	}

	return true;

}


bool Piso::update(double x, double y)
{
	int new_x = (int)floor(x);	//trunco los numeros para sacar su parte decimal
	int new_y = (int)floor(y);

	if (tiles[new_x*col_size + new_y] == sucio)
	{
		tiles[new_x*col_size + new_y] = limpio;	//actualizo y limpio la baldosa
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

	if (tiles[new_x*col_size + new_y] == sucio)
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
	bool control = limpio;

	for (unsigned int i = 0; ((i < fila_size) && (control == limpio)); i++)
	{
		for (unsigned int j = 0; ((j < col_size) && (control == limpio)); j++)
		{
			if (tiles[i*col_size + j] == sucio)	//me fijo si alguna de la baldosa esta sucia
			{
				control = sucio;
			}		
		}
	}

	/*for (unsigned int i = 0; (i < fila_size) ; i++)
	{
		for (unsigned int j = 0; (j < col_size) ; j++)
		{
		if (tiles[i*col_size + j] == sucio)	//me fijo si alguna de la baldosa esta sucia
		{
			printf("|*|");
		}
		else
			printf("| |");
		}
		puts("\n");
	}
	puts("\n\n");*/
	return (control==sucio);
}