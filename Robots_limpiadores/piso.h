#pragma once
#include<cmath>
#include "general.h"

class Piso {

public:
	bool create(unsigned int filas, unsigned int columnas);
	//crea un matriz de filas*columnas que va a servir de piso 
	//devuelve true si se pudo crear o devuelve false sino

	void destroy();
	//destruye el arreglo creado

	bool update(position_t location);
	//toma las coordenadas en donde va el robot se fija como esta el piso y lo limpia

	bool isDirty(position_t location);

	bool stillDirty();
	//se fija si estan limpias todas las baldosas devuelve false si lo estan
	//caso contrario devuelve true

private:
	uint fila_size;
	uint col_size;
	bool ** tiles;	//chequear este 



};