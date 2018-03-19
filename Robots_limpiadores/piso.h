#pragma once
#include<cmath>

class Piso {

public:
	bool create(unsigned int filas, unsigned int columnas);
	//crea un matriz de filas*columnas que va a servir de piso 
	//devuelve true si se pudo crear o devuelve false sino

	void destroy();
	//destruye el arreglo creado

	bool update(double x, double y);
	//toma las coordenadas en donde va el robot se fija como esta el piso y lo limpia

	bool isDirty(double x, double y);

	bool stillDirty();
	//se fija si estan limpias todas las baldosas devuelve false si lo estan
	//caso contrario devuelve true

private:
	unsigned int fila_size;
	unsigned int col_size;
	bool ** tiles;	//chequear este 



};