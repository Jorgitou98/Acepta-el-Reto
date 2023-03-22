#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int peso, n;
		cin >> peso >> n; 
		vector<bool> enPie(n);
		int valor;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			enPie[i] = (peso <= valor);
		}
		int ini = 0, fin = 0, numEnPie = 0, maxLong = 0;
		while (fin < n) {
			if (enPie[fin]) numEnPie++;
			if (numEnPie > 5) {
				while (!enPie[ini]) ini++;
				ini++;
				numEnPie--;
			}
			maxLong = max(maxLong, (fin-ini + 1));
			fin++;
		}
		cout << maxLong << '\n';
		
	}

	return 0;
}