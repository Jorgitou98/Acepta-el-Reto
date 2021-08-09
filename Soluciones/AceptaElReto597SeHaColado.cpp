#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int n;
		cin >> n;
		vector<int> numeros(n);
		for (int i = 0; i < n; ++i) cin >> numeros[i];
		int colados = 0;
		int minimo = 1000000;
		for (int i = n - 1; i >= 0; i--) {
			if (numeros[i] > minimo) colados++;
			minimo = min(minimo, numeros[i]);
		}
		cout << colados << '\n';
	}


	return 0;
}