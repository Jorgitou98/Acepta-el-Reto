#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int burros, sacos;
		cin >> burros >> sacos;
		unordered_map<int, int> numSacos;
		string aux;
		int valor;
		int numParejas = 0;
		for (int i = 0; i < sacos; ++i) {
			if (numParejas >= burros) {
				getline(cin, aux);
				break;
			}
			cin >> valor;
			if (!numSacos.count(valor)) numSacos[valor] = 1;
			else {
				numSacos[valor]++;
				if (numSacos[valor] % 2 == 0) numParejas++;
			}
		}
		cout << min(burros, numParejas) << '\n';
	}

	return 0;
}