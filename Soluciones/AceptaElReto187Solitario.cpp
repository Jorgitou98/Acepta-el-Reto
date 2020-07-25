

#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class stack {
protected:
	static const int TAM_INICIAL = 10; // tamaño inicial del array dinámico

	// número de elementos en la pila
	size_t nelems;

	// tamaño del array
	size_t capacidad;

	// puntero al array que contiene los datos (redimensionable)
	T * array;

public:

	// constructor: pila vacía
	stack() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

	// destructor
	~stack() {
		libera();
	}

	// constructor por copia
	stack(stack<T> const& other) {
		copia(other);
	}

	// operador de asignación
	stack<T> & operator=(stack<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// apilar un elemento
	void push(T const& elem) {
		if (nelems == capacidad)
			amplia();
		array[nelems] = elem;
		++nelems;
	}

	// consultar la cima
	T const& top() const {
		if (empty())
			throw std::domain_error("la pila vacia no tiene cima");
		return array[nelems - 1];
	}

	// desapilar el elemento en la cima
	void pop() {
		if (empty())
			throw std::domain_error("desapilando de la pila vacia");
		--nelems;
	}

	// consultar si la pila está vacía
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tamaño de la pila
	size_t size() const {
		return nelems;
	}

protected:

	void libera() {
		delete[] array;
	}

	// this está sin inicializar
	void copia(stack const& other) {
		capacidad = other.nelems + TAM_INICIAL;
		nelems = other.nelems;
		array = new T[capacidad];
		for (size_t i = 0; i < nelems; ++i)
			array[i] = other.array[i];
	}

	void amplia() {
		T * viejo = array;
		capacidad *= 2;
		array = new T[capacidad];
		for (size_t i = 0; i < nelems; ++i)
			array[i] = std::move(viejo[i]);
		delete[] viejo;
	}
};


struct tCarta{
	int valor;
	char palo;
};

int siguiente(int n){
	if (n != 7) return n + 1;
	else return 10;
}

void hacerMovimientos(){

}




bool resuelveCaso() {
	int palos;
	cin >> palos;
	if (palos == 0)
		return false;
	vector <tCarta> pilaMano;
	tCarta carta;
	stack <tCarta> pilaBastos = stack<tCarta>(), pilaOros = stack<tCarta>(), pilaCopas = stack<tCarta>(), pilaEspadas = stack<tCarta>(), cartasMesa = stack<tCarta>();
	for (int i = 0; i < 10 * palos; ++i){
		cin >> carta.valor >> carta.palo;
		pilaMano.push_back(carta);
	}
	bool ganado = false, perdido = false;
	while (!ganado && !perdido){
		bool colocado = false;
		for (int i = 0; i < pilaMano.size(); i = i + 2){
				cartasMesa.push(pilaMano[i]);
			if (i < pilaMano.size() - 1) cartasMesa.push(pilaMano[i + 1]);
				bool puedoPonerla = true;
				tCarta cartaDeArriba = cartasMesa.top();
				while (puedoPonerla && !cartasMesa.empty()){
					if (cartaDeArriba.palo == 'B'){
						if (pilaBastos.empty()){
							if (cartaDeArriba.valor == 1){
								pilaBastos.push(cartaDeArriba);
								cartasMesa.pop();
								colocado = true;
							}
							else puedoPonerla = false;
						}
						else{
							if (cartaDeArriba.valor == siguiente(pilaBastos.top().valor)){
								pilaBastos.push(cartaDeArriba);
								cartasMesa.pop();
								colocado = true;
							}
							else puedoPonerla = false;
						}
	
					}
					else if (cartaDeArriba.palo == 'O'){
						if (pilaOros.empty()){
							if (cartaDeArriba.valor == 1){
								pilaOros.push(cartaDeArriba);
								cartasMesa.pop();
								colocado = true;
							}
							else puedoPonerla = false;
						}
						else{
							if (cartaDeArriba.valor == siguiente(pilaOros.top().valor)){
								pilaOros.push(cartaDeArriba);
								cartasMesa.pop();
								colocado = true;
							}
							else puedoPonerla = false;
						}
					}
					else if (cartaDeArriba.palo == 'C'){
						if (pilaCopas.empty()){
							if (cartaDeArriba.valor == 1){
								pilaCopas.push(cartaDeArriba);
								cartasMesa.pop();
								colocado = true;
							}
							else puedoPonerla = false;
						}
						else{
							if (cartaDeArriba.valor == siguiente(pilaCopas.top().valor)){
								pilaCopas.push(cartaDeArriba);
								cartasMesa.pop();
								colocado = true;
							}
							else puedoPonerla = false;
						}
					}
					else if (cartaDeArriba.palo == 'E'){
						if (pilaEspadas.empty()){
							if (cartaDeArriba.valor == 1){
								pilaEspadas.push(cartaDeArriba);
								cartasMesa.pop();
								colocado = true;
							}
							else puedoPonerla = false;
						}
						else{
							if (cartaDeArriba.valor == siguiente(pilaEspadas.top().valor)){
								pilaEspadas.push(cartaDeArriba);
								cartasMesa.pop();
								colocado = true;
							}
							else puedoPonerla = false;
						}
					}
					if (cartasMesa.size() > 0)cartaDeArriba = cartasMesa.top();
				}
		}
		if (!colocado) perdido = true;
		else if (cartasMesa.size() == 0) ganado = true;
		else {
			int tam = cartasMesa.size();
			pilaMano.resize(tam);
			for (int i = 0; i < tam; ++i){
				pilaMano[cartasMesa.size() - 1] = cartasMesa.top();
				cartasMesa.pop();
			}
		}
	}
	if (ganado) cout << "GANA\n";
	if (perdido) cout << "PIERDE\n";


		return true;
}



int main() {
	while (resuelveCaso());
	return 0;
}
