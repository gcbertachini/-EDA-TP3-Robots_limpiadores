//#include "allegroInit.h"
#include "parseCmdLine.h"
#include <iostream>

using namespace std;

	int main(int argc, char * argv[]) {

		parameters_t germanTheTrueDetractor = { 0 };

		germanTheTrueDetractor.options[0] = { "height" }; //Esto iría en el constructor que no pude hacer porque soy useless
		germanTheTrueDetractor.options[1] = { "width" };
		germanTheTrueDetractor.options[2] = { "robots" };
		germanTheTrueDetractor.options[3] = { "mode" };

		int vArguments = parseCmdLine(argc, argv, parseCallback, &germanTheTrueDetractor); //Cantidad de argumentos válidos.

		/*Si es modo 1, obligatoriamente debe haber 4 argumentos. Si es modo 2, puede haber 3 argumentos, pero el único faltante
		puede ser robots. Se verifica si el valor de robots es 0 pues es el valor por defecto y no puede ser ingresado
		como parámetro.*/

		if ((vArguments == 4) || ((germanTheTrueDetractor.mode == mode2) && (vArguments == 3) && germanTheTrueDetractor.robots == 0)) {
		printf("Height: %d \nWidth = %d \nNumber of robots = %d \nMode: %d", germanTheTrueDetractor.height, germanTheTrueDetractor.width, germanTheTrueDetractor.robots, germanTheTrueDetractor.mode);
		//Este printf es para poder verificar el funcionamiento del parser. Se los dejé por si lo quieren probar un poco.
		/* Aca iría el resto del main porque ya verificamos que el input es válido y entonces se puede operar correctamente.*/
		
		
		
		
		
		}
		else {
			cout << "Please check your input.\n" << endl;
			cout << "The valid inputs are:\n" << endl;
			cout << "-Height (1-100)\n" << endl;
			cout << "-Width (1-70)\n" << endl;
			cout << "-Robots (Any positive number greater than 0)\n" << endl;
			cout << "-Mode (1 or 2. Mode 1 runs a graphical simulation. Mode 2 runs multiple simulations and show a graph at the end.\n" << endl;
			cout << "Should you choose Mode 2, inputting the number of robots is not necessary.)" << endl;
		}
		
		getchar(); //Este getchar borrenlo antes de entregar, es para ver que imprime el programa.
		return 0;
	}