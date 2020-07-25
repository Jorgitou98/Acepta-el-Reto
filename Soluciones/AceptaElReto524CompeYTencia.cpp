#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct coste {
	int cteCompe, cteTencia;
};

bool operator <(coste const& c1, coste const& c2) {
	return (c1.cteCompe - c1.cteTencia) < (c2.cteCompe - c2.cteTencia);
}

bool resuelveCaso() {
	int numCompras;
	cin >> numCompras;
		if (numCompras == 0)
			return false;
	int minCompe, minTencia;
	cin >> minCompe >> minTencia;
	vector<coste> costes(numCompras);
	for (int i = 0; i < numCompras; ++i)
		cin >> costes[i].cteCompe;
	for (int i = 0; i < numCompras; ++i)
		cin >> costes[i].cteTencia;
	sort(costes.begin(), costes.end());

	int solucion = 0;
	for (int i = 0; i < minCompe; ++i)
		solucion += costes[i].cteCompe;
	for (int j = numCompras-1; j >= numCompras - minTencia; --j)
		solucion += costes[j].cteTencia;
	for (int i = minCompe; i < numCompras - minTencia; ++i)
		solucion += min(costes[i].cteCompe, costes[i].cteTencia);
	cout << solucion << '\n';
		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}