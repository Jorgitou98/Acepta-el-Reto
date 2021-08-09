#include <iostream>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	long long int p;
	while (cin >> n >> p) {
		long long int valor;
		long long int maximo = 0;
		int numUvas = 0;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			if (valor + maximo <= p) {
				numUvas++;
				if (valor > maximo) maximo = valor;
			}
			else if (valor < maximo) maximo = valor;
		}
		cout << numUvas << '\n';
	}

	return 0;
}