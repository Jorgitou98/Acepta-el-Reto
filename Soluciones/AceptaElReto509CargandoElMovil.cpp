#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

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





bool resuelveCaso() {
	int f, c;
	cin >> c;
		if (!std::cin) // fin de la entrada
			return false;
	cin >> f;
	Matriz<int> bateria(f, c);
	for (int i = 0; i < f; ++i)
		for (int j = 0; j < c; ++j)
			cin >> bateria[i][j];

	Matriz<int> maxMinBateria(f, c, INT_MAX);
	maxMinBateria[f - 1][c - 1] = 0;
	for (int i = f-1; i >= 0; --i)
		for (int j = c-1; j >= 0; --j) {
			if (maxMinBateria.posCorrecta(i + 1, j) && maxMinBateria.posCorrecta(i, j + 1)) {
				maxMinBateria[i][j] = max(max(min(maxMinBateria[i + 1][j], maxMinBateria[i][j + 1]) - bateria[i][j],2-bateria[i][j]), 2);
			}
			else if (maxMinBateria.posCorrecta(i + 1, j)) {
				maxMinBateria[i][j] = max(max(maxMinBateria[i + 1][j] - bateria[i][j], 2 - bateria[i][j]), 2);
			}
			else if (maxMinBateria.posCorrecta(i, j + 1)) {
				maxMinBateria[i][j] = max(max(maxMinBateria[i][j+1] - bateria[i][j], 2 - bateria[i][j]), 2);
			}
		}

	cout << max(maxMinBateria[0][0], 2) << '\n';


		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
