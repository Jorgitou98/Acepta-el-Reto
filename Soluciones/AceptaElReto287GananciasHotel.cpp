#include <iostream>
#include <vector>
using namespace std;

#define MOD 78787

int main() {
	int precio, n;
	while (cin >> precio >> n) {
		int caja = 0;
		vector<int> habitaciones(n);
		for (int i = 0; i < n; ++i) cin >> habitaciones[i];

		int pos_algido = (n - 1) / 2;
		int precio_actual = precio;
		for (int i = 0; i <= pos_algido; ++i) {
			caja += (precio_actual * habitaciones[i]) % MOD;
			caja = caja % MOD;
			precio_actual = (3 * precio_actual) % MOD;
		}
		precio_actual = precio;
		for (int i = n - 1; i > pos_algido; --i) {
			caja += (precio_actual * habitaciones[i]) % MOD;
			caja = caja % MOD;
			precio_actual = (3 * precio_actual) % MOD;
		}

		cout << caja << '\n';

	}


}