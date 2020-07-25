#include <iostream>
#include <iomanip>
//#include "Matriz.h"
//#include "ConjuntosDisjuntos.h"
#include <vector>
#include <iostream>

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


using namespace std;

bool resuelveCaso() {
	int f, c;
	cin >> f;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> c;
	getchar(); // Fuera el salto de linea
	bool hayPetroleo = false;
	Matriz<char> mat(f, c);
	ConjuntosDisjuntos disj(f * c);
	char elem;
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			elem = getchar();
			mat[i][j] = elem;
			if (elem == '#') {
				hayPetroleo = true;
				if (mat.posCorrecta(i - 1, j - 1) && mat[i - 1][j - 1] == '#') disj.unir(i * c + j, (i - 1) * c + j - 1);
				if (mat.posCorrecta(i - 1, j) && mat[i - 1][j] == '#') disj.unir(i * c + j, (i - 1) * c + j);
				if (mat.posCorrecta(i - 1, j + 1) && mat[i - 1][j + 1] == '#') disj.unir(i * c + j, (i - 1) * c + j + 1);
				if (mat.posCorrecta(i, j - 1) && mat[i][j - 1] == '#') disj.unir(i * c + j, i * c + j - 1);
			}
		}
		getchar(); // Me quito el salto de linea
	}
	if (hayPetroleo) cout << disj.componenteMasGrande();
	else cout << "0";

	int k, v1, v2;
	cin >> k;
	if(k > 0) cout << " ";
	for (int i = 0; i < k; ++i) {
		cin >> v1 >> v2;
		v1--;
		v2--;
		mat[v1][v2] = '#';
		if (mat.posCorrecta(v1 - 1, v2 - 1) && mat[v1 - 1][v2 - 1] == '#') disj.unir(v1 * c + v2, (v1 - 1) * c + v2 - 1);
		if (mat.posCorrecta(v1 - 1, v2) && mat[v1 - 1][v2] == '#') disj.unir(v1 * c + v2, (v1 - 1) * c + v2);
		if (mat.posCorrecta(v1 - 1, v2 + 1) && mat[v1 - 1][v2 + 1] == '#') disj.unir(v1 * c + v2, (v1 - 1) * c + v2 + 1);
		if (mat.posCorrecta(v1, v2 - 1) && mat[v1][v2 - 1] == '#') disj.unir(v1 * c + v2, v1 * c + v2 - 1);
		if (mat.posCorrecta(v1, v2 + 1) && mat[v1][v2 + 1] == '#') disj.unir(v1 * c + v2, v1 * c + v2 + 1);
		if (mat.posCorrecta(v1 + 1, v2 - 1) && mat[v1 + 1][v2 - 1] == '#') disj.unir(v1 * c + v2, (v1 + 1) * c + v2 - 1);
		if (mat.posCorrecta(v1 + 1, v2) && mat[v1 + 1][v2] == '#') disj.unir(v1 * c + v2, (v1 + 1) * c + v2);
		if (mat.posCorrecta(v1 + 1, v2 + 1) && mat[v1 + 1][v2 + 1] == '#') disj.unir(v1 * c + v2, (v1 + 1) * c + v2 + 1);
		cout << disj.componenteMasGrande();
		if(i < k-1) cout << " ";
	}
	cout << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
