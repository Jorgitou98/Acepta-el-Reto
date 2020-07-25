#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;



int coloca(int ini, int fin) {
	int mitad = (ini + fin) / 2;
	if (fin - ini < 4) return 0;
	else if ((fin + ini) % 2 == 0) {

		return 2 * coloca(ini, mitad) + 1;
	}
	else {
		return coloca(ini, mitad) + coloca(mitad, fin) + 1;
	}
}


bool resuelveCaso() {
	int n, pesoMax;
	cin >> n >> pesoMax;
	if (n == 0)
		return false;
	vector<int> pesos(n);
	for (int i = 0; i < n; ++i)
		cin >> pesos[i];

	sort(pesos.begin(), pesos.end());

	int i = 0, j = pesos.size() - 1;

	long long int cuantos = 0;
	long long int suma;
	while (i < j) {
		suma = pesos[i] + pesos[j];
		if (suma <= pesoMax) {
			cuantos += j - i;
			i++;
		}
		else j--;
	}

	cout << cuantos << '\n';
	return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
