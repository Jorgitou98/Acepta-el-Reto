// Jorge Villarrubia Elvira
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <math.h>  

using namespace std;


int sumaClave(string &cadena, int clave) {

	int cont = 0;
	int suma = 0;
	for (int i = cadena.size() -1; i >= 0; --i) {
		suma += (int(cadena[i]) - '0');
		while (suma > clave) {
			suma -= (int(cadena[cadena.size() - 1]) - '0');
			cadena.pop_back();
		}
		if (suma == clave) cont++;
	}
	return cont;
}

void resuelveCaso() {
	int clave;
	string cadena;

	cin >> clave >> cadena;

	cout << sumaClave(cadena, clave) << '\n';
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
