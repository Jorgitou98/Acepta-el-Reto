#include <iostream>
using namespace std;


struct bintree{
	int pi, di, pd, dd;
	bintree* hijo_izq = nullptr;
	bintree* hijo_der = nullptr;
};

bintree* leerArbol() {
	bintree* arbol = new bintree();
	cin >> arbol->pi >> arbol->di >> arbol->pd >> arbol->dd;
	if (arbol->pi == 0 && arbol->di == 0 && arbol->pd == 0 && arbol->dd == 0) {
		return nullptr;
	}
	if (arbol->pi == 0) arbol->hijo_izq = leerArbol();
	if (arbol->pd == 0) arbol->hijo_der = leerArbol();
	return arbol;
}

void libera_arbol(bintree* arbol) {
	if (arbol->hijo_izq != nullptr) libera_arbol(arbol->hijo_izq);
	if (arbol->hijo_der != nullptr) libera_arbol(arbol->hijo_der);
	delete(arbol);
}

bool balanceado(bintree* arbol, int & peso) {
	bool bal_izq = true, bal_der = true;
	int peso_izq = 0, peso_der = 0;

	if (arbol->pi != 0) peso_izq = arbol->pi;
	else bal_izq = balanceado(arbol->hijo_izq, peso_izq);

	if (arbol->pd != 0) peso_der = arbol->pd;
	else bal_der = balanceado(arbol->hijo_der, peso_der);

	peso = peso_izq + peso_der;
	return bal_izq && bal_der && (peso_izq * arbol->di == peso_der * arbol->dd);
}


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	bintree* arbol = leerArbol();
	while (arbol != nullptr) {
		int peso;
		if (balanceado(arbol, peso)) {
			cout << "SI\n";
		}
		else cout << "NO\n";
		libera_arbol(arbol);
		arbol = leerArbol();
	}

	return 0;
}
