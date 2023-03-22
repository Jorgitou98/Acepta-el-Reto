#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool siemprePremio(vector<int> const& alturas, int ini, int fin, int& minimo, int& maximo) {
	int indMax = ini;
	maximo = alturas[ini];
	minimo = alturas[ini];

	for (int i = ini + 1; i < fin; i++) {
		if (alturas[i] > maximo) {
			maximo = alturas[i];
			indMax = i;
		}
		minimo = min(minimo, alturas[i]);
	}

	if (fin - ini < 3)	return true;
	int maxDcha, maxIzq, minDcha, minIzq;
	if (ini == indMax) return siemprePremio(alturas, indMax + 1, fin, minDcha, minIzq);
	if (indMax + 1 == fin) return siemprePremio(alturas, ini, indMax, minIzq, maxIzq);
	return siemprePremio(alturas, ini, indMax, minIzq, maxIzq) && siemprePremio(alturas, indMax + 1, fin, minDcha, maxDcha) && minIzq >= maxDcha;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while (cin >> n) {
		vector<int> alturas(n);
		for (int i = 0; i < n; ++i) cin >> alturas[i];
		int minimo, maximo;
		if (siemprePremio(alturas, 0, n, minimo, maximo)) cout << "SIEMPRE PREMIO\n";
		else cout << "ELEGIR OTRA\n";
	}
	return 0;
}