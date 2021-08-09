#include <iostream>
#include <vector>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int tx, ty, mx, my;
	cin >> tx >> ty>> mx>> my;
	while (tx != 0 || ty != 0 || mx != 0 || my != 0 ) {
		//vector<vector<char>> tablero(ty, vector<char>(tx));
		char valor;
		vector<vector<int>> sumaFila(ty + 1, vector<int>(tx + 1, 0));
		vector<vector<int>> sumaColumna(ty + 1, vector<int>(tx + 1, 0));
		int moscas = 0;
		for (int i = 1; i <= ty; ++i) {
			for (int j = 1; j <= tx; ++j) {
				cin >> valor;
				if (valor == 'X') {
					sumaFila[i][j] = sumaFila[i][j - 1] + 1;
					sumaColumna[i][j] = sumaColumna[i-1][j] + 1;
				}
				else {
					sumaFila[i][j] = sumaFila[i][j - 1];
					sumaColumna[i][j] = sumaColumna[i-1][j];
				}
				if (i <= my && j <= mx && valor == 'X') moscas++;
			}
		}

		vector<long long int> maneras(8, 0);
		int moscasColCero = moscas;
		for (int i = 1; i + my - 1 <= ty; ++i) {
			if (i > 1) {
				moscasColCero -= sumaFila[i-1][mx];
				moscasColCero += sumaFila[i + my - 1][mx];
				moscas = moscasColCero;
			}
			if (moscas <= 7) maneras[moscas]++;
			for (int j = 2; j + mx - 1 <= tx; ++j) {
				moscas -= (sumaColumna[i + my - 1][j - 1] - sumaColumna[i-1][j - 1]);
				moscas += (sumaColumna[i + my - 1][j + mx - 1] - sumaColumna[i - 1][j + mx - 1]);
				if (moscas <= 7) maneras[moscas]++;
			}
		}
		for (int i = 0; i < 8; ++i) {
			cout << maneras[i];
			if (i < 7) cout << " ";
		}
		cout << "\n";
		cin >> tx >> ty >> mx >> my;
	}

	return 0;
}