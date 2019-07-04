#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>

template <typename Object>
class Matriz {
public:
	// crea una matriz con fils filas y cols columnas,
	// con todas sus celdas inicializadas al valor e
	Matriz(int fils, int cols, Object e = Object()) : datos(fils, std::vector<Object>(cols, e)) {}

	// operadores para poder utilizar notación M[i][j]
	std::vector<Object> const& operator[](int f) const {
		return datos[f];
	}
	std::vector<Object>& operator[](int f) {
		return datos[f];
	}

	// métodos que lanzan una excepción si la posición no existe
	Object const& at(int f, int c) const {
		return datos.at(f).at(c);
	}
	Object& at(int f, int c) { // este método da problemas cuando Object == bool
		return datos.at(f).at(c);
	}

	int numfils() const { return datos.size(); }
	int numcols() const { return numfils() > 0 ? datos[0].size() : 0; }

	bool posCorrecta(int f, int c) const {
		return 0 <= f && f < numfils() && 0 <= c && c < numcols();
	}

private:
	std::vector<std::vector<Object>> datos;
};

#endif

#include <climits>
using namespace std;

struct tMoneda {
	int valor, cantidad;
};


bool resuelveCaso() {
	int N;
	cin >> N;
	if (!std::cin) // fin de la entrada
		return false;
	vector<tMoneda> moneda(N);
	for (int i = 0; i < N; ++i) {
		cin >> moneda[i].valor;
	}
	for (int i = 0; i < N; ++i) {
		cin >> moneda[i].cantidad;
	}
	reverse(moneda.begin(), moneda.end());
	int C;
	cin >> C;
	Matriz<int> M(N + 1, C + 1);

	for (int i = 0; i < N + 1; ++i)
		M[i][0] = 0;

	for (int j = 1; j < C + 1; ++j)
		M[0][j] = INT_MAX;

	for (int i = 1; i < N + 1; ++i)
		for (int j = 1; j < C + 1; ++j) {
			int mini = INT_MAX;
			for (int k = 0; k <= moneda[i - 1].cantidad && k * moneda[i - 1].valor <= j; ++k) {
				if (M[i - 1][j - k * moneda[i - 1].valor] != INT_MAX) {
					mini = min(M[i - 1][j - k * moneda[i - 1].valor] + k, mini);
				}
			}
			M[i][j] = mini;
		}

	if (M[N][C] == INT_MAX) cout << "NO";
	else {
		vector<int> sol;
		int j = C;
		for (int i = N; i > 0; --i) {
			int mini = INT_MAX;
			int m = j;
			int p = 0;

			for (int k = 0; k <= moneda[i - 1].cantidad && k * moneda[i - 1].valor <= j; ++k) {
				if (M[i - 1][j - k * moneda[i - 1].valor] != INT_MAX) {
					if (M[i - 1][j - k * moneda[i - 1].valor] + k <= mini) {
						m = j - k * moneda[i - 1].valor;
						p = k;
					}
					mini = min(M[i - 1][j - k * moneda[i - 1].valor] + k, mini);
				}
			}
			sol.push_back(p);
			j = m;
		}
		cout << "SI ";
		for (int i = 0; i < sol.size(); ++i) {
			cout << sol[i];
			if (i < sol.size() - 1) cout << " ";
		}
	}
	cout << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}