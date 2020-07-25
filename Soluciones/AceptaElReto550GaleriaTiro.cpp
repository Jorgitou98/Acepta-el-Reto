#include <iostream>
#include <cmath>
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
	int n;
	cin >> n;
	if (n == 0)
		return false;
	if (n < 3) cout << 1 << '\n';
	else {
		cout << 2 + coloca(0, n - 1) << '\n';
	}
	
	return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
