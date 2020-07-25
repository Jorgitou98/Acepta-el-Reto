#include <iostream>
#include <vector>
#include <climits>
#ifndef GRAFODIRIGIDOVALORADO_H_
#define GRAFODIRIGIDOVALORADO_H_

#include <memory>
#include <stdexcept>

template <typename Valor>
class AristaDirigida_impl;

template <typename Valor>
class AristaDirigida {
public:
	AristaDirigida();
	AristaDirigida(int v, int w, Valor valor);
	int from() const;
	int to() const;
	Valor valor() const;
	void print(std::ostream & o = std::cout) const;
private:
	std::shared_ptr<AristaDirigida_impl<Valor>> pimpl;
};

template <typename Valor>
inline std::ostream & operator<<(std::ostream & o, AristaDirigida<Valor> const& ar) {
	ar.print(o);
	return o;
}

template <typename Valor>
inline bool operator<(AristaDirigida<Valor> const& a, AristaDirigida<Valor> const& b)
{
	return a.valor() < b.valor();
}

template <typename Valor>
inline bool operator>(AristaDirigida<Valor> const& a, AristaDirigida<Valor> const& b)
{
	return a.valor() > b.valor();
}


template <typename Valor>
using AdysDirVal = std::vector<AristaDirigida<Valor>>;  // lista de adyacentes a un vértice

template <typename Valor>
class GrafoDirigidoValorado {
public:

	/**
	 * Crea un grafo con V vértices.
	 */
	GrafoDirigidoValorado(int v) : _V(v), _E(0), _ady(_V) {}

	/**
	 * Devuelve el número de vértices del grafo.
	 */
	int V() const { return _V; }

	/**
	 * Devuelve el número de aristas del grafo.
	 */
	int E() const { return _E; }

	/**
	 * Añade la arista dirigida v-w al grafo.
	 * @throws invalid_argument si algún vértice no existe
	 */
	void ponArista(AristaDirigida<Valor> arista);

	/**
	 * Comprueba si hay arista de v a w.
	 */
	bool hayArista(int v, int w) const;

	/**
	 * Devuelve la lista de adyacencia de v.
	 * @throws invalid_argument si v no existe
	 */
	AdysDirVal<Valor> const& ady(int v) const;

	/**
	 * Devuelve el grafo dirigido inverso.
	 */
	GrafoDirigidoValorado<Valor> inverso() const;

	/**
	 * Muestra el grafo en el stream de salida o
	 */
	void print(std::ostream & o = std::cout) const;

private:
	int _V;   // número de vértices
	int _E;   // número de aristas
	std::vector<AdysDirVal<Valor>> _ady;   // vector de listas de adyacentes

};

/**
 * Para mostrar grafos por la salida estándar.
 */
template <typename Valor>
inline std::ostream & operator<<(std::ostream & o, GrafoDirigidoValorado<Valor> const& g) {
	g.print(o);
	return o;
}


// IMPLEMENTACIÓN

template <typename Valor>
AristaDirigida<Valor>::AristaDirigida()
	: pimpl(nullptr) {}

template <typename Valor>
AristaDirigida<Valor>::AristaDirigida(int v, int w, Valor valor)
	: pimpl(std::make_shared<AristaDirigida_impl<Valor>>(v, w, valor)) {}

template <typename Valor>
int AristaDirigida<Valor>::from() const { return pimpl->from(); }

template <typename Valor>
int AristaDirigida<Valor>::to() const { return pimpl->to(); }

template <typename Valor>
Valor AristaDirigida<Valor>::valor() const { return pimpl->valor(); }

template <typename Valor>
void AristaDirigida<Valor>::print(std::ostream & o) const { pimpl->print(o); }


template <typename Valor>
class AristaDirigida_impl {
public:
	AristaDirigida_impl(int v, int w, Valor valor) : v(v), w(w), _valor(valor) {};
	int from() const { return v; }
	int to() const { return w; }
	Valor valor() const { return _valor; }
	void print(std::ostream& o) const {
		o << "(" << v << ", " << w << ", " << _valor << ")";
	}
private:
	int v, w;
	Valor _valor;
};


template <typename Valor>
void GrafoDirigidoValorado<Valor>::ponArista(AristaDirigida<Valor> arista) {
	int v = arista.from();
	int w = arista.to();
	if (v >= _V || w >= _V) throw std::invalid_argument("Vertice inexistente");
	++_E;
	_ady[v].push_back(arista);
}

template <typename Valor>
bool GrafoDirigidoValorado<Valor>::hayArista(int v, int w) const {
	for (auto a : _ady[v])
		if (a.to() == w) return true;
	return false;
}

template <typename Valor>
AdysDirVal<Valor> const& GrafoDirigidoValorado<Valor>::ady(int v) const {
	if (v >= _V) throw std::invalid_argument("Vertice inexistente");
	return _ady[v];
}

template <typename Valor>
GrafoDirigidoValorado<Valor> GrafoDirigidoValorado<Valor>::inverso() const {
	GrafoDirigidoValorado R(_V);
	for (auto v = 0; v < _V; ++v) {
		for (auto a : _ady[v]) {
			R.ponArista(AristaDirigida<Valor>(a.to(), a.from(), a.valor()));
		}
	}
	return R;
}

template <typename Valor>
void GrafoDirigidoValorado<Valor>::print(std::ostream & o) const {
	o << _V << " vértices, " << _E << " aristas\n";
	for (auto v = 0; v < _V; ++v) {
		o << v << ": ";
		for (auto a : _ady[v]) {
			o << a << " ";
		}
		o << "\n";
	}
}


#endif /* GRAFODIRIGIDOVALORADO_H_ */
#ifndef INDEXPQ_H_
#define INDEXPQ_H_



// T es el tipo de las prioridades
// Comparator dice cuándo un valor de tipo T es más prioritario que otro
template <typename T = int, typename Comparator = std::less<T>>
class IndexPQ {
public:
	// registro para las parejas < elem, prioridad >
	struct Par {
		int elem;
		T prioridad;
	};

private:
	// vector que contiene los datos (pares < elem, prio >)
	std::vector<Par> array;     // primer elemento en la posición 1

	// vector que contiene las posiciones en array de los elementos
	std::vector<int> posiciones;   // un 0 indica que el elemento no está

	/* Objeto función que sabe comparar prioridades.
	 antes(a,b) es cierto si a es más prioritario que b */
	Comparator antes;

public:
	IndexPQ(int N, Comparator c = Comparator()) : array(1), posiciones(N, 0), antes(c) {}

	IndexPQ(IndexPQ<T, Comparator> const&) = default;

	IndexPQ<T, Comparator>& operator=(IndexPQ<T, Comparator> const&) = default;

	~IndexPQ() = default;

	// e debe ser uno de los posibles elementos
	void push(int e, T const& p) {
		if (posiciones.at(e) != 0)
			throw std::invalid_argument("No se pueden insertar elementos repetidos.");
		else {
			array.push_back({ e, p });
			posiciones[e] = array.size() - 1;
			flotar(array.size() - 1);
		}
	}

	void update(int e, T const& p) {
		int i = posiciones.at(e);
		if (i == 0) // el elemento e se inserta por primera vez
			push(e, p);
		else {
			array[i].prioridad = p;
			if (i != 1 && antes(array[i].prioridad, array[i / 2].prioridad))
				flotar(i);
			else // puede hacer falta hundir a e
				hundir(i);
		}
	}

	int size() const {
		return array.size() - 1;
	}

	bool empty() const {
		return size() == 0;
	}

	Par const& top() const {
		if (size() == 0)
			throw std::domain_error("No se puede consultar el primero de una cola vacia");
		else return array[1];
	}

	void pop() {
		if (size() == 0) throw std::domain_error("No se puede eliminar el primero de una cola vacía.");
		else {
			posiciones[array[1].elem] = 0; // para indicar que no está
			if (size() > 1) {
				array[1] = std::move(array.back());
				posiciones[array[1].elem] = 1;
				array.pop_back();
				hundir(1);
			}
			else
				array.pop_back();
		}
	}

private:

	void flotar(int i) {
		Par parmov = std::move(array[i]);
		int hueco = i;
		while (hueco != 1 && antes(parmov.prioridad, array[hueco / 2].prioridad)) {
			array[hueco] = std::move(array[hueco / 2]); posiciones[array[hueco].elem] = hueco;
			hueco /= 2;
		}
		array[hueco] = std::move(parmov); posiciones[array[hueco].elem] = hueco;
	}

	void hundir(int i) {
		Par parmov = std::move(array[i]);
		int hueco = i;
		int hijo = 2 * hueco; // hijo izquierdo, si existe
		while (hijo <= size()) {
			// cambiar al hijo derecho de i si existe y va antes que el izquierdo
			if (hijo < size() && antes(array[hijo + 1].prioridad, array[hijo].prioridad))
				++hijo;
			// flotar el hijo si va antes que el elemento hundiéndose
			if (antes(array[hijo].prioridad, parmov.prioridad)) {
				array[hueco] = std::move(array[hijo]); posiciones[array[hueco].elem] = hueco;
				hueco = hijo; hijo = 2 * hueco;
			}
			else break;
		}
		array[hueco] = std::move(parmov); posiciones[array[hueco].elem] = hueco;
	}

};

#endif /* INDEXPQ_H_ */

using namespace std;


vector<int> dijsktraElem(int posIni, int n, GrafoDirigidoValorado<int> const& g) {
	vector<AristaDirigida<int>> aristaTo(n);
	vector<int> distTo(n, INT_MAX);
	IndexPQ <int> pq(n);
	distTo[posIni] = 0;
	pq.push(posIni, 0);

	while (!pq.empty()) {
		int v = pq.top().elem;
		pq.pop();
		for (AristaDirigida<int> a : g.ady(v)) {
			int v1 = a.from(); int v2 = a.to();
			if (distTo[v2] > distTo[v1] + a.valor()) {
				distTo[v2] = distTo[v1] + a.valor();
				aristaTo[v2] = a;
				pq.update(v2, distTo[v2]);
			}
		}
	}
	return distTo;
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!std::cin) // fin de la entrada
		return false;
	GrafoDirigidoValorado<int> g1(n), g2(n);
	int c;
	cin >> c;
	int ini, fin, val;
	for (int j = 0; j < c; ++j) {
		cin >> ini >> fin >> val;
		g1.ponArista(AristaDirigida<int>(ini - 1, fin - 1, val));
		g2.ponArista(AristaDirigida<int>(fin - 1, ini - 1, val));
	}
	int o, p, cont = 0;
	cin >> o >> p;
	vector<int> distTo1(n, INT_MAX);
	IndexPQ <int> pq1(n);
	distTo1[o-1] = 0;
	pq1.push(o-1, 0);

	while (!pq1.empty()) {
		int v = pq1.top().elem;
		pq1.pop();
		for (AristaDirigida<int> a : g1.ady(v)) {
			int v1 = a.from(); int v2 = a.to();
			if (distTo1[v2] > distTo1[v1] + a.valor()) {
				distTo1[v2] = distTo1[v1] + a.valor();
				pq1.update(v2, distTo1[v2]);
			}
		}
	}

	vector<int> distTo2(n, INT_MAX);
	IndexPQ <int> pq2(n);
	distTo2[o - 1] = 0;
	pq2.push(o - 1, 0);

	while (!pq2.empty()) {
		int v = pq2.top().elem;
		pq2.pop();
		for (AristaDirigida<int> a : g2.ady(v)) {
			int v1 = a.from(); int v2 = a.to();
			if (distTo2[v2] > distTo2[v1] + a.valor()) {
				distTo2[v2] = distTo2[v1] + a.valor();
				pq2.update(v2, distTo2[v2]);
			}
		}
	}

	bool imposible = false;
	for (int i = 0; i < p; ++i) {
		cin >> ini;
		if (!imposible) {
			int ida = distTo1[ini - 1];
			int vuelta = distTo2[ini-1];
			if (ida == INT_MAX || vuelta == INT_MAX) imposible = true;
			else cont += ida + vuelta;
		}
	}
	if (imposible) cout << "Imposible" << endl;
	else cout << cont << endl;
	return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
