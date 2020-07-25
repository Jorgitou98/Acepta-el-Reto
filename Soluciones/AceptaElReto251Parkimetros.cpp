#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void resuelveCaso() {
	int numTipos, numMaximo;
	cin >> numTipos >> numMaximo;
	vector<int> monedas(numTipos);
	int maximo = INT_MIN;
	for (int i = 0; i < numTipos; ++i) {
		cin >> monedas[i];
		maximo = max(maximo, monedas[i]);
	}
	int maxConseguible = maximo * numMaximo;
	vector<pair<bool, int>> cantidadesPosibles(maxConseguible + 1, { false,0 });
	cantidadesPosibles[0] = { true, 0 };
	for (int i = 1; i <= numTipos; ++i) {
		cantidadesPosibles[monedas[i - 1]] = { true,1 };
		for (int j = maxConseguible; j > 0; --j)
			for (int k = 1; k <= numMaximo; ++k) {
				int posMirar = j - k * monedas[i - 1];
				if (posMirar >= 0 && cantidadesPosibles[posMirar].first && cantidadesPosibles[posMirar].second + k <= numMaximo)
					if (cantidadesPosibles[j].first) cantidadesPosibles[j].second = min(cantidadesPosibles[j].second, cantidadesPosibles[posMirar].second + k);
					else cantidadesPosibles[j] = { true, cantidadesPosibles[posMirar].second + k };
			}

	}
	cantidadesPosibles[0] = { false, 0 };
	int sol = 0;
	for (auto valor : cantidadesPosibles)
		if (valor.first) sol++;
	cout << sol << '\n';
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