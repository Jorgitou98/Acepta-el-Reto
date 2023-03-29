#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> const& grafo, vector<vector<bool>> & marcados, int & casillas, int i, int j, int f, int c, int nivel) {
	if (i < 0 || j < 0 || i >= f || j >= c || marcados[i][j]) return;
	marcados[i][j] = true;
	if (nivel >= grafo[i][j]) {
		casillas++;
		dfs(grafo, marcados, casillas, i + 1, j, f, c, nivel);
		dfs(grafo, marcados, casillas, i - 1, j, f, c, nivel);
		dfs(grafo, marcados, casillas, i, j + 1, f, c, nivel);
		dfs(grafo, marcados, casillas, i, j - 1, f, c, nivel);
	}
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int c, f;
	while (cin >> c >> f) {
		vector<vector<int>> grafo(f, vector<int>(c));
		int alt_max = 0;
		for (int i = 0; i < f; ++i)
			for (int j = 0; j < c; ++j) {
				cin >> grafo[i][j];
				if (grafo[i][j] > alt_max) alt_max = grafo[i][j];
			}			

		int min_alt_necesaria = alt_max, casillas_optimo = f*c;
		int ini = 0, fin = alt_max;
		while (ini <= fin) {
			int mitad = (ini + fin) / 2;
			vector<vector<bool>> marcados(f, vector<bool>(c, false));
			int casillas = 0;
			dfs(grafo, marcados, casillas, f/2, 0, f, c, mitad);
			if (casillas > (f * c) / 2) {
				min_alt_necesaria = mitad;
				casillas_optimo = casillas;
				fin = mitad - 1;
			}
			else ini = mitad + 1;
		}

		cout << min_alt_necesaria << ' ' << casillas_optimo << '\n';

	}
	return 0;
}
