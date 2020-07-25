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

void marcaCompConexaBlanca(Grafo const& g, vector<bool>& marcados, int inicio, vector<char> const& imagen) {
	for (int elem : g.ady(inicio)) {
		if (!marcados[elem] && imagen[elem] == '.') {
			marcados[elem] = true;
			marcaCompConexaBlanca(g, marcados, elem, imagen);
		}
	}
}

bool resuelveCaso() {
	int ancho, alto;
	cin >> ancho;
		if (!std::cin) // fin de la entrada
			return false;
	cin >> alto;
	char pixel;
	vector<char> imagen;
	Grafo g(ancho * alto);
	for (int i = 0; i < alto; ++i) {
		for (int j = 0; j < ancho; ++j) {
			cin >> pixel;
			imagen.push_back(pixel);
			if (i > 0) g.ponArista(i*ancho + j, (i - 1)*ancho + j);
			if (i < alto - 1) g.ponArista(i*ancho + j, (i + 1)*ancho + j);
			if (j > 0) g.ponArista(i*ancho + j, i*ancho + j - 1);
			if(j < ancho -1) g.ponArista(i*ancho + j, i*ancho + j + 1);
		}
	}

	vector <bool> marcados(ancho * alto, false);
	int compConexas = 0;
	int i = 0;
	while (i < alto && compConexas < 2) {
		int j = 0;
		while (j < ancho && compConexas < 2) {
			if (!marcados[i*ancho + j] && imagen[i*ancho + j] == '.') {
				marcaCompConexaBlanca(g, marcados, i*ancho + j, imagen);
				compConexas++;
			}
			++j;
		}
		++i;
	}
	if (compConexas >= 2) cout << "SI\n";
	else cout << "NO\n";
		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
