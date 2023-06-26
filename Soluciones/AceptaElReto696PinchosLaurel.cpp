#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int val;
	while (cin >> val) {
		long long int sum = 0;
		int minimo = val;
		int maximo = val;
		do {
			sum += val;
			if (val < minimo) minimo = val;
			if (val > maximo) maximo = val;
			cin >> val;
		} while (val != 0);

		long long int suma_total = ((long long int) (maximo - minimo + 1) * (long long int) (minimo + maximo)) / 2;
		cout << suma_total - sum << '\n';
		
	}

	return 0;
}