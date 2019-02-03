#include <iostream>
#include <string>
#include <functional>
//
//  PriorityQueue.h
//
//  Implementación de colas con prioridad de mínimos (el elemento más
//  prioritario es el menor) mediante montículos binarios
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2015-2018  Alberto Verdejo
//


#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>

// Comparator dice cuándo un valor de tipo T es más prioritario que otro
template <typename T = int, typename Comparator = std::less<T>>
class PriorityQueue {

	// vector que contiene los datos
	std::vector<T> array;     // primer elemento en la posición 1

	/* Objeto función que sabe comparar elementos.
	 antes(a,b) es cierto si a es más prioritario que b (a debe salir antes que b) */
	Comparator antes;

public:

	PriorityQueue(Comparator c = Comparator()) : array(1), antes(c) {}

	/* Constructor a partir de un vector de elementos */
	PriorityQueue(std::vector<T> const& v_ini, Comparator c = Comparator()) :
		array(v_ini.size() + 1), antes(c) {
		for (auto i = 0; i < v_ini.size(); ++i)
			array[i + 1] = v_ini[i];
		monticulizar();
	}

	PriorityQueue(PriorityQueue<T, Comparator> const&) = default;

	PriorityQueue<T, Comparator> & operator=(PriorityQueue<T, Comparator> const&) = default;

	~PriorityQueue() = default;


	/* Insertar el elemento x (que incluye su prioridad).
	 Si no hay espacio, el array se agranda. */
	void push(T const& x) {
		array.push_back(x);
		flotar(array.size() - 1);
	}

	/* Devuelve el número de elementos en la cola. */
	int size() const { return array.size() - 1; }

	/* Averigua si la cola con prioridad está vacía. */
	bool empty() const { return size() == 0; }

	/* Si la cola no es vacía, devuelve el elemento más prioritario. */
	T const& top()  const {
		if (empty()) throw std::domain_error("La cola vacia no tiene top");
		else return array[1];
	}

	/* Si la cola no es vacía, elimina el elemento más prioritario. */
	void pop() {
		if (empty())
			throw std::domain_error("Imposible eliminar el primero de una cola vacia");
		else {
			array[1] = std::move(array.back());
			array.pop_back();
			if (!empty()) hundir(1);
		}
	}

	/* Si la cola no es vacía, elimina y devuelve el elemento más prioritario. */
	void pop(T & prim) {
		if (empty())
			throw std::domain_error("Imposible eliminar el primero de una cola vacia");
		else {
			prim = std::move(array[1]);
			array[1] = std::move(array.back());
			array.pop_back();
			if (!empty()) hundir(1);
		}
	}

	/* Muestra el montículo por la salida o (solo para depurar) */
	void print(std::ostream & o) const {
		for (auto i = 1; i <= size(); ++i)
			o << array[i] << " ";
	}

private:

	/* Flota el elemento situado en la posición n del montículo. */
	void flotar(int i) {
		T elem = std::move(array[i]);
		int hueco = i;
		while (hueco != 1 && antes(elem, array[hueco / 2])) {
			array[hueco] = std::move(array[hueco / 2]);
			hueco /= 2;
		}
		array[hueco] = std::move(elem);
	}

	/* Hunde el elemento situado en la posición n del montículo. */
	void hundir(int i) {
		T elem = std::move(array[i]);
		int hueco = i;
		int hijo = 2 * hueco; // hijo izquierdo, si existe
		while (hijo <= size()) {
			// cambiar al hijo derecho si existe y va antes que el izquierdo
			if (hijo < size() && antes(array[hijo + 1], array[hijo]))
				++hijo;
			// flotar el hijo si va antes que el elemento hundiéndose
			if (antes(array[hijo], elem)) {
				array[hueco] = std::move(array[hijo]);
				hueco = hijo; hijo = 2 * hueco;
			}
			else break;
		}
		array[hueco] = std::move(elem);
	}

	/* Convierte un vector en un montículo. */
	void monticulizar() {
		for (auto i = size() / 2; i > 0; --i)
			hundir(i);
	}
};

template <typename T, typename Comparator>
inline std::ostream& operator<<(std::ostream & o, PriorityQueue<T, Comparator> const& a) {
	a.print(o);
	return o;
}



using namespace std;

struct tPaciente {
	string nombre;
	int gravedad;
	int cicloEntra;
};

bool operator > (tPaciente const& t1, tPaciente const& t2) {
	return t1.gravedad > t2.gravedad || (t1.gravedad == t2.gravedad && t1.cicloEntra < t2.cicloEntra);
}

bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
		char op;
		PriorityQueue <tPaciente, greater<tPaciente>> pq;
		tPaciente paciente;
		for (int i = 0; i < n; ++i) {
			cin >> op;
			if (op == 'I') {
				cin >> paciente.nombre >> paciente.gravedad;
				paciente.cicloEntra = i;
				pq.push(paciente);
			}
			else if (op == 'A') {
				cout << pq.top().nombre << '\n';
				pq.pop();
			}
		}
		cout << "----\n";

		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
