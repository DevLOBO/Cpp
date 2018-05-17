bool CompararStrings(string, string);

// Se crea una clase que almacenará los objetos Walmart.
class Lista {
public:
	class Iterator;
private:
	class Cell {
		friend class Iterator;
		friend class Lista;
		Clientes t;
		Cell *next;
		Cell() : next(NULL) {}
	};
	Cell *first, *last;
public:
	class Iterator {
	private:
		friend class Lista;
		Cell *ptr;
	public:
		Clientes& operator*() { return ptr->next->t; }
		//Clientes& operator->() { return &ptr->next->t; }
		bool operator!=(Iterator q) { return ptr != q.ptr; }
		bool operator==(Iterator q) { return ptr == q.ptr; }
		Iterator(Cell *p = NULL) : ptr(p) {}
		Iterator operator++() {
			ptr = ptr->next;
			return *this;
		}
		Iterator operator++(int) {
			Iterator q = *this;
			ptr = ptr->next;
			return q;
		}
	};
	Lista() { first = new Cell; last = first; }
	~Lista() {
		Cell *s = NULL, *r = Inicio().ptr->next;
		while (!(r != Fin().ptr->next)) {
			s = r->next;
			delete r;
			r = s;
		}
	}
	Iterator Insertar(Iterator p, Clientes t) {
		Cell *q = p.ptr->next, *c = new Cell;
		p.ptr->next = c;
		c->next = q;
		c->t = t;
		if (q == NULL) last = c;
		return p;
	}
	Iterator Borrar(Iterator p) {
		Cell *q = p.ptr->next;
		if (Tamaño() == 1) {
			delete first;
			return (Iterator)first;
		}
		else {
			if (q == last) last = p.ptr;
			p.ptr->next = q->next;
			delete q;
			return p;
		}
	}
	bool Repetido(string nom) {
		Iterator p = Inicio(); Clientes t;
		while (p != last) {
			t = *p++;
			if (CompararStrings(nom, t.getNombre()))
				return true;
		}
		return false;
	}
	bool Repetido(int num) {
		Iterator p = Inicio(); Clientes t;
		while (p != last) {
			t = *p++;
			if (num == t.getNumClien())
				return true;
		}
		return false;
	}
	void Mostrar() {
		Iterator p = Inicio(); Clientes t;
		while (p != last) {
			t = *p++;
			t.Mostrar();
		}
	}
	void Buscar_Mostrar(string nom) {
		Iterator p = Inicio(); Clientes t; bool indicador = true;
		while (p != last) {
			t = *p++;
			if (CompararStrings(nom, t.getNombre())) {
				indicador = false;
				t.Mostrar();
				break;
			}
		}
		if (indicador)
			cout << "\nUsuario no encontrado. El cleente no est\240 registrado." << endl;
	}
	void Buscar_Mostrar(int num) {
		Iterator p = Inicio(); Clientes t; bool indicador = true;
		while (p != last) {
			t = *p++;
			if (num == t.getNumClien()) {
				t.Mostrar();
				indicador = false;
				break;
			}
		}
		if (indicador)
			cout << "\nUsuario no encontrado. El cleente no est\240 registrado." << endl;
	}
	void Buscar_Factura(int num) {
		Iterator p = Inicio(); Clientes t; bool indicador = true;

		while (p != last) {
			t = *p++;
			if (num == t.getNumClien()) {
				t.Factura();
				indicador = false;
				break;
			}
		}
	}
	bool Modificar_Articulos(int num, deque<Articulo> A) {
		Iterator p = Inicio(); Clientes t; bool indicador = true;

		while (p != last) {
			t = *p++;
			if (num == t.getNumClien()) {
				t.setArticulo(A);
				indicador = false;
				break;
			}
		}
		if (indicador) {
			cout << "\nUsuario no encontrado. El cleente no est\240 registrado." << endl;
			system("PAUSE > NULL");
		}
		else
			cout << "\n Se le ha atribuido los art\241culos correctamente." << endl;
		
		return indicador;
	}
	Iterator Inicio() { return Iterator(first); }
	Iterator Fin() { return Iterator(last); }
	int Tamaño() {
		int sz = 0;
		Iterator p = Inicio();
		while (p++ != Fin()) sz++;
		return sz;
	}
};