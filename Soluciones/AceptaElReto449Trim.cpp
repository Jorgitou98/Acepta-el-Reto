#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



pair<int, int> indicesElimina(string const& palabra, int i, int j, char caracter) {
	int k = i, m = j;
	while (k <= m && (palabra[k] == caracter || palabra[m] == caracter)) {
		if (palabra[k] == caracter) k++;
		if (palabra[m] == caracter) m--;
	}
	return { k,m };
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	string palabra;
	while (cin >> palabra) {
		int n = palabra.size();
		vector<vector<int>> M(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) M[i][i] = 1;
		for (int d = 1; d < n; d++) {
			for (int i = 0; i < n - d; i++) {
				int j = i + d;
				if (palabra[i] == palabra[j]) {
					pair<int, int> par = indicesElimina(palabra, i, j, palabra[i]);
					if (par.second < par.first) M[i][j] = 1;
					else M[i][j] = M[par.first][par.second] + 1;
				}
				else {
					pair<int, int> parIzq = indicesElimina(palabra, i, j, palabra[i]);
					pair<int, int> parDer = indicesElimina(palabra, i, j, palabra[j]);
					M[i][j] = min(M[parIzq.first][parIzq.second], M[parDer.first][parDer.second]) + 1;
				}
			}
		}
		cout << M[0][n - 1] << '\n';
	}

	return 0;
}