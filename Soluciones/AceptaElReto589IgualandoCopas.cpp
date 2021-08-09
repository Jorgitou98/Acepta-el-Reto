#include <iostream>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		long long int maximo = 0, suma = 0, valor;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			if (valor > maximo) maximo = valor;
			suma += valor;
		}
		cout << (maximo* n) - suma << '\n';
		cin >> n;
	}

	return 0;
}