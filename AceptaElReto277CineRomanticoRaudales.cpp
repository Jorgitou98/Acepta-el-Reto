#include <iostream>
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
#include <algorithm>
#include <vector>
using namespace std;

bool resuelveCaso() {
	int N;
	cin >> N;
		if (N == 0)
			return false;
	char aux;
	int horas, minutos, dur, ini;
	vector <pair<int, int>> pelis;
	for (int i = 0; i < N; ++i) {
		cin >> horas >> aux >> minutos >> dur;
		ini = horas * 60 + minutos;
		pelis.push_back({ ini, dur});
	}
	sort(pelis.begin(), pelis.end());
	// 1441 = 24*60 +1 (horas del dia)
	vector <int> V;
	/*Matriz <int> M(N+1, 1441);
	for (int i = 0; i < N + 1; ++i) M[i][0] = 0;*/
	for (int j = 0; j < 1451; ++j) V.push_back(0);

	for (int i = 1; i < N+1; ++i)
		for (int j = 1450; j > 0; --j) {
			if (j >= pelis[i-1].first + pelis[i-1].second + 10)
				V[j] = max(V[j], V[pelis[i-1].first] + pelis[i-1].second);
		}
	cout << V[1450] << '\n';

		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
