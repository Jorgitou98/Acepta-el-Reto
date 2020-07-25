#include <iostream>
#ifndef CONJUNTOSDISJUNTOS_H_
#define CONJUNTOSDISJUNTOS_H_

#include <vector>
#include <iostream>

class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(int N) : nelems(N), ncjtos(nelems), tamMax(1), id(nelems, -1) {}

	// devuelve el número de conjuntos disjuntos
	int num_cjtos() const { return ncjtos; }

	//  devuelve el identificador del conjunto que contiene a p
	int buscar(int p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = buscar(id[p]);
	}

	// unir los conjuntos que contengan a p y q
	void unir(int p, int q) {
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) return;
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = int(i);
			if (tam(p) > tamMax) tamMax = tam(p);
		}
		else {
			id[j] += id[i]; id[i] = int(j);
			if (tam(q) > tamMax) tamMax = tam(q);
		}
		--ncjtos;
	}

	int tam(int p) const {
		return -id[buscar(p)];
	}

	bool unidos(int p, int q) const {
		return buscar(p) == buscar(q);
	}

	int componenteMasGrande() const {
		return tamMax;
	}

protected:
	int nelems;           // los elementos son 0 .. nelems-1
	int ncjtos;           // número de conjuntos disjuntos
	int tamMax;
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i

};


#endif
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


#include <cmath>
#include <stack>
bool resuelveCaso() {
	int N;
	std::cin >> N;
		if (!std::cin) // fin de la entrada
			return false;
	int M, K, n;
	std::cin >> M >> K >> n;
	M++;
	N++;
	ConjuntosDisjuntos c(N*M);
	Matriz<bool> mat(N, M, false);
	mat[0][0] = true;
	mat[N-1][M-1] = true;
	std::stack<std::pair<int,int>> pila;
	int v1, v2;
	for (int i = 0; i < n; ++i) {
		std::cin >> v1 >> v2;
		pila.push({ v1,v2 });
	}
	bool fin = false;
	int prim, seg;
	while (!pila.empty() && !fin) {
		prim = pila.top().first;
		seg = pila.top().second;
		for (int j = -K; j <= K && !fin; ++j) {
			for (int m = -K; m <= K && !fin; ++m) {
				if (sqrt(j*j + m * m) <= K && mat.posCorrecta(prim + j, seg + m) && mat[prim + j][seg + m]) {
					c.unir(prim * M + seg, (prim + j) * M + seg + m);
				}
				if (c.unidos(0, N * M - 1)) fin = true;
			}
		}
		mat[prim][seg] = true;
		pila.pop();
	}
	if (!fin) std::cout << "NUNCA SE PUDO" << std::endl;
	else std::cout << prim << " " << seg << std::endl;

		return true;
}
int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
