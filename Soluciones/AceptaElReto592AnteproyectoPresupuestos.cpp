#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool correcta(vector<int> const& gastos, int presupuesto, int umbral) {
	int acum = 0;
	for (int gasto : gastos) {
		if (acum + min(gasto, umbral) > presupuesto) return false;
		acum += min(gasto, umbral);
	}
	return true;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int presupuesto, n;
	while (cin >> presupuesto >> n) {
		int maximo = 0;
		bool sobra = true;
		int acum = 0;
		vector<int> gastos(n);
		for (int i = 0; i < n; ++i){
			cin >> gastos[i];
			if (gastos[i] > maximo)
				maximo = gastos[i];
			if (sobra) {
				if (acum + gastos[i] > presupuesto) sobra = false;
				else acum += gastos[i];
			}
		}
		if (sobra) {
			cout << maximo << '\n';
			continue;
		}
		int mejor = 0;
		int izq = 0, der = maximo;
		while (izq <= der) {
			int mitad = (izq + der) / 2;
			if (correcta(gastos, presupuesto, mitad)) {
				izq = mitad + 1;
				mejor = mitad;
			}
			else
				der = mitad - 1;
		}
		cout << mejor << '\n';

	}
}