#include <iostream>
#include <string>
#include <conio.h> //sirve para habilitar el getch para mostrar el password con asteriscos
#include <ctime>
#include <random>
#include <deque>
#include <windows.h>
using namespace std;
#include "Clase.h"
#include "Lista.h"
Lista L1;
#include "Funciones.h"

int main()
{
	PRESENTACION();
	if (LOGIN());
	do
	{
		switch (menu())
		{
		case 'a':
			Edwin();
			break;
		case 'b':
			Oscar();
			break;
		case 'c':
			Franco();
			break;
		case 'd':
			break;
		default:
			cout << " Opci\242n no v\240lida." << endl;
		}
	} while (ReturnMenu("volver al men\243 principal") != 'N');
	return 0;
}