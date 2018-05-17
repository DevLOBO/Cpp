/******************************************
	CÓDIGO PROTEGIDO CON SISTEMA "ANTI-BARAJAS"
	FRANCO SALVADOR HERNÁNDEZ HERNÁNDEZ
	ALGORITMOS Y ESTRUCTURA DE DATOS

******************************************/

#include <iostream>
#include <string>
using namespace std;

// DECLARACIÓN DE ESTRUCTURAS
struct Alumno {
	string nombre;
	float calificacion;
};
struct Sobresaliente {
	string nombre;
	Sobresaliente *siguiente;
};

// USO GENERAL
bool SoN(string, string);
int MenuPrincipal();
char ReturnMenu(string);

// CASO 1: CALIFICACIÓN MAYOR
void Alumnos(), CalificacionMayor(Alumno[], int, float);

// CASO 2: ESTACIONES
void Estaciones();
string MesEstacion(int, string);

// CASO 3: ARITMÉTICA
void Aritmetica(), Operaciones(float, float);

// CASO 4: PARALELOGRAMO
void Paralelogramo(), Dibujar(int, int, string);

// CASO 5: CONTAR NÚMEROS
void ContarNumeros();

// CASO 6: VOCAL O CONSONANTE
void VoC();
bool ValidarChar(string);

// CASO 7: VARIOS
char MenuVarios();
void Esfera(float), Factorial(int), Varios(), Esfera(), Factorial();

// CASO 8: VARIOS II
char MenuVariosII(), MenuCalculadora();
void VariosII(), Ventas(), Circulo(), Calculadora();

// He reutilizado muchas de las funciones de programas anteriores. Como el de Ventas(), SoN(), los menús, y Calificación.
// Aunque CalificaciónMayor, es un caso especial, pues la modifiqué para utilizase estructuras de datos.
int main() {
	do {
		system("CLS");
		switch (MenuPrincipal()) {
		case 1:
			Alumnos();
			break;
		case 2:
			Estaciones();
			break;
		case 3:
			Aritmetica();
			break;
		case 4:
			Paralelogramo();
			break;
		case 5:
			ContarNumeros();
			break;
		case 6:
			VoC();
			break;
		case 7:
			Varios();
			break;
		case 8:
			VariosII();
			break;
		case 9:
			break;
		default:
			cout << "\n  Opci\242n no v\240lida." << endl;
		}
	}while (ReturnMenu("volver al men\243 principal") == 'S');
	return 0;
}

// FUNCIONES USO GENERAL
bool SoN(string B, string C) {
	// Esta función compara dos cadenas para después devolver un valor booleano
	// El nombre se esta función hace referenci a "Sí o No" (true or false)

	// Convierte carácter por carácter a mayúscula, para después compararlos.
	for (int x = 0; x < B.length(); x++)
		B[x] = toupper(B[x]);

	for (int u = 0; u < C.length(); u++)
		C[u] = toupper(C[u]);

	if (B == C)
		return true;
	else
		return false;
}
int MenuPrincipal() {
	string n = "";

	cout << "\n  BIENVENIDO AL MEN\351 PRINCIPAL";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  1) CALIFICACI\340N";
	cout << "\n  2) ESTACIONES";
	cout << "\n  3) ARITMETICA";
	cout << "\n  4) PARALELOGRAMO";
	cout << "\n  5) CONTAR N\351MEROS";
	cout << "\n  6) VOCAL O CONSONANTE";
	cout << "\n  7) VARIOS I";
	cout << "\n  8) Vario II";
	cout << "\n  9) Salir";
	cout << "\n  \250Qu\202 quieres hacer? ";
	getline(cin, n);
	return atoi(n.c_str());
}
char ReturnMenu(string P) {
	// Pregunta si desea volver al menú.

	string c = "";
	char r;

	do {
		cout << "\n  \250Quieres " << P << "? [S/N] ";
		getline(cin, c);
		r = toupper(c[0]);
		if (r != 'S' && r != 'N')
			cout << "  Car\240cter no v\240lido. Ingrese solamente S \243 N." << endl;
	} while (r != 'S' && r != 'N');
	return r;
}

// FUNCIONES CALIFICACIÓN
void Alumnos() {
	Alumno *Alumnos;
	int tam = 0;
	string entrada = "", n = "", num = "";
	float t = 0.0, mayor = 0;
	bool indicador = false;
	// Las variables n, num, entrada y t; sólo son de trabajo. No tienen un significado relevante.

	do {
		system("CLS");

		cout << "\n  \250Cu\240ntos alumnos ingresar\240? ";
		getline(cin, entrada);
		// Se relizan los filtros pertinentes para datos entrantes no deseados.
		if (entrada != "0") {
			tam = atoi(entrada.c_str());
			if (tam == 0)
				cout << "  No se aceptan letras." << endl;
			else if (tam > 21)
				cout << "  Ingrese valores entre 1 y 20." << endl;
			else if (tam > 1 && tam <= 20) { // Rango aceptado de alumnos.
				// Se declara el arreglo dinámico
				Alumnos = new Alumno[tam];

				for (int b = 0; b < tam; b++) {
					do {
						system("CLS");
						cout << "\n       Alumno " << b + 1;
						cout << "\n  =========================";
						cout << "\n  Nombre: ";
						getline(cin, n);
						if (n == "0" || atoi(n.c_str()) != 0) {
							cout << "  No ha ingresado letras. Int\202ntelo de nuevo." << endl;
							system("PAUSE > NULL");
						}
						// Verifica que no hay un nombre similar ya ingresado previamente.
						for (int i = 0; i < tam; i++)
							if (SoN(Alumnos[i].nombre, n)) {
								cout << "  Ya hay un alumno con el mismo nombre." << endl;
								system("PAUSE > NULL");
								indicador = true;
								break;
							}
							else
								indicador = false;
					} while (atoi(n.c_str()) != 0 || n == "0" || indicador);
					do {
						cout << "  Calificaci\242n: ";
						getline(cin, num);
						if (num.length() <= 5) {
							t = atof(num.c_str());
							if (t < 0)
								cout << "  No hay calificaciones negativas." << endl;
							else if (t == 0)
								cout << "  No se admiten letras." << endl;
							else if (t > 10)
								cout << "  No hay calificaciones mayores a 10." << endl;
						}
						else
							cout << "  La calificaci\242n m\240xima es 10. De ota manera, ingrese un d\241gito y dos decimales.\n  Ejemplo: 7.25" << endl;
					} while (num.length() > 5 || t < 0 || t == 0 || t > 10);
					// Al terminar los filtros. Se afirma que los datos son correctos y son asignaos a la posición correspondiente en los arreglos.
					Alumnos[b].nombre = n;
					Alumnos[b].calificacion = t;

					// Compara las calificaciones hasta encontrar la mayor.
					if (mayor < Alumnos[b].calificacion)
						mayor = Alumnos[b].calificacion;
				}
				// Se llama a la función para mostrar lo(s) alumno(s) con la calificación más alta.
				CalificacionMayor(Alumnos, tam, mayor);
				delete[] Alumnos; 
				// Libera la memoria reservada para este arreglo dinámico
			}
			else if (tam == 1) {
				do {
					system("CLS");
					cout << "\n       Alumno 1";
					cout << "\n  =========================";
					cout << "\n  Nombre: ";
					getline(cin, n);
					if (n == "0" || atoi(n.c_str()) != 0) {
						cout << "  No ha ingresado letras. Int\202ntelo de nuevo." << endl;
						system("PAUSE > NULL");
					}
				} while (atoi(n.c_str()) != 0 || n == "0");
				do {
					cout << "  Calificaci\242n: ";
					getline(cin, num);
					if (num.length() <= 5) {
						t = atof(num.c_str());
						if (t < 0)
							cout << "  No hay calificaciones negativas." << endl;
						else if (t == 0)
							cout << "  No se admiten letras." << endl;
						else if (t > 10)
							cout << "  No se admiten valores menores a $1,000 \242 mayores a $100,000." << endl;
					}
					else
						cout << "  La calificaci\242n m\240xima es 10. De otra forma, ingrese un d\241gito y dos decimales: 7.25" << endl;
				} while (num.length() > 5 || t < 0 || t == 0 || t > 10);
				system("CLS");
				cout << "\n  Como es el \243nico alumno ingresado...";
				cout << "\n\tNombre: " << n;
				cout << "\n\tCalificaci\242n: " << t << endl;
			}
			else
				cout << "  No se permiten valores negativos." << endl;
		}
		else
			cout << "  Como ha ingresado 0, no se puede proseguir con el proceso. Por tanto, aqu\241 finaliza." << endl;
	} while (ReturnMenu("ingresar otro valor") != 'N');
}
void CalificacionMayor(Alumno A[], int tam, float mayor) {
	// Se declaran los punteros correspondientes para la Pila "Sobresaliente".
	Sobresaliente *Pila = NULL, *Nuevo;

	for (int r = 0; r < tam; r++)
		if (mayor == A[r].calificacion) {
			Nuevo = new Sobresaliente();
			Nuevo->siguiente = Pila;
			Nuevo->nombre = A[r].nombre;
			Pila = Nuevo;
		}

	system("CLS");

	/**************************************************************
	En caso de sólo hubo una calificación mayor, la Pila no está vacía,
	por loq eu su segundo miembro (Nuevo) es NULL, ó, Pila->siguiente.
	Según esta convención, se realizan las condiciones pertinentes
	para mostrar el(los) alumno(s).
	**************************************************************/

	if (Pila->siguiente == NULL) {
		cout << "\n  La calificaci\242n mayor fue:" << endl;
		cout << "\tNombre: " << Pila->nombre << endl;
		cout << "\tCalificaci\242n: " << mayor << endl;
	}
	else {
		cout << "\n  Hay m\240s de un alumno con la calificaci\242n mayor:" << endl;
		cout << "\tCalificaci\242n: " << mayor << endl;
		cout << "\tAlumnos: ";
		// Se sacan todos los elementos de la Pila.
		while (Pila != NULL) {
			if (Pila->siguiente != NULL)
				cout << Pila->nombre << ", ";
			else
				cout << Pila->nombre << ".";
			Pila = Pila->siguiente;
		}
	}
	cout << endl;
}

// FUNCIONES DE ESTACIONES
void Estaciones() {
	int dia = 0;
	bool indicador = false;
	string d = "", m = "", Estacion = "";

	do {
		system("CLS");
		do {
			cout << "\n  Ingrese el mes: ";
			getline(cin, m);
			// Filtros
			if (m == "0" || atoi(m.c_str()) != 0)
				cout << "  No se admiten n\243meros." << endl;
			else if (SoN(m, "ENERO") || SoN(m, "FEBRERO") || SoN(m, "MARZO") || SoN(m, "ABRIL") || SoN(m, "MAYO") || SoN(m, "JUNIO") || SoN(m, "JULIO") || SoN(m, "AGOSTO") || SoN(m, "SEPTIEMBRE") || SoN(m, "OCTUBRE") || SoN(m, "NOVIEMBRE") || SoN(m, "DICIEMBRE"))
				indicador = false;
			else {
				cout << "  El mes escrito no existe." << endl;
				indicador = true;
			}
		} while (m == "0" || atoi(m.c_str()) != 0 || indicador);
		system("CLS");
		do {
			indicador = false;
			cout << "\n  Ingrese el d\241a: ";
			getline(cin, d);
			dia = atoi(d.c_str());
			// Filtros
			if (d == "0")
				cout << "  Este d\241a no existe en el calendario." << endl;
			else if (dia == 0)
				cout << "  No se admiten letrs." << endl;
			else if (dia < 1 || dia > 31)
				cout << "  Este d\241a no existe." << endl;
			else {
				// Filtros para evitar una fecha irreal como 31 de Febrero.
				if (SoN(m, "FEBRERO") && dia > 29) {
					cout << "  El d\241 no concuerda con este mes." << endl;
					indicador = true;
				}
				else if ((SoN(m, "ABRIL") || SoN(m, "JUNIO") || SoN(m, "SEPTIEMBRE") || SoN(m, "NOVIEMBRE")) && dia == 31) {
					cout << "  Este d\241a no concuerda con este mes." << endl;
					indicador = true;
				}
			}
		} while (d == "0" || dia == 0 || dia < 1 || dia > 31 || indicador);

		system("CLS");
		// Con ayuda de la función, se determina la estación del año, según su fecha.
		Estacion = MesEstacion(dia, m);
		cout << "\n  " << dia << " de " << m << ". Estaci\242n: " << Estacion << endl;

	} while (ReturnMenu("introducir otra fecha") != 'N');
}
string MesEstacion(int dia, string mes) {
	// Devolverá la estación correspondiente a la fecha.
	// Con un montón de condiciones lógicas.
	if ((SoN(mes, "MARZO")) && dia >= 21 || SoN(mes, "JUNIO") && dia <= 19 || (SoN(mes, "ABRIL") || SoN(mes, "MAYO")) && dia >= 1)
		return "PRIMAVERA";
	else if ((dia >= 20 && SoN(mes, "JUNIO")) || (dia <= 22 && SoN(mes, "SEPTIEMBRE")) || ((SoN(mes, "JULIO") || SoN(mes, "AGOSTO")) && dia >= 1))
		return "VERANO";
	else if ((dia >= 23 && SoN(mes, "SEPTIEMBRE")) || (dia <= 19 && SoN(mes, "DICIEMBRE")) || (dia >= 1 && (SoN(mes, "OCTUBRE") || SoN(mes, "NOVIEMBRE"))))
		return "OTO\245O";
	else // En las fechas proporcionadas en el archivo, se mencionó que INVIERNO empieza el 21 de Diciembre, no obstante, habría un día sin llenar; así que he abarcado desde el 20 de diciembre hasta el 20 de marzo.
		return "INVIERNO";
}

// FUNCIONES DE ARITMÉTICA
void Aritmetica() {
	float num1 = 0.0, num2 = 0.0;
	string entrada = "";
	bool indicador = false;

	do {
		system("CLS");
		do {
			cout << "\n  Introduce un n\243mero: ";
			getline(cin, entrada);
			if (entrada != "0") {
				if (atoi(entrada.c_str()) == 0) {
					cout << "  No se admiten letras." << endl;
					indicador = true;
				}
			}
			else
				indicador = false;
		} while (indicador);
		num1 = atoi(entrada.c_str());
		system("CLS");
		do {
			cout << "\n  Introduce otro n\243mero: ";
			getline(cin, entrada);
			if (entrada != "0") {
				if (atoi(entrada.c_str()) == 0) {
					cout << "  No se admiten letras." << endl;
					indicador = true;
				}
			}
			else
				indicador = false;
		} while (indicador);
		num2 = atoi(entrada.c_str());
		// No hay ningún aspecto que no se haya comentado previamente.
		Operaciones(num1, num2);
	} while (ReturnMenu("ingresar otros n\243meros") != 'N');
}
void Operaciones(float n1, float n2) {
	system("CLS");
	// Se aplican las condiciones estipuladas en el documento.
	// No hay nada destacado... Todo normal.
	if (n1 > n2) {
		cout << "\n  Las operaciones son:";
		cout << "\n\t" << n1 << " + " << n2 << " = " << n1 + n2;
		cout << "\n\t" << n1 << " - " << n2 << " = " << n1 - n2 << endl;
	}
	else if (n2 > n1) {
		cout << "\n  Las operaciones son:";
		cout << "\n\t" << n1 << " * " << n2 << " = " << n1 * n2;
		if (n2 == 0)
			cout << "\n\tNo se puede realizar divisiones entre 0." << endl;
		else
			cout << "\n\t" << n1 << " / " << n2 << " = " << n1 / n2 << endl;
	}
	else {
		if (n1 == 0) {
			cout << "\n  Todas las operaciones dan cero." << endl;
			cout << "  Excepto la divisi\242, que es indeterminci\242n matem\240tica." << endl;
		}
		else {
			cout << "\n  Las operaciones son:";
			cout << "\n\t" << n1 << " + " << n2 << " = " << 2 * n1;
			cout << "\n\t" << n1 << " - " << n2 << " = 0";
			cout << "\n\t" << n1 << " * " << n2 << " = " << pow(n1, 2);
			cout << "\n\t" << n1 << " / " << n2 << " = 1" << endl;
		}
	}
}

// FUNCIONES PARALELOGRAMO
void Paralelogramo() {
	string c = "", f = "", car = "";
	int col = 0, fila = 0;

	do {
		// Se aplican los filtros para los tres datos necesarios.
		system("CLS");
		cout << "\n  Introduzca el n\243mero de filas: ";
		do {
			try {
				getline(cin, f);
				fila = atoi(f.c_str());
				if (f == "0")
					throw f;
				else if (fila == 0 || fila < 0)
					throw fila;
			}
			catch (string f) {
				cout << "  No se puede dibujar un paralelogramo con 0 filas." << endl;
				cout << "\n  Introduzca otro valor: ";
				continue;
			}
			catch(int f) {
				if (f == 0)
					cout << "  No se admiten letras." << endl;
				else if (f < 0)
					cout << "  No se permiten valores negativos." << endl;
				cout << "\n  Introduzca otro valor: ";
				continue;
			}
		} while (fila == 0 || fila < 0 || f == "0");
		system("CLS");
		cout << "\n  Introduzca el n\243mero de columnas: ";
		do {
			try {
				getline(cin, c);
				col = atoi(c.c_str());
				if (c == "0")
					throw c;
				else if (col < 0 || col == 0)
					throw col;
			}
			catch (string c) {
				cout << "  No se puede dibujar un paralelogramo con 0 columnas." << endl;
				cout << "\n  INtroduzca otro valor: ";
				continue;
			}
			catch (int c) {
				if (c < 0)
					cout << "  No se permiten valores negativos." << endl;
				else if (c == 0)
					cout << "  No se permiten letras." << endl;
				cout << "\n  Introduzca otro valor: ";
				continue;
			}
		} while (c == "0" || col == 0 || col < 0);
		system("CLS");
		cout << "\n  Se tomar\240 el primer car\240ter que ingrese, no importa si es n\243mero, letra o car\240ter especial." << endl;
		cout << "\n  Introduzca un car\240cter: ";
		getline(cin, car);
		Dibujar(fila, col, car);
	} while (ReturnMenu("ingresar otros datos") != 'N');
}
void Dibujar(int filas, int columnas, string caracter) {
	system("CLS");
	cout << endl;
	// Con los tres datos recogidos de la función llamadora, se dibuja el paalelogramo.
	for (int f = 1; f <= filas; f++) {
		cout << "  ";
		for (int c = 1; c <= columnas; c++)
			cout << caracter[0];
		cout << endl;
	}
}

// FUNCIÓN CONTAR NÚMEROS
void ContarNumeros() {
	string num = "";
	int n = 0, positivo = 0, negativo = 0, suma = 0;

	// Otro código convencial que muestra un contador de números positivos y negativos.
	// Actualizándose conforme se ingresan los números.
	do {
		system("CLS");
		cout << "\n  N\243meros positivos: " << positivo;
		cout << "\t\tN\243meros negativos: " << negativo << endl;
		cout << "\n  Para salir de este men\243, introduzca un 0." << endl;
		cout << "\n  Introduzca un n\243mero: ";
		getline(cin, num);
		if (num != "0") {
			n = atoi(num.c_str());
			if (n == 0) {
				cout << "  No se admiten letras o car\240cteres especiales.";
				system("PAUSE > NULL");
			}
			else
				if (n > 0) {
					positivo++;
					suma += n;
				}
				else {
					negativo++;
					suma += n;
				}
		}
	} while (num != "0" || n == 0);
	cout << "\n  El resultado del total es: " << suma << endl;
}

// FUNCIONES VOCAL O CONSONANTE
void VoC() {
	string caracter = "";

	// No importa lo que introduzca el usuario, sólo se admitirán letras.
	do {
		do {
			system("CLS");
			cout << "\n  Introduzca una letra: ";
			getline(cin, caracter);
			if (caracter == "0" || atoi(caracter.c_str())) {
				cout << "  No se admiten n\243meros." << endl;
				system("PAUSE > NULL");
			}
		} while (caracter == "0" || atoi(caracter.c_str()) != 0 || toupper(caracter[0]) < 'A' || toupper(caracter[0]) > 'Z');
		if (ValidarChar(caracter))
			cout << "  Es una vocal." << endl;
		else
			cout << "  Es una consonante." << endl;
	} while (ReturnMenu("introducir otra letra") != 'N');
}
bool ValidarChar(string letra) {
	// Devuelve true, si es vocal; y false, si es consonante.
	if (toupper(letra[0]) != 'A' && toupper(letra[0]) != 'E' && toupper(letra[0]) != 'I' && toupper(letra[0]) != 'O' && toupper(letra[0]) != 'U')
		return false;
	else
		return true;
}

// FUNCIONES VARIOS
char MenuVarios() {
	string opc = "";
	system("CLS");

	cout << "\n  BIENVENIDO AL MEN\351 DE VARIOS";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  A) Vol\243men de una esfera";
	cout << "\n  B) Factorial de un n\243mero";
	cout << "\n  C) Volver al men\243 principal";
	cout << "\n  \250Qu\202 qyuere gacer? ";
	getline(cin, opc);
	return toupper(opc[0]);
}
void Varios() {
	// Sobrecargué las os funciones (Factorial y Esfera), pues tienen relación entre sí.
	// Una es la función llamadora, mientras que la otra, es la que hace los cálculos.
	do {
		switch (MenuVarios()) {
			case 'A':
				Esfera();
				break;
			case 'B':
				Factorial();
				break;
			case 'C':
				break;
			default:
				cout << "\n  Opci\242n no v\240lida." << endl;
		}
	} while (ReturnMenu("volver a mostrar el men\243 VARIOS") != 'N');
}
// En mi parecer, no hay mucho que comentar en las funciones siguientes...
void Factorial() {
	string numero = "";
	int num;

	do {
		system("CLS");

		do {
			cout << "\n  Ingrese un n\243mero entero positivo: ";
			getline(cin, numero);
			if (numero != "0"){
				num = atoi(numero.c_str());
				if (num == 0)
					cout << "  No se permiten letras u otros car\240cteres." << endl;
				else if (num < 0)
					cout << "  No se permiten valores negativos. No hay factorial para esos n\243meros." << endl;
			}
			else {
				cout << "  El factorial de 0! = 1." << endl;
				break;
			}
		} while (num == 0 || num < 0);
		if (numero != "0")
			Factorial(num);
	} while (ReturnMenu("ingresar otro valor") != 'N');
}
void Factorial(int n) {
	double producto = 1;

	cout << "  El factorial de " << n << " es:\n  ";
	for (int factorial = n; factorial >= 1; factorial--) {
		if (factorial != 1)
			cout << factorial << " \56 ";
		else
			cout << factorial;
		producto *= factorial;
	}
	cout << " = " << producto << endl;
}
void Esfera() {
	float r = 0.0;
	string radio = "";

	do {
		system("CLS");
		do {
			cout << "\n  Ingresa el valor del radio: ";
			getline(cin, radio);
			if (radio != "0") {
				r = atoi(radio.c_str());
				if (r == 0)
					cout << "  No se admiten letras u otros car\240cteres especiales." << endl;
				else if (r < 0)
					cout << "  No se permiten valores negativos." << endl;
			}
			else {
				cout << "  El volumen con radio 0 es 0." << endl;
				break;
			}
		} while (r == 0 || r < 0);
		if (radio != "0")
			Esfera(r);
	} while (ReturnMenu("ingresar otro valor") != 'N');
}
void Esfera(float r) {
	cout << "  El volumen de la esfera es: " << double(4 * 3.1416 * pow(r, 3) / 3) << endl;
}

// FUNCIONES DE VARIOS II
char MenuVariosII() {
	string opc = "";
	system("CLS");

	cout << "\n  BIENVENIDO AL MEN\351 DE VARIOS II";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  A) \365rea y circunferencia";
	cout << "\n  B) Ventas";
	cout << "\n  C) Calculadora b\240sica";
	cout << "\n  D) Volver al men\243 principal";
	cout << "\n  \250Qu\202 qyuere gacer? ";
	getline(cin, opc);
	return toupper(opc[0]);
}
void VariosII() {
	do {
		switch (MenuVariosII()) {
			case 'A':
				Circulo();
				break;
			case 'B':
				Ventas();
				break;
			case 'C':
				Calculadora();
				break;
			case 'D':
				break;
			default:
					cout << "\n  Opci\242n no v\240lida." << endl;
		}
	} while (ReturnMenu("volver al men\243 VARIOS II") != 'N');
}
void Circulo() {
	float radio = 0;
	bool indicador = false;
	string n = "";

	do {
		system("CLS");
		do {
			indicador = false;
			cout << "\n  Introduzca el radio: ";
			getline(cin, n);
			if (n == "0") {
				cout << "  El \240rea y circunferencia con radio 0 es: 0" << endl;
				indicador = false;
			}
			else {
				radio = atof(n.c_str());
				if (radio < 0) {
					cout << "  No se admiten valores negativos." << endl;
					indicador = true;
				}
				else if (radio == 0) {
					cout << "  No se admiten letras." << endl;
					indicador = true;
				}
			}
		} while (indicador);

		system("CLS");
		cout << "\n  El \240rea es: " << 3.1416 * pow(radio, 2) << " unidades cuadradas";
		cout << "\n  La circunferenci es: " << 2 * 3.1416 * radio << " unidades" << endl;

	} while (ReturnMenu("ingresar otro valor") != 'N');
}
void Ventas() {
	int tam = 12;
	bool indicador = false;
	string n = "", num = "";
	float t = 0.0, suma = 0.0, Venta_Mes[12];

	do {
		system("CLS");
		do {
			cout << "\n  Nombre del vendedor: ";
			getline(cin, n);

			if (n == "0")
				cout << "  No ha ingresado letras. Int\202ntelo de nuevo." << endl;
			else
				if (atoi(n.c_str()) != 0)
					cout << "  No ha ingresado letras. Int\202ntelo de nuevo." << endl;
		} while (atoi(n.c_str()) != 0 || n == "0");

		for (int b = 0; b < tam; b++) {
			system("CLS");
			cout << "\n       Mes " << b + 1;
			cout << "\n  =========================";
			do {
				cout << "\n  Vendido: $";
				getline(cin, num);
				if (num == "0")
					cout << "  No se admiten valores menores de $1,000 \242 mayores a $100,000." << endl;
				else {
					if (num.length() <= 9) {
						t = atof(num.c_str());
						if (t < 0)
							cout << "  No hay ventas negativas." << endl;
						else if (t == 0)
							cout << "  No se admiten letras." << endl;
						else if (t < 1000 || t > 100000)
							cout << "  No se admiten valores menores a $1,000 \242 mayores a $100,000." << endl;
					}
					else {
						cout << "  La cantidad vendida debe tener m\240ximo 8 d\241gitos -contando con dos decimales-." << endl;
						cout << "  Ejemplo: $45725.50" << endl;
					}
				}
				for (int d = 0; d < tam; d++)
					if (Venta_Mes[d] == t) {
						indicador = true;
						cout << "  Ingrese otro valor, no puede repetirse." << endl;
						break;
					}
					else
						indicador = false;
			} while (num == "0" || num.length() > 9 || t == 0 || indicador || t < 1000 || t > 100000);
			Venta_Mes[b] = t;
			system("CLS");
		}
		system("CLS");
		cout << "\n  A continuaci\242n se mostrar\240n las ventas obtenidas por:" << n << endl;
		for (int i = 0; i < tam; i++) {
			cout << "\n  Mes " << i + 1 << ": $" << Venta_Mes[i];
			suma += Venta_Mes[i];
		}
		cout << "\n\n  La venta anual es de: %" << suma << endl;
	} while (ReturnMenu("ingresar otro vendedor") != 'N');
}
void Calculadora() {
	bool indicador = false;
	string numero = "", numero2 = "";
	int n = 0;
	float operacion = 0.0, num = 0.0, producto = 1.0, num2 = 0.0;
	do {
		switch (MenuCalculadora()) {
			case '+':
				do {
					indicador = false;
					system("CLS");
					cout << "\n  \250Cu\240ntos n\243meros sumar\240? ";
					getline(cin, numero);
					if (numero != "0") {
						n = atoi(numero.c_str());
						if (n < 0) {
							cout << "  No se permiten valores negativos." << endl;
							indicador = true;
						}
						else if (n == 0) {
							cout << "  No se admiten letras." << endl;
							indicador = true;
						}
					}
					else
						indicador = false;
				} while (indicador);

				for (int j = 1; j <= n; j++) {
					do {
						system("CLS");
						cout << "\n  Introduzca un n\243mero: ";
						getline(cin, numero);
						if (numero != "0") {
							num = atof(numero.c_str());
							if (num == 0) {
								cout << "  No se permiten letras." << endl;
								indicador = true;
							}
						}
						else
							indicador = false;
					} while (indicador);
					operacion += num;
				}
				system("CLS");
				cout << "\n  La suma total es: " << operacion << endl;
				break;
			case '-':
				do {
					indicador = false;
					system("CLS");
					cout << "\n  \250Cu\240ntos n\243meros restar\240? ";
					getline(cin, numero);
					if (numero != "0") {
						n = atoi(numero.c_str());
						if (n < 0) {
							cout << "  No se permiten valores negativos." << endl;
							indicador = true;
						}
						else if (n == 0) {
							cout << "  No se admiten letras." << endl;
							indicador = true;
						}
					}
					else
						indicador = false;
				} while (indicador);

				for (int j = 1; j <= n; j++) {
					do {
						system("CLS");
						cout << "\n  Introduzca un n\243mero: ";
						getline(cin, numero);
						if (numero != "0") {
							num = atof(numero.c_str());
							if (num == 0) {
								cout << "  No se permiten letras." << endl;
								indicador = true;
							}
						}
						else
							indicador = false;
					} while (indicador);
					operacion -= num;
				}
				system("CLS");
				cout << "\n  La resta total es: " << operacion << endl;

				break;
			case '*':
				do {
					indicador = false;
					system("CLS");
					cout << "\n  \250Cu\240ntos n\243meros multiplicar\240? ";
					getline(cin, numero);
					if (numero != "0") {
						n = atoi(numero.c_str());
						if (n < 0) {
							cout << "  No se permiten valores negativos." << endl;
							indicador = true;
						}
						else if (n == 0) {
							cout << "  No se admiten letras." << endl;
							indicador = true;
						}
					}
					else
						indicador = false;
				} while (indicador);

				for (int j = 1; j <= n; j++) {
					do {
						system("CLS");
						cout << "\n  Introduzca un n\243mero: ";
						getline(cin, numero);
						if (numero != "0") {
							num = atof(numero.c_str());
							if (num == 0) {
								cout << "  No se permiten letras." << endl;
								indicador = true;
							}
						}
						else
							indicador = false;
					} while (indicador);
					producto *= num;
				}
				system("CLS");
				cout << "\n  El producto total es: " << producto << endl;
				break;
			case '/':
				do {
					indicador = false;
					system("CLS");
					cout << "\n  Ingrese un n\243merp: ";
					getline(cin, numero);
					if (numero != "0") {
						num = atof(numero.c_str());
						if (num == 0) {
							cout << "  No se admiten letras." << endl;
							indicador = false;
						}
					}
					else
						indicador = false;
				} while (indicador);
				do {
					indicador = false;
					system("CLS");
					cout << "\n  Ingrese otro n\243merp: ";
					getline(cin, numero2);
					if (numero2 != "0") {
						num2 = atof(numero2.c_str());
						if (num2 == 0) {
							cout << "  No se admiten letras." << endl;
							indicador = false;
						}
					}
					else {
						cout << "  No se puede realizar una divisi\242n entre 0." << endl;
						indicador = false;
					}
				} while (indicador);
				if (num2 != 0) {
					system("CLS");
					cout << "\n  La divisi\242n es: " << num / num2 << endl;
				}

				break;
			default:
				cout << "\n  Operaci\242n no v\240lida." << endl;
		}
	} while (ReturnMenu("hacer otra operaci\242n") != 'N');
}
char MenuCalculadora() {
	string opc = "";
	system("CLS");

	cout << "\n  BIENVENIDO AL MEN\351 DE VARIOS II";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  +) Suma";
	cout << "\n  -) Resta";
	cout << "\n  *) Producto";
	cout << "\n  /) Divisi\242n";
	cout << "\n  \250Qu\202 qyuere gacer? ";
	getline(cin, opc);
	return opc[0];
}

/***********************************************************************
	Como se pudo observar, en cada caso, utilicé una función general,
	que englobase a los procedimientos y las demás funciones. Con el
	fil de que si y sólo si, se ingresa a ese caso, aplicar la memoria
	necesaria para ésas variables locales; O esa fue la idea...
***********************************************************************/