#include <iostream>
#include <vector>
using namespace std;

long long int mcd(long long int a, long long int b) {
	if (a == 0) return b;
	else return mcd(b % a, a);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	long long int valor;
	cin >> valor;
	while (valor != 0) {
		long long int suma = 1;
		long long int maximoDiv = valor;
		cin >> valor;
		while (valor != 0) {
			long long int nuevoMaximoDiv = mcd(maximoDiv, valor);
			suma *= maximoDiv / nuevoMaximoDiv;
			suma += valor / nuevoMaximoDiv;
			maximoDiv = nuevoMaximoDiv;
			cin >> valor;
		}
		cout << suma << '\n';
		cin >> valor;
	}

	return 0;
}