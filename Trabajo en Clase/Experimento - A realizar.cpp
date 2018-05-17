/*************************************************

	Algoritmos y Estructura de Datos
H	echo por Hernández Hernández Franco Salvador

*************************************************/

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
#include "Clases.h"
#include "Funciones.h"

int main() {
	do {
		system("CLS");
		gotoxy(35, 1); cout << "/****************************************";
		gotoxy(35, 2); cout << "DESCRIPCI\340N:";
		gotoxy(40, 3); cout << "En cada opci\242n se encuentra";
		gotoxy(40, 4); cout << "un programa diferente visto en la";
		gotoxy(40, 5); cout << "materia de Algoritmos y Estructura";
		gotoxy(40, 6); cout << "de Datos.";
		gotoxy(35, 7); cout << "****************************************/";
		gotoxy(0, 0);
		// Aquí se encuentra el primer menú, el principal.
		switch (MenuPrincipal()) {
		case 1:
			// Este caso pude un número en el rango de 10 a 20.

			Rango();
			break;
		case 2:
			IMSS();
			break;
		case 3:
			SerieI();
			break;
		case 4:
			SerieII();
			break;
		case 5:
			Triangulo();
			break;
		case 6:
			Sueldo();
			break;
		case 7:
			Costo();
			break;
		case 8:
			Clases();
			break;
		case 9:
			break;
		default:
			system("CLS");
			cout << "\n  Opci\242n no v\240lida." << endl;
		}
	} while (ReturnMenu("volver al men\243 principal") != 'N');
	system("CLS");
	return 0;
}

