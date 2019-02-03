#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;



bool resuelveCaso() {
	int L, valor;

	cin >> L;

	if (L == 0)
		return false;

	cin >> valor;
	int mejorHastaAhora = valor, mejorDeAhora = valor;
	int maxInicio = valor, minInicio = valor, suma = valor;
	if (maxInicio < suma) maxInicio = suma;
	if (minInicio > suma) minInicio = suma;
	if (mejorDeAhora < 0) mejorDeAhora = 0;
	if (mejorDeAhora > mejorHastaAhora) mejorHastaAhora = mejorDeAhora;

	for (int i = 1; i < L; ++i) {
		cin >> valor;
		mejorDeAhora += valor;
		suma += valor;
		if (maxInicio < suma) maxInicio = suma;
		if (minInicio > suma) minInicio = suma;
		if (mejorDeAhora < 0) mejorDeAhora = 0;
		if (mejorDeAhora > mejorHastaAhora) mejorHastaAhora = mejorDeAhora;
	}
	int maxFinal = (suma - minInicio);

	int mejor = max(mejorHastaAhora, maxFinal + maxInicio);
	cout << mejor << '\n';
	

	return true;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}
