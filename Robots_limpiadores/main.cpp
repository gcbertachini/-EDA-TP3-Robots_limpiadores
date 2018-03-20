#include "general.h"
#include "parameters.h"
#include "parseCmdLine.h"
#include "Simulacion.h"
#include <iostream>
#include "allegro_startup.h"

#define MAX_ROBS_PERMITIDOS 100

using namespace std;

	int main(int argc, char * argv[]) {

		bool allegro_startup(void);

		class parameters_t germanTheTrueDetractor;

		int vArguments = parseCmdLine(argc, argv, parseCallback, &germanTheTrueDetractor); //Cantidad de argumentos válidos.

		if ((((vArguments == 4) && germanTheTrueDetractor.mode == mode1)) || ((vArguments == 3) && germanTheTrueDetractor.robots == 0)) 
			{
		       printf("Height: %d \nWidth = %d \nNumber of robots = %d \nMode: %d", germanTheTrueDetractor.height, germanTheTrueDetractor.width, germanTheTrueDetractor.robots, germanTheTrueDetractor.mode);
		
			/*if (germanTheTrueDetractor.mode == mode1)
			{
				simulacion Simulate;
				Simulate.create(germanTheTrueDetractor.robots, germanTheTrueDetractor.height, germanTheTrueDetractor.width, germanTheTrueDetractor.mode);
				Simulate.run(germanTheTrueDetractor.robots, germanTheTrueDetractor.height, germanTheTrueDetractor.width, germanTheTrueDetractor.mode);

			Simulate.destroy();
			}*/
			if(1)
			{
				simulacion Simulate;
				double tickMedio[MAX_ROBS_PERMITIDOS] = {};

				for (int i = 1; (i < MAX_ROBS_PERMITIDOS) &&   ((tickMedio[i] - tickMedio[i - 1]) < 0.1) ; i++)
				{	
					double sum = 0.0;

					for (int countsum = 0; countsum < 1000; countsum++)
					{

						Simulate.create(germanTheTrueDetractor.robots, germanTheTrueDetractor.height, germanTheTrueDetractor.width, mode2);
						sum += Simulate.run(germanTheTrueDetractor.robots, germanTheTrueDetractor.height, germanTheTrueDetractor.width, germanTheTrueDetractor.mode);
						Simulate.destroy();
					}
					tickMedio[i - 1] = sum / 1000;
					printf("%f", sum);
				}
				//histograma(tickMedio, i);
			}
		
		
		}
		else {
			cout << "Please check your input.\n" << endl;
			cout << "The valid inputs are:\n" << endl;
			cout << "-Height (1-100)" << endl;
			cout << "-Width (1-70)" << endl;
			cout << "-Robots (Any positive number greater than 0)" << endl;
			cout << "-Mode (1 or 2. Mode 1 runs a graphical simulation. Mode 2 runs multiple simulations and show a graph at the end." << endl;
			cout << "Should you choose Mode 2, inputting the number of robots is not necessary.)\n" << endl;
			cout << "Press any key to end the program." << endl;
		}

		
		getchar(); //Este getchar borrenlo antes de entregar, es para ver que imprime el programa.
		void allegro_shut_down(void);

		return 0;
	}