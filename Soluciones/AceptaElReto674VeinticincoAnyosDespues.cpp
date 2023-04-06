#include <iostream>
using namespace std;

long long int numCerosFactorial(long long int num) {
	long long int numCeros = 0;
	num /= 5;
	while (num > 0) {
		numCeros += num;
		num /= 5;
	}
	return numCeros;
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int d;
	long long int n;
	cin >> d >> n;
	while (d != 0 || n != 0) {

		if (n == 0) {
			if (d < 5) cout << d << '\n';
			else cout << "NINGUNO\n";
			cin >> d >> n;
			continue;
		}

		long long int ini = 1;
		long long int fin = 5 * n;
		long long int mejor = -1;
		while (ini <= fin) {
			long long int mitad = (ini + fin) / 2;
			long long int ceros = numCerosFactorial(mitad);
			if (ceros == n ) {
				mejor = mitad;
				fin = mitad - 1;
			}
			else if (ceros < n) ini = mitad + 1;
			else fin = mitad - 1;
		}
		for (int i = 0; i < d; ++i) {
			if ((mejor + i) % d == 0) {
				long long int pos_num = mejor + i;
				if (numCerosFactorial(pos_num) == n) {
					cout << pos_num << '\n';
				}
				else cout << "NINGUNO\n";
				break;
			}
		}

		cin >> d >> n;
	}

	return 0;
}