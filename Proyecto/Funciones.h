// FUNCIONES DE USO GENERAL
void gotoxy(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);
}
int WhereX() {
	CONSOLE_SCREEN_BUFFER_INFO sbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
	return sbi.dwCursorPosition.X;
}
int WhereY() {
	CONSOLE_SCREEN_BUFFER_INFO sbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
	return sbi.dwCursorPosition.Y;
}
bool CompararStrings(string Str1, string Str2) {
	// Aquí se convierte cada uno de los carácteres de las strings a minúsculas y compararlas.
	for (int i = 0; i < Str1.length(); i++)
		Str1[i] = tolower(Str1[i]);
	for (int j = 0; j < Str2.length(); j++)
		Str2[j] = tolower(Str2[j]);
	
	return Str1 == Str2 ? true : false;
}
char ReturnMenu(string P) {
	// Pregunta si desea volver al menú.

	string c = "";
	char r;

	do {
		cout << "\n \250Quieres " << P << "? [S/N] ";
		getline(cin, c);
		r = toupper(c[0]);
		if (r != 'S' && r != 'N')
			cout << "  Car\240cter no v\240lido. Ingrese solamente S \243 N." << endl;
	} while (r != 'S' && r != 'N');
	return r;
}
string FechaHoraActual() {
	// Con esta función, se puede determinar la hora actual del sistema cuando fuese invocada.
	time_t actual = time(0);
	struct tm  fechaHora;
	char t[80];
	errno_t tiempo;
	tiempo = localtime_s(&fechaHora, &actual);
	strftime(t, 30, "%d/%h/%Y %H:%M:%S", &fechaHora);

	return t;
}
int AsignarNumeroCliente() {
	bool indicador;
	int num, r;
	random_device rd;

	/************************************************************************************
		Se genera un número aletario entre 50,000 y 300,000
		Si el número ya existe en alguno de los clientes registrados (poco probable, pero posible),
		se vuelve a generar hasta que no exista repetición.
	************************************************************************************/
	do {
		mt19937 gen(rd());
		uniform_int_distribution <> dist(50000, 300000);
		num = dist(gen);
	} while (L1.Repetido(num));
	return num;
}
bool LOGIN() {
	int c = NULL;
	string usuario = "", password;
	// Éstas son las claves de acceso.
	string USER = "The Matrix", PASS = "Algoritmos";
	int contador = 0;
	bool ingresa = false;

	
	// Se valida el usuario y contraseña. Si es correcto, tiene acceso al programa, sino, termina.
	do {
		password = "";
		system("CLS");
		gotoxy(5, 12); cout << "Usuario: " << USER;
		gotoxy(5, 13); cout << "Contrase\244a: " << PASS;
		gotoxy(0, 0);
		cout << "\t\t\tLogin de usuario" << endl;
		cout << "\t\t\t----------------" << endl;
		if (contador != 0)
			cout << "\n\tLlevas  " << contador << " intento(s)" << "\tTe quedan: " << 5 - contador;
		cout << "\n\tUsuario: ";
		getline(cin, usuario);

		cout << "\tPassword: ";
		do {
			c = _getch();
			if (c == 13); //numero 13 corresponde a un enter en ASCI
			else if (c != 8) {//8 en codigo ASCI es un retroceso
				password += (char)c;
				cout << "*";
			}
			else {
				if (password.length() > 0) {
					cout << "\b \b";
					password.erase(password.length() - 1);
				}
			}
		} while (contador <= 5 && c != 13);

		if (usuario == USER && password == PASS)
			ingresa = true;
		else
		{
			cout << " \n\tEl usuario y/o contrase\244a son incorrectos " << endl;
			contador++;
			system("PAUSE > NULL");
		}
	} while (ingresa == false && contador < 5); // Tiene cinco intentos para ingresar los datos correctos.

	//validar el ingreso
	if (ingresa == false)
	{
		cout << "\n\tUsted no pudo ingresar al sistema " << endl;
		cout << "\tSe acaba aqu\241 el programa.";
		system("PAUSE > NULL");
		exit(1);
	}
	else
	{
		system("CLS");
		cout << "\t\t\t-----------------------" << endl;
		cout << "\t\t\t\255\255Bienvenido al sistema!!" << endl;
		cout << "\t\t\t-----------------------" << endl;
		system("PAUSE > NULL");
		system("CLS");
		return true;
	}
}
void PRESENTACION() {
	cout << "\n  Equipo: The Matrix" << endl
		<< "  Alumno:" << endl
		<< "\tGuti\202rrez Contreras Edwin\tAnimaci\242n y Arte Digital" << endl
		<< "\tHern\240ndez Hern\240ndez Franco Salvador\tIng. Sist. Comp." << endl
		<< "\tReyes Cruz Oscar\tIng. Sist. Comp.";
	system("PAUSE > NULL");
}

// FUNCIONES DE EDWIN
// Todas las funciones con prefijo "Pedir", hacen eso, piden un dato del usuario
string PedirNombre(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Dame el nombre: ";
	n = N.MasPalabras();
	return n;
}
string PedirApPat(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Dame el apellido paterno: ";
	n = N.UnaPalabra();
	return n;
}
string PedirApMat(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Dame el apellido materno: ";
	n = N.UnaPalabra();
	return n;
}
string PedirEmail(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Dame el e-mail: ";
	n = N.Email();
	return n;
}
string PedirColonia(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Dame la colonia: ";
	n = N.Mixto();
	return n;
}
string PedirCalle(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Dame la calle: ";
	n = N.Mixto();
	return n;
}
string PedirNumInt(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Dame el n\243mero interior: ";
	n = N.Numeros();
	return n;
}
string PedirNumExt(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Dame el n\243mero exterior: ";
	n = N.Numeros();
	return n;
}
string PedirCP(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Dame el c\242digo postal: ";
	n = N.Numeros();
	return n;
}
void PedirEdoMuni(int num_cl, string &municipio, string &estado) {
	bool indicador = false; int edo = 0; char mun;
	string e, m;

	do {
		system("CLS");
		cout << "Datos del cliente " << num_cl << ":\n"
			<< "=====================================\n"
			<< " 1) Ciudad de M\202xico" << endl
			<< " 2) Estado de M\202xico" << endl
			<< " 3) Hidalgo" << endl
			<< " Escoje tu estado: ";
		getline(cin, e);
		edo = atoi(e.c_str());
		switch (edo) {
		case 1:
			do {
				system("CLS");
				cout << "Datos del cliente " << num_cl << ":\n"
					<< "======================================\n"
					<< " a) Tl\240huac" << endl
					<< " b) Cuajimalpa" << endl
					<< " c) Tlalpan" << endl
					<< " d) Xochimilco" << endl
					<< " e) Milpa Alta" << endl
					<< " Escoje tu delegaci\202n: ";
				getline(cin, m);
				mun = tolower(m[0]);
				switch (mun) {
				case 'a':
					estado = "Ciudad de M\202xico";
					municipio = "Tl?240huac";
					indicador = false;
					break;
				case 'b':
					estado = "Ciudad de M\202xico";
					municipio = "Cuajimalpa";
					indicador = false;
					break;
				case 'c':
					estado = "Ciudad de M\202xico";
					municipio = "Tlalpan";
					indicador = false;
					break;
				case 'd':
					estado = "Ciudad de M\202xico";
					municipio = "Xochimilco";
					indicador = false;
					break;
				case 'e':
					estado = "Ciudad de M\202xico";
					municipio = "Milpa Alta";
					indicador = false;
					break;
				default:
					cout << "Opci\242n no v\240lida." << endl;
					indicador = true;
					system("PAUSE > NULL");
				}
			} while (indicador);
			break;
		case 2:
			do {
				system("CLS");
				cout << "Datos del cliente " << num_cl << ":\n"
					<< "======================================\n"
					<< " a) Tlalnepantla" << endl
					<< " b) Ecatepec de Morelos" << endl
					<< " c) Tultitlan" << endl
					<< " Escoje tu delegaci\202n: ";
				getline(cin, m);
				mun = tolower(m[0]);
				switch (mun) {
				case 'a':
					indicador = false;
					estado = "Estado de M\202xico";
					municipio = "Tlalnepantla";
					break;
				case 'b':
					indicador = false;
					estado = "Estado de M\202xico";
					municipio = "Ecatepec de Morelos";
					break;
				case 'c':
					indicador = false;
					estado = "Estado de M\202xico";
					municipio = "Tultitlan";
					break;
				default:
					cout << "Opci\242n no v\240lida." << endl;
					indicador = true;
					system("PAUSE > NULL");
				}
			} while (indicador);
			break;
		case 3:
			do {
				system("CLS");
				cout << "Datos del cliente " << num_cl << ":\n"
					<< "======================================\n"
					<< " a) Actopan" << endl
					<< " Escoje tu delegaci\202n: ";
				getline(cin, m);
				mun = tolower(m[0]);
				switch (mun) {
				case 'a':
					indicador = false;
					estado = "Hidalgo";
					municipio = "Actopan";
					break;
				default:
					cout << "Opci\242n no v\240lida." << endl;
					indicador = true;
					system("PAUSE > NULL");
				}
			} while (indicador);
			break;
		default:
			cout << " Opci\202n no v\240lida." << endl;
			indicador = true;
			system("PAUSE > NULL");
		}
	} while (indicador);
}
string PedirTelefono(int num_cl) {
	string n; Validar N;

	system("CLS");
	cout << "Datos del cliente " << num_cl << ":\n"
		<< "==============================================" << endl
		<< "Presiona 0 para concluir con la inserci\242n de tel\202fonos de contacto." << endl
		<< "Dame un n\243mero telef\242nico: ";
	n = N.Telefono();
	return n;
}
int num_clientes() {
	string size = "";
	bool indicador = false;

	// Se determina el número de clientes que se ingresarán
	// Este número debe ser POSITIVO
	system("CLS");
	cout << "\250Cu\240ntos clientes ingresar\240s? ";
	do {
		try {
			getline(cin, size);
			if (size == "0")
				cout << "Como no ingresar\242s clientes, se acaba aqu\241 mi trabajo." << endl;
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
int menu3() {
	string str = "";
	
	system("CLS");
	cout << "\n 1. MOSTRAR TODOS LOS CLIENTES"
		<< "\n 2. MOSTRAR CLIENTE ESPECIFICO"
		<< "\n 3. SALIR"
		<< "\n Escoge una opci\242n: ";
	getline(cin, str);
	return atoi(str.c_str());
}
char menu4() {
	string str = ""; char opc;

	system("CLS");
	cout << "\n a) Por nombre completo"
		<< "\n b) Por n\243mero de cliente"
		<< "\n \250C\242mo quieres hacer la b\243squeda? ";
	getline(cin, str);
	opc = tolower(str[0]);
	return opc;
}
void CAPTURA()
{
	string nombre = "", a_paterno = "", a_materno = "", email = "", n = "", t = "";
	string num_int = "", num_ext = "", calle = "", col = "", cp = "", muni = "", edo = "";
	int NumAle = 0, tam = 0;
	bool indicador;
	Lista::Iterator p = L1.Inicio();
	deque<string> tel;
	
	tam = num_clientes();
	// Si ingresa 0, se sale de la función.
	if (tam == 0);
	// De lo contrario, empieza a pedir los datos.
	else
		for (int casillas = 0; casillas < tam; casillas++)
		{
			do {
				nombre = PedirNombre(casillas + 1);
				a_paterno = PedirApPat(casillas + 1);
				a_materno = PedirApMat(casillas + 1);
				n = nombre + " " + a_paterno + " " + a_materno;
				indicador = L1.Repetido(n);
				if (indicador) {
					cout << "\nYa hay un usuario con el mismo nombre y appelidos.";
					system("PAUSE > NULL");
				}
			} while(indicador); // Verifica que no haya usuarios con el mismo nombre
			email = PedirEmail(casillas + 1);
			NumAle = AsignarNumeroCliente();
			col = PedirColonia(casillas + 1);
			calle = PedirCalle(casillas + 1);
			num_int = PedirNumInt(casillas + 1);
			num_ext = PedirNumExt(casillas + 1);
			cp = PedirCP(casillas + 1);
			PedirEdoMuni(casillas + 1, muni, edo);
			while (true) {
				// Almacena los números telefónicos en una cola genérica
				// Posteriormente se pasará a esa cola a la clase para que sus valores se le asignen a la Clase Clientes
				t = PedirTelefono(casillas + 1);
				if (t == "0") break;
				else tel.push_back(t);
			}
			// Se le asignan valores al objeto Walmart
			Walmart.setDatos(nombre, a_paterno, a_materno, email, NumAle, col, calle, num_int, num_ext, cp, muni, edo, tel);
			// Al asignarle la cola con números telefónicos, se limpian los valores para evitar errores de inserción.
			tel.clear();
			// Conforme se repita el loop, se sobreescribirán estos datos. Creando un objeto distinto cada vez.
			p = L1.Insertar(p, Walmart);
		}
	cout << endl;
	return;
}
void MOSTRAR() {
	Validar N; string nom = ""; int num;

	// Se toman las debidas validaciones.
	// Si no hay usuarios, se le indicará al usuario.
	if (L1.Tamaño() == 0) {
		cout << "No hay usuarios que visualizar en este momento."
			<< "\nPor favor ingrese alguno para poder mostrarlo." << endl;
	}
	// Si hay sólo uno, no hay necesidad de mostrar un menú
	else if (L1.Tamaño() == 1)
		L1.Mostrar();
	// Se muestra el menú para mostrar todos los usuarios o alguno en especial
	else {
		do {
			switch (menu3()) {
			case 1:
				L1.Mostrar();
				break;
			case 2:
				do {
					switch (menu4()) {
					case 'a':
						system("CLS");
						cout << "Dame el nombre completo: ";
						nom = N.MasPalabras();
						L1.Buscar_Mostrar(nom);
						break;
					case 'b':
						system("CLS");
						cout << "Dame el n\243mero del cliente: ";
						num = atoi(N.Numeros().c_str());
						L1.Buscar_Mostrar(num);
						break;
					case 'c':
						break;
					default:
						cout << "Opci\242n inv\240lida." << endl;
					}
				} while (ReturnMenu("volver al men\243") != 'N');
				break;
			case 3:
				break;
			default:
				cout << "Opci\242n inv\240lida." << endl;
			}
		} while (ReturnMenu("volver a mostrar el men\243") != 'N');
	}
}
int menu2() {
	string opc = "";

	system("CLS");
	cout << "CONTROL DE CLIENTES"
		<< "\n 1-ALTA DE CLIENTES"
		<< "\n 2-CONSULTA DE CLIENTES "
		<< "\n 3.-SALIR"
		<< "\n Escoge tu opci\242n: ";
	getline(cin, opc);
	return atoi(opc.c_str());

}
void Edwin()
{
	do
	{
		switch (menu2())
		{
		case 1:
			CAPTURA();
			break;
		case 2:
			MOSTRAR();
			break;
		case 3:
			break;
		default:
			cout << "Opci\242n no v\240lida." << endl;
		}
	} while (ReturnMenu("volver al submen\243") != 'N');
}
char menu() {
	char menu;
	string opc = "";

	system("CLS");
	cout << "MENU PRINCIPAL WALLMART DE MEXICO"
		<< "\n A) CONTROL DE CLIENTES"
		<< "\n B) CONTROL DE VENTAS"
		<< "\n C) CONTRAOL DE FACTURAS"
		<< "\n D) SALIR.  "
		<< "\n Dame tu opci\242n: ";
	getline(cin, opc);
	menu = opc[0];
	return tolower(menu);
}

// FUNCIONES DE OSCAR
int MenuVentas() {
	string c = "";
	
	system("CLS");
	cout << "MENU DE CONTROL DE VENTAS" << endl
		<< "  1. Ingresar art\241culos" << endl
		<< "  3. Salir" << endl
		<< "  Escoje una opci\242n: ";
	getline(cin, c);
	return atoi(c.c_str());
}
void Oscar() {
	Articulo Art; int num_art = 0;
	string n = ""; int num = 0; Validar N;
	deque<Articulo> LArt;

	if (L1.Tamaño() == 0)
		cout << "\n No hay clientes a los cuales atribuirles la venta." << endl;
	else {
		do {
			num_art = num_clientes();
			for (int i = 1; i <= num_art; i++) {
				Art.pedir_articulo();
				LArt.push_back(Art);
			}

			do {
				system("CLS");
				cout << " Ingresa el n\243mero de cluente al que se le atribuye la venta: ";
				n = N.Numeros();
				num = atoi(n.c_str());
			} while (L1.Modificar_Articulos(num, LArt));
		} while (ReturnMenu("ingresar m\240s art\241culos") != 'N');
	}
}

// FUNCIONES DE FRANCO
void Franco() {
	Validar N; int num = 0; string nom = "";

	system("CLS");
	if (L1.Tamaño() == 0)
		cout << "\n  No hay usuarios ni art\241culos registrados." << endl;
	else {
		system("CLS");
		cout << "Dame el n\243mero del cliente: ";
		num = atoi(N.Numeros().c_str());
		L1.Buscar_Factura(num);
	}
}