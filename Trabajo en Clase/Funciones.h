//Estructuras
struct MedicamentosPropios {
	string nombre = "";
	int valor;
};
struct MedicamentosGenericos {
	string nombre = "";
	int valor;
};

// Funciones de Uso General
bool SoN(string B, string C) {
	// Esta función compara dos cadenas para después devolver un valor booleano.
	// El nombre se esta función hace referenci a "Sí o No" (true or false)

	for (short x = 0; x < B.length(); x++)
		B[x] = toupper(B[x]);

	for (short u = 0; u < C.length(); u++)
		C[u] = toupper(C[u]);

	if (B == C)
		return true;
	else
		return false;
}
void gotoxy(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);
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
int MenuPrincipal() {
	// Muestra el menú principal.

	string n = "";

	cout << "\n  BIENVENIDO AL MEN\351 PRINCIPAL";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  1) DO-WHILE (RANGO)";
	cout << "\n  2) MEN\351 IMSS";
	cout << "\n  3) SERIE I";
	cout << "\n  4) SERIE II";
	cout << "\n  5) TRI\265NGULO";
	cout << "\n  6) SUELDO";
	cout << "\n  7) COSTOS";
	cout << "\n  8) CLASES";
	cout << "\n  9) SALIR";
	cout << "\n  \250Qu\202 quieres hacer? ";
	getline(cin, n);
	return atoi(n.c_str());
}

// Rango DO-WHILE
void Rango() {
	// Repite la función hasta que se introduzca un número dentro del rango de 10 a 20.

	string n = "";

	system("CLS");
	gotoxy(50, 1); cout << "/***********************************";
	gotoxy(50, 2); cout << "DESCRIPCI\340N:";
	gotoxy(55, 3); cout << "Se pde un n\243mero en el";
	gotoxy(55, 4); cout << "rango de 10 a 20.";
	gotoxy(50, 5); cout << "***********************************/";
	gotoxy(0, 0);

	cout << "\n  Ingresa un n\243mero: ";
	do {
		try {
			getline(cin, n);
			if (n == "0")
				throw n;
			else if (atoi(n.c_str()) < 10 || atoi(n.c_str()) > 20)
				throw atoi(n.c_str());
		}
		catch (string n) {
			cout << "  Este n\243mero no est\240 en el rango." << endl;
			cout << "\n  Int\202telo de nuevo: ";
			continue;
		}
		catch (int n) {
			if (n == 0) {
				cout << "  No se admiten valores no num\202ricos." << endl;
				cout << "\n  Int\202telo de nuevo: ";
			}
			else {
				cout << "  Este n\243mero no est\240 dentro del rango." << endl;
				cout << "\n  Int\202telo de nuevo: ";
			}
			continue;
		}
	} while (!(atoi(n.c_str()) >= 10 && atoi(n.c_str()) <= 20));
	cout << "  El n\243mero est\240 dentro del rango." << endl;
}

// Funciones de Menú IMSS
int MenuIMSS() {
	// Muestra el menú del IMSS.
	string n = "";
	system("CLS");

	gotoxy(40, 1); cout << "/****************************************";
	gotoxy(40, 2); cout << "DESCRIPCI\340N:";
	gotoxy(45, 3); cout << "Se puede capturar medicamentos con";
	gotoxy(45, 4); cout << "su n\243mero y nombre, buscarlo por";
	gotoxy(45, 5); cout << "nombre o n\243mero, mostrar todos los";
	gotoxy(45, 6); cout << "medicamentos registrados hasta el";
	gotoxy(45, 7); cout << "momento, o por \243ltimo, eliminar";
	gotoxy(45, 8); cout << "alg\243n medicamento.";
	gotoxy(40, 9); cout << "****************************************/";
	gotoxy(0, 0);

	cout << "\n  BIENVENIDO AL MEN\351 DEL IMSS";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  1) Capturar medicamentos.";
	cout << "\n  2) Buscar medicamentos.";
	cout << "\n  3) Mostrar todo lo capturado.";
	cout << "\n  4) Eliminar un medicamento.";
	cout << "\n  5) Terminar/Salir";
	cout << "\n  \250Qu\202 quiere hacer? ";
	getline(cin, n);
	return atoi(n.c_str());
}
bool Validar() {
	// Función que vlida la contraseña para el acceso al menú del IMSS.

	string p = "";
	int c = 0;
	system("CLS");

	while (c < 3) {
		cout << "\n  Ingresa la contrase\244a para mostrar este men\243: ";
		getline(cin, p);
		if (p != "I.M.S.S.") {
			cout << "  Contrase\244a incorrecta." << endl;
			c++;
		}
		else
			c = 5;
	}

	if (c == 3)
		return false;
	else
		return true;
}
int ValidarBusqueda() {
	// Muestra el menú de búsqueda (por nombre o por número).

	string ayu = "";
	int opc = 0;

	system("CLS");
	cout << "\n  1) Por nombre";
	cout << "\n  2) Por n\243mero" << endl;
	do {
		cout << "\n  \250C\242mo quiere realizar la b\243squeda? [1/2] ";
		getline(cin, ayu);
		if (ayu == "0")
			cout << "  N\243mero no v\240lido. No es una de las opciones." << endl;
		else {
			opc = atoi(ayu.c_str());
			if (opc == 0)
				cout << "  No aceptan otro tipo de valores que no sean num\202ricos." << endl;
			else if (opc != 1 && opc != 2)
				cout << "  Introduzca solamente 1 \242 2. De otra manera, no se aceptar\240n otros valores." << endl;
		}
	} while (opc != 1 && opc != 2 || ayu == "0");
	return opc;
}
void Captura(MedicamentosPropios MP[], MedicamentosGenericos MG[], int &posicionP, int &posicionG) {
	int valor = 0, t = 0;
	string entrada = "", nom = "";
	bool indicador = true;

	do {
		system("CLS");

		/* Para evitar que el usuario introduzca valores no numércios, se utiliza la variable aux para tomar esos valores
		y depués, si son números convertirlos a valores enteros, de lo contrario, serán valores nulos, es decir, 0. Mosterando un mensaje de error. */
		cout << "\n  Para salir de esta opci\242n, introduzca 0." << endl;
		cout << "\n  Ingrese el n\243mero de la patente del medicamento: ";
		getline(cin, entrada);

		if (entrada != "0") {
			valor = atoi(entrada.c_str()); // La función atoi() convierte las cadenas de carácteres a números enteros, si no son números enteros, regresa un valor nulo (0).
			if (valor == 0) {
				cout << "  S\242lo se aceptan n\243meros enteros." << endl;
				system("PAUSE > NULL");
			}
			else {
				if (valor < 0) {
					cout << "  No hay patentes negativas." << endl;
					system("PAUSE > NULL");
				}
				else if (valor >= 1 && valor <= 30000) {
					// Aquí empieza la validación para la captura, evitando capturar medicamentos ya existentes.
					for (short p = 0; p <= posicionP; p++) {
						if (MP[p].valor == valor) {
							cout << "  Esta patente ya existe." << endl;
							system("PAUSE > NULL");
							break;
						}
						else {
							if (posicionP < 500) {
								cout << "  Nombre: ";
								getline(cin, nom);

								for (short v = 0; v <= posicionP; v++)
									if (SoN(MP[v].nombre, nom)) {
										cout << "  Este medicamento ya ha sido registrad con un nombre similar.";
										system("PAUSE > NULL");
										indicador = false;
										break;
									}

								if (indicador) {
									MP[posicionP].nombre = nom;
									MP[posicionP].valor = valor;
									posicionP++;
								}
							}
							else {
								cout << "  Se ha excedido el n\243mero de medicamentos guardados.";
								system("PAUSE > NULL");
							}
							break;
						}
					}

				}
				else if ((valor > 30000 && valor < 31000) || valor > 60000) {
					cout << "  No hay ninguna patente. S\242lo en rangos de 1 a 30,000 \242 30,000 a 60,000" << endl;
					system("PAUSE > NULL");
				}
				else if (valor >= 31000 && valor <= 60000) {
					// Aquí empieza la validación, evitando capturar medicamentos ya registrados.
					for (short q = 0; q <= posicionG; q++) {
						if (MG[q].valor == valor) {
							cout << "  Esta patente ya existe." << endl;
							system("PAUSE > NULL");
							break;
						}
						else {
							if (posicionG < 250) {
								cout << "  Nombre: ";
								getline(cin, nom);

								for (short v = 0; v <= posicionG; v++)
									if (SoN(MG[v].nombre, nom)) {
										cout << "  Este medicamento ya fue registrado con un nombre similar.";
										system("PAUSE > NULL");
										indicador = false;
										break;
									}

								if (indicador) {
									MG[posicionG].nombre = nom;
									MG[posicionG].valor = valor;
									posicionG++;
								}
							}
							else {
								cout << "  Se ha excedido el n\243mero de medicamentos guardados.";
								system("PAUSE > NULL");
							}
							break;
						}
					}

				}
			}
		}
	} while (entrada != "0");

	// Antes de salir de esta opción, se reorganizarán los números de los medicamentos.
	// Se usó ordenamiento por selección -mismo algoritmo en Elimina()-
	for (short n = 0, m = 0; n < posicionP; n++) {
		m = n;
		for (short o = n + 1; o < posicionP; o++)
			if (MP[m].valor < MP[o].valor)
				m = o;
		t = MP[n].valor;
		MP[n].valor = MP[m].valor;
		MP[m].valor = t;

		nom = MP[n].nombre;
		MP[n].nombre = MP[m].nombre;
		MP[m].nombre = nom;
	}

	// Hace lo mismo del for anterior, pero con posicionG.
	for (short n = 0, m = 0; n < posicionG; n++) {
		m = n;
		for (short o = n + 1; o < posicionG; o++)
			if (MG[m].valor < MG[o].valor)
				m = o;
		t = MG[n].valor;
		MG[n].valor = MG[m].valor;
		MG[m].valor = t;

		nom = MG[n].nombre;
		MG[n].nombre = MG[m].nombre;
		MG[m].nombre = nom;
	}

}
void Busca(MedicamentosPropios MP[], MedicamentosGenericos MG[], int &posicionP, int &posicionG) {
	int valor = 0;
	string Buscar = "";
	bool indicador = true;

	// En este caso realizará la búsqueda por nombre o número, dependiendo de lo que el usuario escoja.
	if (ValidarBusqueda() == 1) {
		do {
			// omienza la búsqueda por nombre.
			system("CLS");

			cout << "\n  Para salir de esta opci\242n, introduzca un 0." << endl;
			cout << "\n  Nombre del medicamento: ";
			getline(cin, Buscar);
			if (Buscar != "0") {
				if (atoi(Buscar.c_str()) != 0) {
					cout << "  No se permiten valores num\202ricos." << endl;
					system("PAUSE > NULL");
				}
				else {
					// El ciclo for buscará las coincidencias -si hay- en cada uno de los arreglos.
					for (short k = 0; k < posicionP; k++)
						if (SoN(Buscar, MP[k].nombre)) {
							cout << "  N\243mero " << MP[k].valor << ": " << MP[k].nombre << endl;
							indicador = false;
							break;
						}

					for (short l = 0; l < posicionG; l++)
						if (SoN(Buscar, MG[l].nombre)) {
							cout << "  N\243mero " << MG[l].valor << ": " << MG[l].nombre << endl;
							indicador = false;
							break;
						}

					if (indicador)
						cout << "  No se encontr\242 el medicamento.";
				}
				system("PAUSE > NULL");
			}
		} while (Buscar != "0");
	}
	else {
		// Comienza la búsqueda por número.
		do {
			system("CLS");

			cout << "\n  Para salir de esta opci\242n, introduzca un 0." << endl;
			cout << "\n  Introduzca la patente del medicamento que busca: ";
			getline(cin, Buscar);

			if (Buscar != "0") {
				valor = atoi(Buscar.c_str());
				if (valor == 0)
					cout << "  S\242lo se aceptan valores num\202ricos." << endl;
				else {
					if (valor < 0)
						cout << "  No hay patentes negativas.";
					else if (valor >= 1 && valor <= 30000) {
						for (short p = 0; p < posicionP; p++)
							if (valor == MP[p].valor) {
								cout << "  N\243mero " << MP[p].valor << ": " << MP[p].nombre << endl;
								indicador = false;
								break;
							}

						if (indicador)
							cout << "  No se encontr\242 el medicamento de marca propia.";
					}
					else if ((valor > 30000 && valor < 31000) || valor > 60000)
						cout << "  Ingrese una patante en el rango de 1 a 30,000 \242 31,000 a 60,000" << endl;
					else if (valor >= 31000 && valor <= 60000) {
						for (short q = 0; q < posicionG; q++)
							if (valor == MG[q].valor) {
								cout << "  N\243mero " << MG[q].valor << ": " << MG[q].nombre << endl;
								indicador = false;
								break;
							}

						if (indicador)
							cout << "  No se encontr\242 el medicamento gen\202rico.";
					}
				}
				system("PAUSE > NULL");
			}
		} while (Buscar != "0");
	}
}
void Muestra(MedicamentosPropios MP[], MedicamentosGenericos MG[], int &posicionP, int &posicionG) {
	// En este caso, mostrará los medicamentos ya registrados. En dado caso que no se haya capturado aún medicamentos, devolverá un mensaje correspondiente.
	system("CLS");

	// Verifica que haya medicamentos para mostrar.
	if (MP[0].valor == 0)
		cout << "\n  No hay medicamento de marca propia registrados." << endl;
	else {
		cout << "\n  Los medicamentos de marca propia:" << endl;
		cout << "  N\243mero\tNombre" << endl;
		cout << "  ========================================";
		for (short i = 0; i < posicionP; i++) {
			gotoxy(2, i + 4); cout << MP[i].valor;
			gotoxy(16, i + 4); cout << MP[i].nombre;
		}
		cout << endl;
	}
	// Verifica si ya hay medicamentos registrados para mostrarlos.
	if (MG[0].valor == 0) {
		if (MP[0].valor == 0) {
			gotoxy(55, 1); cout << "No hay medicamentos gen\202ricos registrados.";
		}
		else {
			gotoxy(45, 1); cout << "No hay medicamentos gen\202ricos registrados.";
		}
	}
	else {
		if (posicionP == 0) {
			gotoxy(52, 1); cout << "Los medicamentos gen\202ricos:";
			gotoxy(52, 2); cout << "N\243mero\tNombre";
			gotoxy(52, 3); cout << "========================================";
		}
		else {
			gotoxy(45, 1); cout << "Los medicamentos gen\202ricos:";
			gotoxy(45, 2); cout << "N\243mero\tNombre";
			gotoxy(45, 3); cout << "========================================";
		}
		for (short j = 0; j < posicionG; j++) {
			if (posicionP != 0) {
				gotoxy(45, j + 4); cout << MG[j].valor;
				gotoxy(56, j + 4); cout << MG[j].nombre;
			}
			else {
				gotoxy(52, j + 4); cout << MG[j].valor;
				gotoxy(64, j + 4); cout << MG[j].nombre;
			}
		}
	}

	if (posicionP < posicionG)
		gotoxy(0, posicionG + 4);
	else if (posicionP == posicionG)
		if (posicionP == 0)
			gotoxy(0, 2);
		else
			gotoxy(0, posicionP + 4);
	else
		gotoxy(0, posicionP + 4);
}
void Elimina(MedicamentosPropios MP[], MedicamentosGenericos MG[], int &posicionP, int &posicionG) {
	int valor = 0, tP = 0, tG = 0;
	string entrada = "", nomP = "", nomG = "";
	bool indicador = true;

	// En este caso, le pedirá al usuario el número del medicamento para eliminarlo, si no hay un medicamento con ese número, devolverá un mensaje indicando que ese medicamento no ha sido registrado.
	do {
		system("CLS");

		cout << "\n  Para salir de esta opci\42n, intrduzca un 0." << endl;
		cout << "\n  N\243mero del medicamento: ";
		getline(cin, entrada);

		if (entrada != "0") {
			valor = atoi(entrada.c_str());
			if (valor < 0)
				cout << "  No hay patentes negativas." << endl;
			else if (valor >= 1 && valor <= 30000) {
				for (short p = 0; p <= posicionP; p++)
					if (valor == MP[p].valor) {
						MP[p].valor = 0;
						MP[p].nombre = "";
						cout << "  Se elimin\242 satisfactoriamente el medicamento de marca propia." << endl;
						posicionP--;
						indicador = false;
						break;
					}
			}
			else if ((valor > 30000 && valor < 31000) || valor > 60000)
				cout << "  Introduzca valores en el rango de 1 a 30,000 \242 31,000 a 60,000." << endl;
			else if (valor >= 31000 && valor <= 60000) {
				for (short q = 0; q <= posicionG; q++)
					if (valor == MG[q].valor) {
						MG[q].valor = 0;
						MG[q].nombre = "";
						cout << "  Se elimin\242 satisfactoriamente el medicamento gen\202rico." << endl;
						posicionG--;
						indicador = false;
						break;
					}
			}

			if (indicador)
				cout << "  Este medicamento no est\240 registrado.";

			system("PAUSE > NULL");

			// Reordena los valores de mayor a menor para que el contador posicionP pueda agregar un nuevo medicamento en la posición siguiente.
			// Ordenamiento por selección
			for (short n = 0, m = 0; n <= posicionP; n++) {
				m = n;
				for (short o = n + 1; o <= posicionP; o++)
					if (MP[m].valor < MP[o].valor)
						m = o;
				tP = MP[n].valor;
				MP[n].valor = MP[m].valor;
				MP[m].valor = tP;

				nomP = MP[n].nombre;
				MP[n].nombre = MP[m].nombre;
				MP[m].nombre = nomP;
			}

			// Hace lo mismo del for anterior, pero con posicionG.
			for (short n = 0, m = 0; n <= posicionG; n++) {
				m = n;
				for (short o = n + 1; o <= posicionG; o++)
					if (MG[m].valor < MG[o].valor)
						m = o;
				tG = MG[n].valor;
				MG[n].valor = MG[m].valor;
				MG[m].valor = tG;

				nomG = MG[n].nombre;
				MG[n].nombre = MG[m].nombre;
				MG[m].nombre = nomG;
			}
		}
	} while (entrada != "0");
}
void TrashKill(MedicamentosPropios MP[], MedicamentosGenericos MG[], int tamP, int tamG) {
	for (short i = 0; i < tamP; i++)
		if (MP[i].valor != 0)
			MP[i].valor = 0;
	for (short j = 0; j < tamG; j++)
		if (MG[j].valor != 0)
			MG[j].valor = 0;
}
void IMSS() {
	int pP = 0, pG = 0;
	MedicamentosPropios MEDP[500];
	MedicamentosGenericos MEDG[250];

	// Hay basura en el arreglo, así que para un mejor manejo, todas las posiciones de los arreglos de .valor, serán igualados a 0.
	TrashKill(MEDP, MEDG, 500, 250);

	// Antes de visualizar el menú del IMSS, valida la contraseña.

	if (Validar()) {
		do {
			// Aquí empieza el submenú correspondiente al del IMSS.
			switch (MenuIMSS()) {
			case 1:
				Captura(MEDP, MEDG, pP, pG);
				break;
			case 2:
				Busca(MEDP, MEDG, pP, pG);
				break;
			case 3:
				Muestra(MEDP, MEDG, pP, pG);
				break;
			case 4:
				Elimina(MEDP, MEDG, pP, pG);
				break;
			case 5:
				cout << endl;
				break;
			default:
				system("CLS");
				cout << "\n  Opci\242n no v\240lida." << endl;
			}
		} while (ReturnMenu("escoger otra opci\242n del men\243 IMSS") != 'N');
	}
	else
		cout << "  Como no ha acertado la contrase\244a en tres intentos. Se saldr\240 de esta opci\242n." << endl;
}

// Funciones de Menú Series
char MenuSerie() {
	// Muestra el menú para el caso "Serie I" y "Serie II".
	string opc = "";
	system("CLS");

	gotoxy(40, 1); cout << "/******************************************";
	gotoxy(40, 2); cout << "DESCRIPCI\340N:";
	gotoxy(45, 3); cout << "Con el n\243mero recogio anteriormente";
	gotoxy(45, 4); cout << "se le mostrará una serie sucesiva;";
	gotoxy(45, 5); cout << "ya sea con fracciones o decimles.";
	gotoxy(40, 6); cout << "*****************************************/";
	gotoxy(0, 0);

	cout << "\n  BIENVENIDO AL MEN\351 DE SERIES";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  A) Mostrar en fracciones";
	cout << "\n  B) Mostrar en decimales";
	cout << "\n  C) Volver al men\243 principal";
	cout << "\n  \250Qu\202 qyuere gacer? ";
	getline(cin, opc);
	return toupper(opc[0]);
}
int ValidarRango() {
	// Esta función valida que el nímero ingresado, sea perteneciente al rango de 6 - 120.

	string validar = "";
	int numero = 0;

	do {
		system("CLS");

		cout << "\n  Introduzca un n\243mero entre 6 a 20: ";
		getline(cin, validar);
		if (validar != "0") {
			numero = atoi(validar.c_str());
			if (numero == 0) {
				cout << "  S\242lo se aceptan n\243meros enteros.";
				system("PAUSE > NULL");
			}
			else if (numero < 6 || numero > 20) {
				cout << "  Este n\243mero no est\240 en el rango.";
				system("PAUSE > NULL");
			}
		}
		else {
			cout << "  Este n\243mero no est\240 en el rango.";
			system("PAUSE > NULL");
		}
	} while (numero < 6 || numero > 20 || validar == "0");
	return numero;
}
void Fracciones(int n) {
	// Esta función muestra la serie de fracciones correspondientes.

	float num = 0.0, sum = 0.0;
	int contador = 1;

	system("CLS");

	cout << "\n  Su suma es:\n  ";
	while (contador <= n) {
		num = 1.0 / contador;
		sum += num;
		if (contador != n)
			cout << "1/" << contador << " + ";
		else
			cout << "1/" << contador;
		contador++;
	}
	cout << " = " << sum << endl;
}
void Decimales(int n) {
	// Esta función muestra la serie de decimales correspondiente.

	float num = 0.0, sum = 0.0;
	int contador = 1;

	system("CLS");

	cout << "\n  Su suma es:\n  ";
	while (contador <= n) {
		num = 1.0 / contador;
		sum += num;
		if (contador != n)
			cout << num << " + ";
		else
			cout << num;
		contador++;
	}
	cout << " = " << sum << endl;
}
void SerieI() {
	int numero = 0;

	// Visualizará el menú correspondiente a Serie I.
	do {
		numero = ValidarRango();
		do {
			switch (MenuSerie()) {
			case 'A':
				Fracciones(numero);
				break;
			case 'B':
				Decimales(numero);
				break;
			case 'C':
				break;
			default:
				system("CLS");
				cout << "\n  Opci\242n no v\240lida." << endl;
			}
		} while (ReturnMenu("escoger otra opci\242n del men\243 Series") != 'N');
	} while (ReturnMenu("ingresar otro n\243mero") != 'N');
}
void Fracciones2(int n) {
	// Esta función mostrará la serie de fracciones con signos conjugados con ayuda de una condición.

	float num = 0.0, sum = 0.0;
	int contador = 1;

	system("CLS");

	cout << "\n  Su suma es:\n  ";
	while (contador <= n) {
		num = 1.0 / contador;
		if (contador % 2 == 0) {
			sum -= num;
			if (contador != n)
				cout << "1/" << contador << " + ";
			else
				cout << "1/" << contador;
		}
		else {
			sum += num;
			if (contador != n)
				cout << "1/" << contador << " - ";
			else
				cout << "1/" << contador;
		}
		contador++;
	}
	cout << " = " << sum << endl;
}
void Decimales2(int n) {
	// Esta función mostrará la serie de decimales con signos conjugados con ayuda de una condición.

	float num = 0.0, sum = 0.0;
	int contador = 1;

	system("CLS");

	cout << "\n  Su suma es:\n  ";
	while (contador <= n) {
		num = 1.0 / contador;
		if (contador % 2 == 0) {
			sum -= num;
			if (contador != n)
				cout << num << " + ";
			else
				cout << num;
		}
		else {
			sum += num;
			if (contador != n)
				cout << num << " - ";
			else
				cout << num;
		}
		contador++;
	}
	cout << " = " << sum << endl;
}
void SerieII() {
	int numero = 0;

	// Visualizará el menú correspondiente a Serie II.
	do {
		numero = ValidarRango();
		do {
			switch (MenuSerie()) {
			case 'A':
				Fracciones2(numero);
				break;
			case 'B':
				Decimales2(numero);
				break;
			case 'C':
				break;
			default:
				system("CLS");
				cout << "\n  Opci\242n no v\240lida." << endl;
			}
		} while (ReturnMenu("escoger otra opci\242n del men\243 Series") != 'N');
	} while (ReturnMenu("ingresar otro n\243mero") != 'N');
}

// Función de la opción Triángulo
void Triangulo() {
	// Esta función determinará el tipo de triángulo, dependiendo de la longitud de sus lados.
	float l1 = 0, l2 = 0, l3 = 0;
	string lado1 = "", lado2 = "", lado3 = "";

	do {
		system("CLS");

		gotoxy(50, 1); cout << "/************************************************";
		gotoxy(50, 2); cout << "DESCRIPCI\340N:";
		gotoxy(55, 3); cout << "Dependiendo de la longitud de los lados de un";
		gotoxy(55, 4); cout << "tri\240ngulo, se le mostrar\240 a qu\202 tipo";
		gotoxy(55, 5); cout << "pertenece.";
		gotoxy(50, 6); cout << "***********************************************/";
		gotoxy(0, 0);

		cout << "\n  Para salir, ingrese un 0." << endl;
		cout << "\n  Introduzca el lado 1: ";
		getline(cin, lado1);
		if (lado1 != "0") {
			cout << "  Introduzca el lado 2: ";
			getline(cin, lado2);
			if (lado2 != "0") {
				cout << "  Introduzca el lado 3: ";
				getline(cin, lado3);
				if (lado3 != "0") {
					l1 = atof(lado1.c_str()); // La función atof() tiene el mismo propósito que su hermana atoi(), con la diferencia que cnvierte las cadenas de carácteres a números flotantes.
					l2 = atof(lado2.c_str());
					l3 = atof(lado3.c_str());
					if (l1 > 0 && l2 > 0 && l3 > 0) {
						if (l1 == l2 && l1 != l3 || l2 == l3 && l2 != l1 || l1 == l3 && l3 != l2)
							cout << "\n  Su tri\240ngulo es is\242sceles.";
						else if (l1 == l2 && l2 == l3)
							cout << "\n  Su tri\240ngulo es equil\240tero.";
						else
							cout << "\n  Su tri\240ngulo es escaleno.";
						cout << "\n  Sus lados son:\n\t" << l1 << "\t" << l2 << "\t" << l3;
					}
					else if (l1 == 0 || l2 == 0 || l3 == 0)
						cout << "\n  S\243lo se aceptan n\243meros.";
					else
						cout << "\n  Uno de sus n\243meros es negativo.";
					system("PAUSE > NULL");
				}
			}
		}
	} while (lado1 != "0" && lado2 != "0" && lado3 != "0");
}

// Funcines del Menú Sueldos
char MenuSueldos() {
	string opc = "";
	system("CLS");

	gotoxy(40, 1); cout << "/*********************************************";
	gotoxy(40, 2); cout << "DESCRIPCI\340N:";
	gotoxy(45, 3); cout << "Con los nombres y salarios ingresados";
	gotoxy(45, 4); cout << "previamente, se le mostrará cuál es el";
	gotoxy(45, 5); cout << "mayor, el menor, ambos o todos; seg\243n";
	gotoxy(45, 6); cout << "la opci\242n que elijas.";
	gotoxy(40, 7); cout << "*********************************************/";
	gotoxy(0, 0);

	cout << "\n  BIENVENIDO AL MEN\351 DE SUELDOS";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  A) Sueldo mayor";
	cout << "\n  B) Sueldo menor";
	cout << "\n  C) Sueldo mayor y menor";
	cout << "\n  D) Mostrar todos los sueldos";
	cout << "\n  E) Volver al men\243 principal";
	cout << "\n  \250Qu\202 qyuere gacer? ";
	getline(cin, opc);
	return toupper(opc[0]);
}
void Sueldo() {
	// Determinará el sueldo mayor, menor o ambos.
	float t = 0, *Sueldos;
	int tam = 0;
	string entrada = "", n = "", num = "", *Nombres;
	bool indicador = false;

	do {
		system("CLS");

		cout << "\n  \250Cu\240ntos elementos ingresar\240? ";
		getline(cin, entrada);
		if (entrada != "0") {
			tam = atoi(entrada.c_str());
			if (tam == 0)
				cout << "  No se aceptan letras." << endl;
			else {
				if (tam > 1) {				// Se declara el arreglo dinámico
					Sueldos = new float[tam];
					Nombres = new string[tam];
					system("CLS");

					// Pedir el nombre y sueldo del número de personas.
					for (short b = 0; b < tam; b++) {
						do {
							cout << "\n       Persona " << b + 1;
							cout << "\n  =========================";
							cout << "\n  Nombre: ";
							getline(cin, n);

							if (n == "0") {
								cout << "  No ha ingresado letras. Int\202ntelo de nuevo.";
								system("PAUSE > NULL");
								system("CLS");
							}
							else {
								if (atoi(n.c_str()) != 0) {
									cout << "  No ha ingresado letras. Int\202ntelo de nuevo.";
									system("PAUSE > NULL");
									system("CLS");
								}
							}
						} while (atoi(n.c_str()) != 0 || n == "0");
						do {
							cout << "  Sueldo: $";
							getline(cin, num);
							if (num == "0")
								cout << "  No se admiten valores menores de $1,000 \242 mayores a $100,000." << endl;
							else {
								if (num.length() <= 9) {
									t = atof(num.c_str());
									if (t < 0)
										cout << "  No hay sueldos negativos." << endl;
									else if (t == 0)
										cout << "  No se admiten letras." << endl;
									else if (t < 1000 || t > 100000)
										cout << "  No se admiten valores menores a $1,000 \242 mayores a $100,000." << endl;
									else if (t <= 1000 || t > 100000)
										cout << "  No se admiten valores menores a $1,000 \242 mayores a $100,000." << endl;
								}
								else {
									cout << "  El sueldo debe tener m\240ximo 8 d\241gitos -contando con dos decimales-." << endl;
									cout << "  Ejemplo: $45725.50" << endl;
								}
							}
							for (short d = 0; d < tam; d++)
								if (Sueldos[d] == t) {
									indicador = true;
									cout << "  Alguien m\240s tiene el mismo sueldo... Y eso no es posible... Por lo menos, no en este código." << endl;
									break;
								}
								else
									indicador = false;
						} while (num == "0" || num.length() > 9 || t < 0 || t == 0 || indicador || t < 1000 || t > 100000);
						Nombres[b] = n;
						Sueldos[b] = t;
						system("CLS");
					}

					// Se organiza el arreglo de mayor a menor.
					// Ordenamiento por inserción.
					for (short o = 1, j = 0; o < tam; o++) {
						t = Sueldos[o];
						n = Nombres[o];
						j = o - 1;
						while (Sueldos[j] < t && j >= 0) {
							Sueldos[j + 1] = Sueldos[j];
							Nombres[j + 1] = Nombres[j];
							j--;
						}
						Sueldos[j + 1] = t;
						Nombres[j + 1] = n;
					}
					do {
						switch (MenuSueldos()) {
						case 'A':
							// Como el valor mayor está en la posición 0, sólo hay que mostrarlo
							system("CLS");
							cout << "\n  El sueldo mayor es:" << endl;
							cout << "\tNombre: " << Nombres[0] << endl;
							cout << "\tSueldo: $" << Sueldos[0] << endl;
							break;
						case 'B':
							// Como el valor menor está en la última posición
							system("CLS");
							cout << "\n  El sueldo menor es:" << endl;
							cout << "\tNombre: " << Nombres[tam - 1] << endl;
							cout << "\tSueldo: $" << Sueldos[tam - 1] << endl;
							break;
						case 'C':
							// Se juntaron A y B
							system("CLS");

							cout << "\n  El sueldo mayor es:" << endl;
							cout << "\tNombre: " << Nombres[0] << endl;
							cout << "\tSueldo: $" << Sueldos[0] << endl;

							cout << "\n  El sueldo menor es:" << endl;
							cout << "\tNombres: " << Nombres[tam - 1] << endl;
							cout << "\tSueldo: $" << Sueldos[tam - 1] << endl;
							break;
						case 'D':
							// Se muestra en forma de tabla, los nombres y sueldos ingresados.
							// Una opción que me pareció conveniente agregar
							system("CLS");
							cout << "\n  Sueldo\tNombre";
							cout << "\n  =============================================";
							for (short m = 0; m < tam; m++) {
								gotoxy(2, m + 3); cout << "$" << Sueldos[m];
								gotoxy(16, m + 3); cout << Nombres[m];
							}
							cout << endl;
							break;
						case 'E':
							break;
						default:
							cout << "\n  Opci\242n no v\240lida.";
						}
					} while (ReturnMenu("escoger otra opci\242n del men\243 Sueldos") != 'N');
					delete[] Sueldos;
					delete[] Nombres;
				}
				else if (tam == 1) {
					do {
						system("CLS");
						cout << "\n       Persona 1";
						cout << "\n  =========================";
						cout << "\n  Nombre: ";
						getline(cin, n);
						if (n == "0") {
							cout << "  No ha ingresado letras. Int\202ntelo de nuevo.";
							system("PAUSE > NULL");
							system("CLS");
						}
						else {
							if (atoi(n.c_str()) != 0) {
								cout << "  No ha ingresado letras. Int\202ntelo de nuevo.";
								system("PAUSE > NULL");
								system("CLS");
							}
						}
					} while (atoi(n.c_str()) != 0 || n == "0");
					do {
						cout << "  Sueldo: $";
						getline(cin, num);
						if (num == "0")
							cout << "  No se admiten valores menores de $1,000 \242 mayores a $100,000." << endl;
						else {
							if (num.length() <= 9) {
								t = atof(num.c_str());
								if (t < 0)
									cout << "  No hay sueldos negativos." << endl;
								else if (t == 0)
									cout << "  No se admiten letras." << endl;
								else if (t <= 1000 || t > 100000)
									cout << "  No se admiten valores menores a $1,000 \242 mayores a $100,000." << endl;
								else if (t < 1000 || t > 100000)
									cout << "  No se admiten valores menores a $1,000 \242 mayores a $100,000." << endl;
							}
							else {
								cout << "  El sueldo debe tener m\240ximo 8 d\241gitos -contando con dos decimales-." << endl;
								cout << "  Ejemplo: $45725.50" << endl;
							}
						}
					} while (num == "0" || num.length() > 9 || t < 0 || t == 0 || t < 1000 || t > 100000);
					system("CLS");
					cout << "\n  Como es el \243nico elemento ingresado, por lo tanto es el mayor y menor al mismo tiempo.";
					cout << "\n\tNombre: " << n;
					cout << "\n\tSueldo: $" << t << endl;
				}
				else
					cout << "  No hay elementos negativos" << endl;
			}
		}
		else
			cout << "  Como ha ingresado 0, no se puede proseguir con el proceso. Por tanto, aqu\241 finaliza." << endl;
	} while (ReturnMenu("ingresar otro valor") != 'N');
}

// Funciones del Menú Costos
char MenuCostos() {
	string opc = "";
	system("CLS");

	gotoxy(40, 1); cout << "/*********************************************";
	gotoxy(40, 2); cout << "DESCRIPCI\340N:";
	gotoxy(45, 3); cout << "Se mostrar\240 el mes con mayor y menor";
	gotoxy(45, 4); cout << "producci\242; adem\240, de que se calcula el";
	gotoxy(45, 5); cout << "promedio anual.";
	gotoxy(40, 6); cout << "*********************************************/";
	gotoxy(0, 0);

	cout << "\n  BIENVENIDO AL MEN\351 DE COSTOS";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  A) Mes con costo mayor";
	cout << "\n  B) Mes con consto menor";
	cout << "\n  C) Promedio anual";
	cout << "\n  D) Volver al men\243 principal";
	cout << "\n  \250Qu\202 quiere gacer? ";
	getline(cin, opc);
	return toupper(opc[0]);
}
string Mes(int m) {
	if (m == 0)
		return "Enero";
	else if (m == 1)
		return "Febrero";
	else if (m == 2)
		return "Marzo";
	else if (m == 3)
		return "Abril";
	else if (m == 4)
		return "Mayo";
	else if (m == 5)
		return "Junio";
	else if (m == 6)
		return "Julio";
	else if (m == 7)
		return "Agosto";
	else if (m == 8)
		return "Septiembre";
	else if (m == 9)
		return "Octubre";
	else if (m == 10)
		return "Noviembre";
	else
		return "Diciembre";
}
void CosteProduccion(float A[], int tam, int &may, int &men) {
	string entrada = "";
	bool indicador = false;
	float nma = 0, nme = 1000000, num = 0;

	for (short i = 0; i < tam; i++) {
		system("CLS");
		do {
			cout << "\n  \250Cu\240nto se produj\242 en el mes de " << Mes(i) << "? $";
			getline(cin, entrada);
			if (entrada == "0")
				cout << "  S\242lo se admiten valores mayores a $1,000 y menores a $1,000,000." << endl;
			else {
				if (entrada.length() <= 10) {
					num = atof(entrada.c_str());
					if (num < 0)
						cout << "  No hay costes de producci\242n negativos. En este programa, no." << endl;
					else if (num == 0)
						cout << "  No se admiten valores que no sean n\243meros.";
					else if (num < 1000 || num > 1000000)
						cout << "  S\242lo se admiten valores entre $1,000 y $1,000,000." << endl;
					for (short e = 0; e < tam; e++)
						if (A[e] == num) {
							indicador = true;
							cout << "  Ya ha ingresado este costo de producci\242n. En este programa no se aceptan valores repetidos." << endl;
							break;
						}
						else
							indicador = false;
				}
				else
					cout << "  S\242 se admiten 7 cifrras y dos deciales. Ejemplo: $700590.25" << endl;
			}
		} while (entrada == "0" || entrada.length() > 10 || num < 0 || num < 1e3 || num > 1e6 || indicador);
		A[i] = num;
	}

	for (short c = 0; c < tam; c++) {
		if (nma < A[c]) {
			may = c;
			nma = A[c];
		}
		if (nme > A[c]) {
			men = c;
			nme = A[c];
		}
	}
}
void Costo() {
	float Costos_Mes[12], sum = 0.0;
	int mayor = 0, menor = 0;

	do {
		CosteProduccion(Costos_Mes, 12, mayor, menor);
		do {
			switch (MenuCostos()) {
			case 'A':
				system("CLS");
				cout << "\n  El mes con costos de producci\242n mayor fue: " << endl;
				cout << "\tMes " << Mes(mayor) << endl;
				cout << "\tCosto: $" << Costos_Mes[mayor] << endl;
				break;
			case 'B':
				system("CLS");
				cout << "\n  El mes con el menor costo de producci\242 fue: " << endl;
				cout << "\tMes " << Mes(menor) << endl;
				cout << "\tCosto: $" << Costos_Mes[menor] << endl;
				break;
			case 'C':
				system("CLS");
				for (short s = 0; s < 12; s++)
					sum += Costos_Mes[s] / 12;
				cout << "\n  La media de costos de producci\242n fue de: $" << sum << endl;
				break;
			case 'D':
				break;
			default:
				system("CLS");
				cout << "\n  Opci\242n no v\240lida.";
			}
		} while (ReturnMenu("escoger otra opci\242n del men\243 de Costos") != 'N');
	} while (ReturnMenu("ingresar otros valores") != 'N');
}

// FUNCIONES DE CLASES
int MenuClases() {
	string entrada = "";

	system("CLS");

	gotoxy(40, 1); cout << "/*******************************************************";
	gotoxy(40, 2); cout << "DESCRIPCI\340N:";
	gotoxy(45, 3); cout << "Se encuentran las tres clases propuestas";
	gotoxy(45, 4); cout << "como ejercicios. La clase de AHORRO pedir\240";
	gotoxy(45, 5); cout << "los datos correspondientes al ahorro en un banco.";
	gotoxy(45, 6); cout << "La clase Paralelogramo devolverá el per\241metro";
	gotoxy(45, 7); cout << "y \240rea de un paralelogramo. La clase ASIGNATURA";
	gotoxy(45, 8); cout << "mostrar\240 el promedio y n\243mero de alumnos";
	gotoxy(45, 9); cout << "acreditados y no acreditados en una materia.";
	gotoxy(40, 10); cout << "*******************************************************/";
	gotoxy(0, 0);

	cout << "\n  BIENVENIDO AL MEN\351 DE CLASES";
	cout << "\n  \261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261";
	cout << "\n  1) Ahorro";
	cout << "\n  2) Paralelogramo";
	cout << "\n  3) Geometr\241a Anal\241tica";
	cout << "\n  4) Salir";
	cout << "\n  \250Qu\202 quiere hacer? ";
	getline(cin, entrada);
	return atoi(entrada.c_str());
}
// FUNCIONES CLASE AHORRO
int PedirTam() {
	string size = "";
	bool indicador = false;

	system("CLS");
	cout << "\n  \250Cu\240ntos clientes ingresar\240s? ";
	do {
		try {
			getline(cin, size);
			if (size == "0") {
				cout << "  No ingresar\240 clientes, por lo que el programa termina aqu\241.";
				system("PAUSE > NULL");
				exit(1);
			}
			else if (atoi(size.c_str()) < 0)
				throw size;
			else if (atoi(size.c_str()) == 0)
				throw 1;
			else
				indicador = false;
		}
		catch (int e) {
			cout << "  Ha introducido car\240cteres no v\240lidos.\n\n  Inttroduzca n\243meros: ";
			indicador = true;
		}
		catch (string e) {
			cout << "  Ingres\242 un n\243mero negativo. Introduzca un n\243mero positivo: ";
			indicador = true;
		}
	} while (indicador);
	return atoi(size.c_str());
}
string PedirNombre(int NC) {
	bool indicador;
	string nom = "";

	system("CLS");
	cout << "\n  Cliente " << NC + 1 << ":";
	cout << "\n  ==============================================================";
	cout << "\n  Ingrese su nombre: ";
	do {
		try {
			getline(cin, nom);
			if (nom == "0" || atoi(nom.c_str()) != 0)
				throw atoi(nom.c_str());
			else
				indicador = false;
		}
		catch (int e) {
			cout << "  N\243mero no v\240lido. Ingres\242 0 \242 negativo." << endl;
			cout << "\n  Ingrese un nombre v\coherente: ";
			indicador = true;
		}
	} while (indicador);
	return nom;

}
string PedirBanco(int NC) {
	string ban = "";

	system("CLS");
	cout << "\n  Cliente " << NC + 1 << ":";
	cout << "\n  ==============================================================";
	cout << "\n  Ingrese el nombre del Banco: ";
	getline(cin, ban);
	return ban;
}
string PedirCuenta(int NC) {
	string cue = "";

	system("CLS");
	cout << "\n  Cliente " << NC + 1 << ":";
	cout << "\n  ==============================================================";
	cout << "\n  Ingrese su n\243mero de cuenta: ";
	getline(cin, cue);
	return cue;

}
short PedirPlazo(int NC) {
	string pla = "";
	bool indicador = false;

	system("CLS");
	cout << "\n  Cliente " << NC + 1 << ":";
	cout << "\n  ==============================================================";
	cout << "\n  \250Cu\240l es el plazo que utilizar\240? [1 a 36 meses] ";
	do {
		try {
			getline(cin, pla);
			if (pla == "0" || atoi(pla.c_str()) < 0 || atoi(pla.c_str()) > 36)
				throw 0;
			else if (atoi(pla.c_str()) == 0)
				throw "ERROR";
			else
				indicador = false;
		}
		catch (int e) {
			cout << " Plazo fuera del rango." << endl;
			cout << "\n  Ingrese un plazo v\240lido: ";
			indicador = true;
		}
		catch (string e) {
			cout << "\n  Ingres\242 car\240cteres inv\240lidos." << endl;
			cout << "  Ingrese s\242lo n\243meros: ";
			indicador = true;
		}
	} while (indicador);
	return atoi(pla.c_str());
}
double PedirSubtotal(short plazo, int NC) {
	string ahomes = "";
	double subtot = 0;
	bool indicador = false;

	for (short n = 1; n <= plazo; n++) {
		system("CLS");
		cout << "\n  Cliente " << NC + 1 << ":";
		cout << "\n  ==============================================================";
		cout << "\n  Ahorro del mes " << n << ": $";
		do {
			try {
				getline(cin, ahomes);
				if (ahomes != "0") {
					if (atof(ahomes.c_str()) == 0)
						throw "ERROR";
					else if (atof(ahomes.c_str()) < 0)
						throw 0;
					else
						indicador = false;
				}
				else
					indicador = false;
			}
			catch (int e) {
				cout << "  No hay ahorros negativos en este programa." << endl;
				cout << "\n  Ingresar un ahorro v\240lido: ";
				indicador = true;
			}
			catch (string e) {
				cout << "  Ha ingresado car\240cteres incorrectos." << endl;
				cout << "\n  Ingrese un ahorro v\240lido: ";
				indicador = true;
			}
		} while (indicador);
		subtot += atof(ahomes.c_str());
	}
	return subtot;
}
void ClassAhorro() {
	Ahorro *Cliente;
	int tam = 0;
	string nombre = "", cuenta = "", banco = "";
	short plazo = 0;
	double subtotal = 0.0;

	system("CLS");
	tam = PedirTam();
	Cliente = new Ahorro[tam];

	for (int i = 0; i < tam; i++) {
		nombre = PedirNombre(i);
		banco = PedirBanco(i);
		cuenta = PedirCuenta(i);
		plazo = PedirPlazo(i);
		subtotal = PedirSubtotal(plazo, i);
		Cliente[i].setDatos(nombre, banco, cuenta, plazo, subtotal);
		Cliente[i].Calcular();
	}

	for (int j = 0; j < tam; j++)
		Cliente[j].Mostrar(j, tam);

	delete[] Cliente;
}
// CLASE PARALELOGRAMO
float PedirBase() {
	string b = "";
	bool indicador = false;

	system("CLS");
	cout << "\n  Ingrese la base: ";
	do {
		try {
			getline(cin, b);
			if (b == "0")
				indicador = false;
			else if (atof(b.c_str()) == 0)
				throw "ERROR";
			else if (atof(b.c_str()) < 0)
				throw -1;
			else
				indicador = false;
		}
		catch (int e) {
			cout << " No hay longitudes negativas." << endl;
			cout << "\n  Ingrese una longitud v\240lido: ";
			indicador = true;
		}
		catch (string e) {
			cout << "\n  Ingres\242 car\240cteres inv\240lidos." << endl;
			cout << "  Ingrese s\242lo n\243meros: ";
			indicador = true;
		}
	} while (indicador);
	return atof(b.c_str());

}
float PedirAltura() {
	string h = "";
	bool indicador = false;

	system("CLS");
	cout << "\n  Ingrese la altura: ";
	do {
		try {
			getline(cin, h);
			if (h == "0")
				indicador = false;
			else if (atof(h.c_str()) == 0)
				throw "ERROR";
			else if (atof(h.c_str()) < 0)
				throw - 1;
			else
				indicador = false;
		}
		catch (int e) {
			cout << " No hay longitudes negativas." << endl;
			cout << "\n  Ingrese una longitud v\240lido: ";
			indicador = true;
		}
		catch (string e) {
			cout << "\n  Ingres\242 car\240cteres inv\240lidos." << endl;
			cout << "  Ingrese s\242lo n\243meros: ";
			indicador = true;
		}
	} while (indicador);
	return atof(h.c_str());

}
void ClassParalelogramo() {
	float base = 0, altura = 0;

	base = PedirBase();
	altura = PedirAltura();

	if (base == altura) {
		Paralelogramo Cuadrado;
		Cuadrado.setLados(base, altura);
		Cuadrado.Mostrar("cuadrado");
	}
	else {
		Paralelogramo Rectangulo;
		Rectangulo.setLados(base, altura);
		Rectangulo.Mostrar("rect\240ngulo");
	}
}
// CLASE GEOMETRÍA ANALÍTICA
void ClassAsignatura() {
	Asignatura Geo_Ana;
	short tam = 0;
	bool indicador = false;
	string cal = "";

	tam = PedirTam();
	Geo_Ana.setTam(tam);

	for (short n = 0; n < tam; n++) {
		system("CLS");
		cout << "\n  Calificaci\242n " << n + 1 << ": ";
		do {
			try {
				getline(cin, cal);
				if (cal != "0") {
					if (atoi(cal.c_str()) == 0.0)
						throw cal;
					else if (atof(cal.c_str()) < 0 || atof(cal.c_str()) > 10)
						throw -1;
					else
						indicador = false;
				}
				else
					indicador = false;
			}
			catch (int e) {
				cout << "  No hay calificaciones menores a 0 \242 mayores a 10." << endl;
				cout << "\n  Ingresar una calificaci\242n v\240lida: ";
				indicador = true;
			}
			catch (string e) {
				cout << "  Ha ingresado car\240cteres incorrectos." << endl;
				cout << "\n  Ingrese una calificaci\242n v\240lida: ";
				indicador = true;
			}
		} while (indicador);
		Geo_Ana.setCalificacion(atof(cal.c_str()), n);
	}
	Geo_Ana.Mostrar();
}
void Clases() {
	do {
		system("CLS");
		switch (MenuClases()) {
		case 1:
			ClassAhorro();
			break;
		case 2:
			ClassParalelogramo();
			break;
		case 3:
			ClassAsignatura();
			break;
		case 4:
			break;
		default:
			cout << "  Opci\242n no v\240lida.";
		}
	} while (ReturnMenu("mostrar de nuevo el men\243 CLASES") != 'N');
}