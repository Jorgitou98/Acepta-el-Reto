#include <iostream>
#include <cmath>
using namespace std;

void resuelveCaso() {
	int numDecimos;
	cin >> numDecimos;
	int pares = 0;
	int valor;
	for (int i = 0; i < numDecimos; ++i) {
		cin >> valor;
		if (valor % 2 == 0) pares = pares++;
	}
	cout << pares << '\n';
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}