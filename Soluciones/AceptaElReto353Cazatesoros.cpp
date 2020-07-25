#include <iostream>
#include <vector>
#include <algorithm>
//
//  Matriz.h
//
//  Implementación de matrices (arrays bidimensionales)
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Created by Alberto Verdejo on 26/6/15.
//  Copyright (c) 2015 Alberto Verdejo. All rights reserved.
//

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


using namespace std;

struct tCofre{
	int profundidad, oro;
	bool cogido;
};

bool resuelveCaso() {
	int T;
	cin >> T;
		if (!std::cin) // fin de la entrada
			return false;
	int n;
	cin >> n;
	int p, o;
	vector <tCofre> cofres;
	for (int i = 0; i < n; ++i) {
		cin >> p >> o;
		cofres.push_back({ p,o, false });
	}
	Matriz<int> M(n+1, T+1);
	for (int i = 0; i < n+1; ++i) M[i][0] = 0;
	for (int j = 1; j < T+1; ++j) M[0][j] = 0;

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < T+1; ++j) {
			if (3 * cofres[i - 1].profundidad > j) M[i][j] = M[i - 1][j];
			else M[i][j] = max( M[i - 1][j],  M[i - 1][j - 3 * cofres[i - 1].profundidad] + cofres[i - 1].oro );
		}
	}
	int j = T;
	int cont = 0;
	for (int i = n; i > 0; --i) {
		if (M[i][j] != M[i - 1][j]) {
			cofres[i-1].cogido = true;
			j -= 3 * cofres[i - 1].profundidad;
			cont++;
		}
	}
	cout << M[n][T] << '\n';
	cout << cont << '\n';
	for (int i = 0; i < n; ++i)
		if (cofres[i].cogido) cout << cofres[i].profundidad << " " << cofres[i].oro << '\n';
	cout << "----"<< '\n';
		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
