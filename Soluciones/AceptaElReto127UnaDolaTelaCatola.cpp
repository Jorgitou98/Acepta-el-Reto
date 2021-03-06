#include <stdexcept>  // std::domain_error
#include <iostream>
#include <string>
using namespace std;

template <class T>
class queue {
protected:

	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente, que puede ser nullptr si
	el nodo es el último de la lista enlazada.
	*/
	struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const& elem, Nodo * si = nullptr) : elem(elem), sig(si) {}
		T elem;
		Nodo * sig;
	};

	// punteros al primer y último elemento
	Nodo * prim;
	Nodo * ult;

	// número de elementos en la cola
	size_t nelems;

public:

	// constructor: cola vacía
	queue() : prim(nullptr), ult(nullptr), nelems(0) {}

	// destructor
	~queue() {
		libera();
	}

	// constructor por copia
	queue(queue<T> const& other) {
		copia(other);
	}

	// operador de asignación
	queue<T> & operator=(queue<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// añadir un elemento al final de la cola
	void push(T const& elem) {
		Nodo * nuevo = new Nodo(elem);

		if (ult != nullptr)
			ult->sig = nuevo;
		ult = nuevo;
		if (prim == nullptr) // la cola estaba vacía
			prim = nuevo;
		++nelems;
	}

	// consultar el primero de la cola
	T const& front() const {
		if (empty())
			throw std::domain_error("la cola vacia no tiene primero");
		return prim->elem;
	}

	// eliminar el primero de la cola
	void pop() {
		if (empty())
			throw std::domain_error("eliminando de una cola vacia");
		Nodo * a_borrar = prim;
		prim = prim->sig;
		if (prim == nullptr) // la cola se ha quedado vacía
			ult = nullptr;
		delete a_borrar;
		--nelems;
	}

	// consultar si la cola está vacía
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tamaño de la cola
	size_t size() const {
		return nelems;
	}

	void cerrarCola(){
		ult->sig = prim;
	}

	void abrirCola(){
		ult->sig = nullptr;
	}

	void eliminaElemens(int camas, int palabras, int totalPersonas){
		if (empty()) throw std::domain_error("eliminando de una cola vacia");
		Nodo* ant = ult;
		Nodo* punt = prim;
		for (int i = 0; i < totalPersonas - camas; ++i){
				for (int j = 0; j < palabras - 1; ++j){
					ant = punt;
					punt = punt->sig;
				}
				if (punt == prim) {
					ant->sig = punt->sig;
					pop();
					punt = prim;
				}
				else{
					if (punt == ult) ult = ant;
					ant->sig = punt->sig;
					delete punt;
					punt = ant->sig;
					nelems--;
				}
		}
	}

	void muestraContenido() const{
		Nodo* punt = prim;
		for (int i = 0; i < nelems; ++i){
			cout << punt->elem;
			if (i < nelems - 1) cout << " ";
			punt = punt->sig;
		}
		cout << '\n';
	}

protected:

	void libera() {
		while (prim != nullptr) {
			Nodo * a_borrar = prim;
			prim = prim->sig;
			delete a_borrar;
		}
		ult = nullptr;
	}

	// this está sin inicializar
	void copia(queue const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			Nodo * act = other.prim; // recorre la cola original
			Nodo * ant = new Nodo(act->elem); // último nodo copiado
			prim = ant;
			while (act->sig != nullptr) {
				act = act->sig;
				ant->sig = new Nodo(act->elem);
				ant = ant->sig;
			}
			ult = ant;
			nelems = other.nelems;
		}
	}
};

void resuelveCaso() {
	string cad;
	int camas, palabras;
	cin >> cad;
	queue <string> cola = queue <string>();
	while (cad != "F"){
		cola.push(cad);
		cin >> cad;
	}
	cin >> camas >> palabras;
	if (camas >= cola.size()) cout << "TODOS TIENEN CAMA\n";
	else if (camas == 0) cout << "NADIE TIENE CAMA\n";
	else{
		cola.cerrarCola();
		cola.eliminaElemens(camas, palabras, cola.size());
		cola.abrirCola();
		cola.muestraContenido();
	}
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}

