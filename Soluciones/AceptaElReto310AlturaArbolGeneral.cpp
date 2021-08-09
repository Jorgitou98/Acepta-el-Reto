#include <iostream>
#include <algorithm>
using namespace std;


int alturaArbol(int hijos) {
	if (hijos == 0) return 1;
	else {
		int maximo = 2;
		int valor;
		for (int i = 0; i < hijos; ++i) {
			cin >> valor;
			maximo = max(maximo, alturaArbol(valor) + 1);
		}
		return maximo;
	}
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int raiz;
		cin >> raiz;
		cout << alturaArbol(raiz) << '\n';
	}

	return 0;
}