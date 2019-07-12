#include <iostream>
#include <algorithm>
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
	std::vector<Object> & operator[](int f) {
		return datos[f];
	}

	// métodos que lanzan una excepción si la posición no existe
	Object const& at(int f, int c) const {
		return datos.at(f).at(c);
	}
	Object & at(int f, int c) { // este método da problemas cuando Object == bool
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
#include <vector>
using namespace std;
bool resuelveCaso() {
	int N;
	cin >> N;
		if (N == 0)
			return false;
	vector <int> cubos;
	int valor;
	for (int i = 0; i < N; ++i) {
		cin >> valor;
		cubos.push_back(valor);
	}
	Matriz<int> M(N, N);
	for (int i = 0; i < N; ++i) M[i][i] = cubos[i];

	for (int d = 1; d < N; ++d)
		for (int i = 0; i < N - d; ++i) {
			int j = i + d;
			int suma1, suma2;

			if (i + 1 == j) suma1 = cubos[i];
			else if (cubos[i + 1] >= cubos[j]) suma1 = cubos[i] + M[i + 2][j];
			else suma1 = cubos[i] + M[i + 1][j-1];

			if (j - 1 == i) suma2 = cubos[j];
			else if (cubos[j-1] >= cubos[i]) suma2 = cubos[j] + M[i][j-2];
			else suma2 = cubos[j] + M[i + 1][j - 1];

			M[i][j] = max(suma1, suma2);
		}

	cout << M[0][N - 1] << '\n';
		return true;
}
int main() {
  	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
