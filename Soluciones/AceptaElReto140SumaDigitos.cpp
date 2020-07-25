// Jorge Villarrubia Elvira
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;


int sumarCifras(int numero) {
	int suma;

	if (numero / 10 == 0) {
		suma = numero % 10;
		cout << numero;
	}
	else {
		suma = sumarCifras(numero / 10) + (numero % 10);
		cout << " + ";
		cout << (numero % 10);
	}
	return suma;
}


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n < 0)
		return false;

	int suma = sumarCifras(n);
	cout << " = " << suma << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	/*// Comentar para acepta el reto
	#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif
	*/

	while (resuelveCaso())
		;


	/*// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	#endif
	*/
	return 0;
}
