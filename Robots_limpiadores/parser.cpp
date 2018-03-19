#include "parser.h"
#include "main.h"
#include <string>

#define MAX_PARAM_SIZE 12

bool parseCallback(char *key, char *value, void * parameters)
{

	parameters_t * data = (parameters_t*) parameters ;  //Esto es redundante, pero visual studio no me dejaba desreferenciarlo bien si no lo hacía.


	bool validez = false; //Respuesta del callback
	char casehandler[MAX_PARAM_SIZE]; //String para trabajar con las mayusculas/minusculas.

	if (key[0] == '-') // Analizo parámetros
	{
		int i;
		int cerrarBucle = 0;

		if (strlen(&(key[1])) <= MAX_PARAM_SIZE) {
			strcpy_s(casehandler, &(key[1])); // para no tomar con el strcmp el OPTION_IDENTIFIER
		}

		for (i = 0; (i < OPTION_QTY) && cerrarBucle == 0; i++) //ciclo el arreglo de opciones hasta hallar la clave igual
		{
			if (!(strcmp(strlower(casehandler), data->options[i])))
			{
				if(checkValues(key,value,parameters)){
					validez = true;
					cerrarBucle = 1;
				}
			}
			else  //Ocurre en el caso en el que la clave no es valida.
			{
				validez = false;
			}
		}

	}
	return validez;
}

/***********************************
Función strlwr
************************************/

char* strlower(char str[])
{
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		str[i] = tolower(str[i]); //Todo caracter en mayuscula se pasa a minuscula, logrando que el programa sea case insensitive.
	}
	return str;
}

bool checkValues(char * key, char * value, void * parameters) {


	parameters_t * param = (parameters_t *)parameters;
	bool validez = false;

	char casehandler[MAX_PARAM_SIZE]; //String para trabajar con las mayusculas/minusculas.



	if (strlen(&(key[1])) <= MAX_PARAM_SIZE)
	{
		strcpy(casehandler, &(key[1])); // Para no tomar con el strcmp el OPTION_IDENTIFIER, además de asegurarnos que podamos modificar el string.
		if (!(strcmp(strlower(casehandler),"width")) && (atoi(value) <= 70) && (atoi(value) > 0)){ //Corroboro cual parámetro es y si cumple los valores en los que está acotado.
				param->width = atoi(value);
				validez = true;
		}
		else if (!(strcmp(strlower(casehandler), "height")) && (atoi(value) <= 100) && (atoi(value) > 0)){
			param->height = atoi(value);
			validez = true;
		}
		else if (!(strcmp(strlower(casehandler), "robots")) && (atoi(value) > 0)) {
			param->robots = atoi(value);
			validez = true;
		}
		else if (!(strcmp(strlower(casehandler), "mode"))) {

			if (atoi(value) == mode1) {
				param->mode = mode1;
				validez = true;
			}
			else if (atoi(value) == mode2) {
				param->mode = mode2;
				validez = true;
			}
		}
	}


	return validez;
}
