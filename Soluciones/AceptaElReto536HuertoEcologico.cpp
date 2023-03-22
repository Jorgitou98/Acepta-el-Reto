#include <iostream>
#include <string>
using namespace std;


struct tTerreno {
	int tamano, abono, agua, distancia;
	string dueno;
	tTerreno(){}
	tTerreno(int tamano, int abono, int agua, int distancia, string dueno) {
		this->tamano = tamano;
		this->abono = abono;
		this->agua = agua;
		this->distancia = distancia;
		this->dueno = dueno;
	}
};


bool mejorTerreno(tTerreno const& terreno1, tTerreno const& terreno2) {
	return terreno1.tamano > terreno2.tamano || terreno1.tamano == terreno2.tamano && terreno1.agua < terreno2.agua ||
		terreno1.tamano == terreno2.tamano && terreno1.agua == terreno2.agua && terreno1.distancia < terreno2.distancia
		|| terreno1.tamano == terreno2.tamano && terreno1.agua == terreno2.agua && terreno1.distancia == terreno2.distancia && terreno1.abono < terreno2.abono;
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int terrenos;
	while (cin >> terrenos) {
		tTerreno mejor = tTerreno(0,0,0,0,"");
		tTerreno actual;
		char aux;
		for (int i = 0; i < terrenos; ++i) {
			cin >> actual.tamano >> actual.abono >> actual.agua >> actual.distancia;
			cin.get(aux);
			getline(cin, actual.dueno);
			if (mejorTerreno(actual, mejor)) mejor = actual;
		}
		cout << mejor.dueno << '\n';
	}
	return 0;
}