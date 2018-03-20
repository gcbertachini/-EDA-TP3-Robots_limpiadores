#include"modo2.h"

double promediosim[10000];


bool modo2( uint filas, uint col)
{
	
	simulacion s;
	uint ticksporsim[NSIM];	//debido a que el numero de simulaciones es el mismo
							//arreglo donde se van a guardar cuantos ticks uso cada simulacion
	double promedio = 0.0;

	
	uint j = 1; //variable que indica la cantidad de robots 
	
	for (uint i = 0; i < NSIM; i++)
	{	
		if (s.create(j, filas, col, 2))	//le sumo 1 a i como no pueden haber 0 robots
		{
			ticksporsim[i] = s.run(j, filas, col, 2);	//guardo en el valor del arreglo que le corresponde el 
			s.destroy();
		}

		else
			return false;	//si no se puede crear una de las simulaciones la funcion devuelve false
	}


	for (uint i = 0; i < NSIM; i++)	
	{
		promedio += ticksporsim[i];

	}
	

	//unir los dos ciclos de arriba y hacer un ciclo para que calcule los promedios de las n simulaciones
	//poniendo un while que tenga dos condiciones para evitar problemas con las primeras dos pasadas
	promediosim[j] = (promedio / 1000.0); // no pongo NSIM para evitar posibles casteos
	
	
	
}