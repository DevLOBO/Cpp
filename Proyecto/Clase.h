void gotoxy(int, int);
int WhereX(), WhereY();
int AsignarNumeroCliente();
string FechaHoraActual();
char ReturnMenu(string);

// Esta clase tiene las validaciones necesarias para los valores requeridos en este programa.
class Validar {
private:
	char AsignarChar(int Char) {
		if (Char == 241) return '\244';
		else if (Char == 209) return '\245';
		else if (Char == 225) return '\240';
		else if (Char == 233) return '\202';
		else if (Char == 237) return '\241';
		else if (Char == 243) return '\242';
		else if (Char == 250) return '\243';
		else if (Char == 193) return '\265';
		else if (Char == 201) return '\220';
		else if (Char == 205) return '\326';
		else if (Char == 211) return '\340';
		else if (Char == 218) return '\351';
		else if (Char == 32) return ' ';
		else return (char)Char;
	}
	bool ProveedorEmail(string Correo) {
		string pr_em = "";
		for (int e = 0; e < Correo.length(); e++)
			if (Correo[e] == '@') {
				pr_em = Correo.substr(e + 1);
				for (int m = 0; m < pr_em.length(); m++)
					pr_em[m] = tolower(pr_em[m]);
				break;
			}
		if (pr_em != "hotmail.com" && pr_em != "outlook.com" && pr_em != "yahoo.com.mx" && pr_em != "yahoo.com" && pr_em != "gmail.com" && pr_em != "live.es" && pr_em != "live.com" && pr_em != "aoi.com" && pr_em != "my.unitec.edu.mx")
			return true;
		return false;
	}
public:
	string UnaPalabra() {
		string str = "";
		int car, PosX, PosY;
		char C;

		do {
			car = _getch();
			PosX = WhereX(); PosY = WhereY();
			if (car == 13);
			else if (car != 8) {
				if ((car >= 65 && car <= 90) || (car >= 97 && car <= 122) || (car == 209 || car == 241) || (car == 193 || car == 201 || car == 205 || car == 211 || car == 218) || (car == 250 || car == 243 || car == 237 || car == 233 || car == 225)) {
					C = AsignarChar(car);
					cout << C;
					str += C;
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX + 1, PosY);
				}
				else if (car == 32) {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! S\340LO INGRESA UNA PALABRA";
					gotoxy(PosX, PosY);
				}
				else {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! INGRESASTE CAR\265CTERES NO PERMITIDOS";
					gotoxy(PosX, PosY);
				}
			}
			else {
				if (str.length() > 0) {
					cout << "\b \b";
					str.erase(str.length() - 1);
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX - 1, PosY);
				}
			}
		} while (car != 13);
		return str;
	}
	string MasPalabras() {
		string str = "";
		int car, PosX, PosY;
		char C;

		do {
			car = _getch();
			PosX = WhereX(); PosY = WhereY();
			if (car == 13);
			else if (car != 8) {
				if ((car >= 65 && car <= 90) || (car >= 97 && car <= 122) || (car == 209 || car == 241) || (car == 193 || car == 201 || car == 205 || car == 211 || car == 218) || (car == 250 || car == 243 || car == 237 || car == 233 || car == 225) || car == 32) {
					C = AsignarChar(car);
					cout << C;
					str += C;
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX + 1, PosY);
				}
				else {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! INGRESASTE CAR\265CTERES NO PERMITIDOS";
					gotoxy(PosX, PosY);
				}
			}
			else {
				if (str.length() > 0) {
					cout << "\b \b";
					str.erase(str.length() - 1);
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX - 1, PosY);
				}
			}
		} while (car != 13);
		return str;
	}
	string Mixto() {
		string str = "";
		int car, PosX, PosY;
		char C;

		do {
			car = _getch();
			PosX = WhereX(); PosY = WhereY();
			if (car == 13);
			else if (car != 8) {
				if ((car >= 65 && car <= 90) || (car >= 97 && car <= 122) || (car >= 48 && car <= 57) || (car == 209 || car == 241) || (car == 193 || car == 201 || car == 205 || car == 211 || car == 218) || (car == 250 || car == 243 || car == 237 || car == 233 || car == 225) || car == 32) {
					C = AsignarChar(car);
					cout << C;
					str += C;
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX + 1, PosY);
				}
				else {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! INGRESASTE CAR\265CTERES NO PERMITIDOS";
					gotoxy(PosX, PosY);
				}
			}
			else {
				if (str.length() > 0) {
					cout << "\b \b";
					str.erase(str.length() - 1);
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX - 1, PosY);
				}
			}
		} while (car != 13);
		return str;
	}
	string Numeros() {
		string str = ""; char C; int PosX, PosY, car;

		do {
			car = _getch();
			PosX = WhereX(); PosY = WhereY();
			if (car == 13);
			else if (car != 8) {
				if (car >= 48 && car <= 57) {
					C = (char)car;
					cout << C;
					str += C;
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX + 1, PosY);
				}
				else {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! INGRESASTE CAR\265CTERES NO PERMITIDOS";
					gotoxy(PosX, PosY);
				}
			}
			else {
				if (str.length() > 0) {
					cout << "\b \b";
					str.erase(str.length() - 1);
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX - 1, PosY);
				}
			}
		} while (car != 13);
		return str;
	}
	string NumFloat() {
		string str = ""; int PosX = 0, PosY = 0, car; short punto = 0; char C;

		do {
			car = _getch();
			PosX = WhereX(); PosY = WhereY();
			if (car == 13);
			else if (car != 8) {
				if (car >= 48 && car <= 57 || car == 46) {
					if (car == 46) punto++;

					if (punto > 1) {
						car = 12;
						gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! NO HAY DECIMALES CON DOS PUNTOS";
						gotoxy(PosX, PosY);
					}
					else {
						C = (char)car;
						cout << C;
						str += C;
						gotoxy(PosX, PosY + 1); cout << "                                                ";
						gotoxy(PosX + 1, PosY);
					}
				}
				else {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! INGRESASTE CAR\265CTERES NO PERMITIDOS";
					gotoxy(PosX, PosY);
				}
			}
			else {
				if (str.length() > 0) {
					if (str[str.length() - 1] == '.') punto--;
					cout << "\b \b";
					str.erase(str.length() - 1);
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX - 1, PosY);
				}
			}
		} while (car != 13);
		return str;
	}
	string Email() {
		string str = ""; char C; int car, PosX, PosY; short arroba = 0;

		do {
			car = _getch();
			PosX = WhereX(); PosY = WhereY();
			if (car == 13) {
				if (arroba == 0) {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! E-MAIL INCOMPLETO";
					gotoxy(PosX, PosY + 2); cout << "Siga el formato: alguien@example.com";
					gotoxy(PosX, PosY);
					car = 12;
				}
				else if (ProveedorEmail(str)) {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! PROVEEDOR DE EMAIL NO ACEPTADO";
					gotoxy(PosX, PosY);
					car = 12;
				}
				else
					car = 13;
			}
			else if (car != 8) {
				if ((car >= 65 && car <= 90) || (car >= 48 && car <= 57) || (car >= 97 && car <= 122) || car == 46 || car == 45 || car == 64 || car == 95) {
					C = (char)car;
					if (C == '@')
						arroba++;
					if (arroba > 1) {
						gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! NO SE PERMITEN DOS ARROBAS";
						gotoxy(PosX, PosY);
						arroba--;
					}
					else {
						if (isalpha(C) == 0 && str.empty()) {
							gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! EL PRIMER CAR\265CTER DEBE SER UNA LETRA";
							gotoxy(PosX, PosY);
						}
						else {
							str += C;
							cout << C;
							gotoxy(PosX, PosY + 1); cout << "                                                ";
							gotoxy(PosX, PosY + 2); cout << "                                       ";
							gotoxy(PosX + 1, PosY);
						}
					}
				}
				else {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! INGRESASTE CAR\265CTERES NO PERMITIDOS";
					gotoxy(PosX, PosY);
				}
			}
			else {
				if (str.length() > 0) {
					if (str[str.length() - 1] == '@') arroba--;

					cout << "\b \b";
					str.erase(str.length() - 1);
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX - 1, PosY);
				}
			}
		} while (car != 13);

		for (int e = 0; e < str.length(); e++)
			if (str[e] != '@' && str[e] != '-' && str[e] != '_' && str[e] != '.' && !(str[e] >= '0' && str[e] <= '9'))
				str[e] = tolower(str[e]);

		return str;
	}
	string Telefono() {
		string str = ""; char C; int PosX, PosY, car;

		do {
			car = _getch();
			PosX = WhereX(); PosY = WhereY();
			if (car == 13) {
				if (str == "0");
				else if (str.length() < 6 || str.length() > 10) {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! INGRESA UN TEL\220FONO V\265LUDO";
					gotoxy(PosX, PosY);
					car = 12;
				}
			}
			else if (car != 8) {
				if (car >= 48 && car <= 57) {
					C = (char)car;
					cout << C;
					str += C;
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX + 1, PosY);
				}
				else {
					gotoxy(PosX, PosY + 1); cout << "\255ATENCI\340N! INGRESASTE CAR\265CTERES NO PERMITIDOS";
					gotoxy(PosX, PosY);
				}
			}
			else {
				if (str.length() > 0) {
					cout << "\b \b";
					str.erase(str.length() - 1);
					gotoxy(PosX, PosY + 1); cout << "                                                ";
					gotoxy(PosX - 1, PosY);
				}
			}
		} while (car != 13);
		return str;
	}
};

class Articulo {
private:
	friend class Clientes;
	string articulos, precio, clave_articulo, Fecha, Dia, Mes, Anio;
public:
	Articulo() : articulos(""), precio(""), clave_articulo(""), Fecha(""), Dia(""), Mes(""), Anio("") {}
	void pedir_articulo() {
		Validar N; string ent = ""; int n = 0;

		system("CLS");
		cout << "\nIngresa la clave del Articulo :" << " ";
		clave_articulo = N.Mixto();
		system("CLS");
		cout << "\n Descripcion del Articulo :" << " ";
		articulos = N.Mixto();
		system("CLS");
		cout << " Ingresa el Precio del Articulo :$" << " ";
		precio = N.NumFloat();
		system("CLS");
		cout << " Ingresa fecha de venta :DD/MM/A\245O " << endl;
		do {
			cout << " Ingresa D\241a del mes [1-31]:" << " ";
			ent = N.Numeros();
			n = atoi(ent.c_str());
			if (n < 1 || n > 31)
				cout << " Error,Ingrese D\241a del mes correcto " << endl;
		} while (n<1 || n>31);
		Dia = ent;
		do {
			cout << " Ingresa el mes [1-12] :" << " ";
			ent = N.Numeros();
			n = atoi(ent.c_str());
			if (n < 1 || n > 12)
				cout << " Error,Ingrese n\243mero de mes correcto " << endl;
		} while (n<1 || n>12);
		Mes = ent;
		do {
			cout << " Ingresa el A\244o [2000-2020] :" << " ";
			ent = N.Numeros();
			n = atoi(ent.c_str());
			if (n < 1 || n > 12)
				cout << " Error,A\244o fuera del rango" << endl;
		} while (n<2000 || n >2020);
		Anio = ent;
		Fecha = Dia + '/' + Mes + '/' + Anio;
	}
	float getPrecio() { return atof(precio.c_str()); }
	string getDescripcion() { return articulos; }
};
class Clientes {
private:
	float IVA, ImporteBruto, ImporteTotal;
	string NombreCompleto, CorreoElectronico, DireccionCompleta, status;
	deque<string> Telefono;
	int NumeroCliente;
	deque<Articulo> Articulos;
	void setValores() {
		for (int i = 0; i < Articulos.size(); i++)
			this->ImporteBruto += Articulos[i].getPrecio();

		this->ImporteTotal = (1 + IVA) * ImporteBruto;
	}
	void setEstado() {
		Validar N; string Pago;

		setValores();
		system("CLS");
		cout << "\n  El importe total por los art\241culos es: $" << ImporteTotal << endl
			<< "  Pagar\240 con:\n"
			<< "    1. Tarjeta de cr\202dito" << endl
			<< "    2. Efectivo" << endl
			<< "  Forma de Pago: ";
		Pago = N.Numeros();
		switch (atoi(Pago.c_str())) {
		case 1:
			this->status = "PAGADO";
			break;
		case 2:
			system("CLS");
			cout << "\n  \250Con cu\240nto pagar\240s? $";
			Pago = N.NumFloat();
			if (atof(Pago.c_str()) >= ImporteTotal) {
				cout << "\n  Ha saldado la cuenta." << endl;
				this->status = "PAGADO";
			}
			else {
				cout << "\n  No le alcanza el efectivo.";
				this->status = "ADEUDO";
			}
		}

		if (ReturnMenu("mostrar la factura") != 'N')
			Factura();

	}
public:
	Clientes() : NombreCompleto(""), CorreoElectronico(""), NumeroCliente(0), DireccionCompleta(""), IVA(0), ImporteBruto(0), ImporteTotal(0), status("") { Telefono.clear(); Articulos.clear(); }
	~Clientes() { Telefono.clear(); } // Como la cola Telefono es dinámica, se debe de limpiar cuando ya no se utilice
	void setDatos(string nom, string a_pat, string a_mat, string cor_ele, int alea, string colonia, string calle, string num_int, string num_ext, string cod_pos, string muni_del, string estado, deque<string> tel) {
		NombreCompleto = nom + " " + a_pat + " " + a_mat;
		CorreoElectronico = cor_ele;
		NumeroCliente = alea;
		DireccionCompleta = "Col. " + colonia + " " + calle + " No. Int. " + num_int + " No.Ext. " + num_ext + " C.P. " + cod_pos + " " + muni_del + ", " + estado;
		Telefono.swap(tel);
		if (muni_del == "Actopan") IVA = .16;
		else IVA = .17;
	}
	void setArticulo(deque<Articulo> Art) { Articulos = Art; setEstado(); }
	void Factura() {
		string producto = "", fechaActual = FechaHoraActual();

		system("CLS");
		cout << "\n  EMPRESA WALMART S.A. de C.V."
			<< "\n  Tipo de Venta: Compra de art\241culos" << endl
			<< "\n  Fecha y hora actual de la Factura: " << fechaActual
			<< "\n\n  Nombre del Cliente: " << NombreCompleto
			<< "\n  Direcci\242n fiscal del cliente: " << DireccionCompleta
			<< "\n  Art\241culo(s): ";
		for (int i = 0; i < Articulos.size(); i++) {
			producto = Articulos[i].getDescripcion();
			if (i == Articulos.size() - 1)
				cout << producto << "." << endl;
			else
				cout << producto << ", ";
		}

		cout << "\n  Importe Bruto = $" << ImporteBruto
			<< "\n  IVA = $" << (IVA * ImporteBruto)
			<< "\n  ------------------------------------------" << endl
			<< "Importe Total = $" << ImporteTotal << endl
			<< "\n  Estado de la compra: " << status << endl;
	}
	void Mostrar() {
		system("CLS");
		cout << "\n  Datos del Cliente" << ":"
			<< "\n  ================================================"
			<< "\n\tN\243mero de cliente: " << NumeroCliente
			<< "\n\tNombre: " << NombreCompleto << endl
			<< "\tCorreo Electr\242nico: " << CorreoElectronico << endl
			<< "\tDirecci\242n: " << DireccionCompleta << endl
			<< "\tTel\202fono(s): ";
		if (Telefono.size() == 0)
			cout << "No hay tel\202no registrado" << endl;
		else
			for (int t = 0; t < Telefono.size(); t++)
				if (t != Telefono.size() - 1)
					cout << Telefono[t] << ", ";
				else
					cout << Telefono[t] << "." << endl;
		
		system("PAUSE > NULL");
	}
	inline int getNumClien() { return NumeroCliente; }
	inline string getNombre() { return NombreCompleto; }
} Walmart;