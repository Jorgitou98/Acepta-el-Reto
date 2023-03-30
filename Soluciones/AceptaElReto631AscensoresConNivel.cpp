#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct intervalo {
	int ini, fin, nivel;
};

bool compare(intervalo const& inter1, intervalo const& inter2) {
	return inter1.ini < inter2.ini;
}

bool posible(vector<intervalo> const& intervalos, int nivelMax, int maxPiso) {
	int fin = 0;
	int i = 0;
	while (i < intervalos.size() && fin != maxPiso) {
		if (intervalos[i].ini > fin) break;
		if (intervalos[i].nivel <= nivelMax && intervalos[i].fin > fin)
			fin = intervalos[i].fin;
		i++;
	}
	return (fin == maxPiso);
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	while (cin >> n) {
		vector<intervalo> intervalos(n);
		int maxPiso = 0;
		int maxNivel = 0;
		for (int i = 0; i < n; ++i) {
			cin >> intervalos[i].ini >> intervalos[i].fin >> intervalos[i].nivel;
			if (intervalos[i].fin > maxPiso) maxPiso = intervalos[i].fin;
			if (intervalos[i].nivel > maxNivel) maxNivel = intervalos[i].nivel;
		}
		sort(intervalos.begin(), intervalos.end(), compare);

		int minNivel = 0;
		int opt = maxNivel;
		while (minNivel <= maxNivel) {
			int mitad = (minNivel + maxNivel) / 2;
			if (posible(intervalos, mitad, maxPiso)) {
				opt = mitad;
				maxNivel = mitad - 1;
			}
			else minNivel = mitad + 1;
		}

		cout << opt << '\n';

	}

	return 0;
}