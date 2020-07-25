// Jorge Villarrubia Elvira
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int LADOS_CUADRADO = 4;
int fractales(int longitud, int numeroCuadrados);

int fractales(int longitud, int numeroCuadrados){
	int sumaLongitud;
	if (longitud == 1) sumaLongitud = LADOS_CUADRADO * numeroCuadrados;
	else sumaLongitud = fractales(longitud / 2, LADOS_CUADRADO * numeroCuadrados) + numeroCuadrados * LADOS_CUADRADO * longitud;
	return sumaLongitud;
}


bool resuelveCaso() {
	int longitud;
	cin >> longitud;
	if (!std::cin)
		return false;

	if (longitud == 0) cout << "0 \n";
	else {
		int sumaLongitud = fractales(longitud, 1);
		cout << sumaLongitud << '\n';
	}
	return true;

}

int main() {
/*
#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
*/

	while (resuelveCaso())
		;


	/*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif
*/
	return 0;
}
