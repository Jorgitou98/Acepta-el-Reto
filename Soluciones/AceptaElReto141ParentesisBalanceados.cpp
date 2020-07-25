#include <iostream>
#include <stdexcept>  // std::domain_error
#include <string>
#include <utility>    // std::move
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

bool balanceado(string linea){
	stack <char> pila = stack <char>();
	for (char caracter : linea){
		if (caracter == '('){
			pila.push(')');
		}
		else if (caracter == '{'){
			pila.push('}');
		}
		else if (caracter == '['){
			pila.push(']');
		}
		else if (caracter == ')' || caracter == '}' || caracter == ']'){
			if (pila.empty() || pila.top() != caracter)	return false;
			else pila.pop();
		}
	}
	if (!pila.empty()) return false;
	return true;
}




bool resuelveCaso() {
	string linea;
	getline(cin, linea);
	if (!std::cin)
		return false;
	if (balanceado(linea)) cout << "YES\n";
	else cout << "NO\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
