// CLASE AHORRO - Ejercicio 1
class Ahorro {
	private:
		string nombre;
		string cuenta;
		string banco;
		short plazo;
		double subtotal, ahorro, total;
	public:
		Ahorro() {
			nombre = "";
			cuenta = "";
			banco = "";
			plazo = 0;
			ahorro = 0;
			subtotal = 0;
			total = 0;
		}
		void setDatos(string n, string b, string c, short p, double s) {
			nombre = n;
			banco = b;
			cuenta = c;
			plazo = p;
			subtotal = s;
		}
		void Calcular() {
			if (plazo >= 1 && plazo <= 12) {
				ahorro = subtotal * 0.05;
				total = subtotal * 1.05;
			}
			else if (plazo >= 13 && plazo <= 24) {
				ahorro = subtotal * 0.1;
				total = subtotal * 1.1;
			}
			else {
				ahorro = subtotal * 0.15;
				total = subtotal = 1.15;
			}

		}
		void Mostrar(int NC, int tam) {
			system("CLS");
			cout << "\n  Cliente " << NC + 1 << ":\n";
			cout << "\tNombre: " << nombre << endl;
			cout << "\tBanco: " << banco << endl;
			cout << "\tN\243mero de cuenta: " << cuenta << endl;
			cout << "\tPlazo indicado: " << plazo << " meses" << endl;
			cout << "\tSubtotal: $" << subtotal << endl;
			cout << "\tAhoro: $" << ahorro << endl;
			cout << "\tPromedio de ahorro al mes: $" << subtotal / plazo << endl;
			cout << "\tTotal acumulado: $" << total;
			if (NC + 1 < tam)
				cout << "\n\n  Siguiente Cliente >>" << endl;
			else
				cout << "\n\n  \351ltimo cliente" << endl;
			system("PAUSE > NULL");
		}
};

// CLASE PARALELOGRAMO
class Paralelogramo {
	private:
		float altura, base;
		double area, perimetro;
	public:
		Paralelogramo() {
			altura = 0; base = 0;
			perimetro = 0; area = 0;
		}
		inline void setLados(float b, float h) { altura = h; base = b; }
		inline void Calcular() { area = base * altura; perimetro = 2 * base + 2 * altura; }
		void Mostrar(string Figura) {
			system("CLS");
			Calcular();
			cout << "\n  Los valores del " << Figura << " son:" << endl;
			cout << "\t\265rea = " << area << endl;
			cout << "\tPer\241metro = " << perimetro << endl;
		}
};

// CLASE ASIGNATURA
class Asignatura {
	private:
		float *calificacion, media;
		short AC, NA, tam;
	public:
		Asignatura() { calificacion = NULL; media = 0; AC = 0; NA = 0; tam = 0; }
		inline void setTam(short t) { tam = t; calificacion = new float[t]; }
		inline void setCalificacion(float calif, short pos) { calificacion[pos] = calif; }
		void Calcular() {
			for (short n = 0; n < tam; n++) {
				media += calificacion[n] / tam;
				if (calificacion[n] < 6)
					NA++;
				else
					AC++;
			}
		}
		void Mostrar() {
			system("CLS");
			Calcular();
			cout << "\n  El promedio del sal\242n es: " << media;
			cout << "\n  " << AC << " alumnos aprobaods y " << NA << " reprobados." << endl;
		}
};