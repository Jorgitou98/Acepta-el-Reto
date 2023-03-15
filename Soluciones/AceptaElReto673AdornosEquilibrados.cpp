#include <iostream>
#include <vector>
using namespace std;


bool busquedaBinaria(int ini, int fin, int val, vector<int> const& acum) {
	if (ini > fin) return false;
	int mitad = (ini + fin) / 2;
	if (acum[mitad] < val) return busquedaBinaria(mitad + 1, fin, val, acum);
	else if(acum[mitad] > val) return busquedaBinaria(ini, mitad-1, val, acum);
	return true;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n, c;
	while (cin >> n >> c) {
		vector<int> acum(n+1);
		acum[0] = 0;
		int val;
		for (int i = 1; i < n+1; ++i) {
			cin >> val;
			acum[i] = acum[i - 1] + val;
		}
		int maxPesoEq = 0;
		int posMejor = -1;
		for (int i = 1; i <= n+1-c; ++i) {
			int gap = acum[i + c - 1] - acum[i-1];
			if (gap % 2 == 0 && gap > maxPesoEq && busquedaBinaria(i, i + c - 1, acum[i-1] + gap / 2, acum)) {
				maxPesoEq = gap;
				posMejor = i;
			}
		}
		if (posMejor == -1) cout << "SIN ADORNOS\n";
		else cout << posMejor << '\n';
	}

	return 0;
}