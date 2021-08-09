#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numero;
	while (cin >> numero) {
		int doble = 2 * numero;
		for (int k = trunc(sqrt(doble)); k >= 1; k--) {
			if ((doble - k * (k - 1)) % (2 * k) == 0) {
				cout << k << '\n';
				break;
			}
		}
	}

	return 0;
}
