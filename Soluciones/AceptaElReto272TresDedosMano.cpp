// Jorge Villarrubia Elvira
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int BASE_CONVERSION = 6;

void valorDivision(int numBaseDiez);

void valorDivision(int numBaseDiez) {
	if (numBaseDiez / BASE_CONVERSION == 0) {
		cout << numBaseDiez;
	}
	else if (numBaseDiez / BASE_CONVERSION <= 5) {
		cout << numBaseDiez / BASE_CONVERSION << numBaseDiez % BASE_CONVERSION;
	}
	else {
		valorDivision(numBaseDiez / BASE_CONVERSION);
		cout << numBaseDiez % BASE_CONVERSION;
	}

}


void resuelveCaso() {
	int numBaseDiez;
	cin >> numBaseDiez;
	valorDivision(numBaseDiez);
	cout << '\n';


}

int main() {
/*
#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
*/

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	/*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif
*/
	return 0;
}
