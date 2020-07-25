#include <iostream>
#include <vector>
#include <stdexcept>

using Adys = std::vector<int>;  // lista de adyacentes a un vértice

class Grafo {

	int _V;   // número de vértices
	int _E;   // número de aristas
	std::vector<Adys> _ady;   // vector de listas de adyacentes

public:

	/**
	 * Crea un grafo con V vértices.
	 */
	Grafo(int v) : _V(v), _E(0), _ady(_V) {}

	/**
	 * Devuelve el número de vértices del grafo.
	 */
	int V() const { return _V; }

	/**
	 * Devuelve el número de aristas del grafo.
	 */
	int E() const { return _E; }


	/**
	 * Añade la arista v-w al grafo.
	 * @throws invalid_argument si algún vértice no existe
	 */
	void ponArista(int v, int w) {
		if (v >= _V || w >= _V)
			throw std::invalid_argument("Vertice inexistente");
		++_E;
		_ady[v].push_back(w);
		_ady[w].push_back(v);
	}


	/**
	 * Devuelve la lista de adyacencia de v.
	 * @throws invalid_argument si v no existe
	 */
	Adys const& ady(int v) const {
		if (v >= _V)
			throw std::invalid_argument("Vertice inexistente");
		return _ady[v];
	}


	/**
	 * Muestra el grafo en el stream de salida o (para depurar)
	 */
	void print(std::ostream & o = std::cout) const {
		o << _V << " vértices, " << _E << " aristas\n";
		for (auto v = 0; v < _V; ++v) {
			o << v << ": ";
			for (auto w : _ady[v]) {
				o << w << " ";
			}
			o << "\n";
		}
	}

};

/**
 * Para mostrar grafos por la salida estándar
 */
inline std::ostream & operator<<(std::ostream & o, Grafo const& g) {
	g.print(o);
	return o;
}

using namespace std;

void recorreEnProfundidad(int &visitados, Grafo const& g, int inicio, vector<bool> & marcados) {
	visitados++;
	marcados[inicio] = true;
	for (int elem : g.ady(inicio))
		if (!marcados[elem]) recorreEnProfundidad(visitados, g, elem, marcados);
}


void resuelveCaso() {
	int n, m, v1, v2;
	cin >> n >> m;
	Grafo g(n+1);
	for (int i = 0; i < m; ++i) {
		cin >> v1 >> v2;
		g.ponArista(v1, v2);
	}
	vector <bool> marcados(n+1, false);
	int maxAmigos = 0, visitados;
	for (int i = 1; i <= n; ++i) {
		visitados = 0;
		recorreEnProfundidad(visitados, g, i, marcados);
		if (visitados > maxAmigos) maxAmigos = visitados;
	}
	cout << maxAmigos << '\n';
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
