#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int c, m, n;
	while (cin >> c >> m >> n) {
		int anterior;
		cin >> anterior;
		int valor;
		vector<int> contrahuellas(n);
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			contrahuellas[i] = valor - anterior;
			anterior = valor;
		}
		int minimo = 1000000000;
		int maximo = 0;
		bool correcto = true;
		for (int i = 0; i < n; ++i) {
			if (i > 0 && abs(contrahuellas[i] - contrahuellas[i - 1]) > c) {
				cout << "Tropiezo\n";
				correcto = false;
				break;
			}
			if (contrahuellas[i] < minimo) minimo = contrahuellas[i];
			if (contrahuellas[i] > maximo) maximo = contrahuellas[i];
		}
		if (correcto) {
			if ((maximo - minimo) > m) cout << "Tropiezo\n";
			else cout << "Ok\n";
		}

	}

	return 0;
}
