#include <iostream>
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
		int valor;
		cin >> valor;
		int maxGlobal = valor;
		int maxNinos = valor;
		int ninos = 1;
		for (int i = 1; i < n; ++i) {
			cin >> valor;
			if (valor > maxGlobal) maxGlobal = valor;
			if (valor <= maxNinos) {
				ninos = i + 1;
				maxNinos = maxGlobal;
			}
		}
		cout << ninos << '\n';


		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
