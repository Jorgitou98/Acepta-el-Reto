#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<int>> const& grafo, vector<bool>& visitados, int ini) {
	visitados[ini] = true;
	for (int vecino : grafo[ini]) {
		if (!visitados[vecino]) dfs(grafo, visitados, vecino);
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int p, c;
	while (cin >> p >> c) {
		vector<vector<int>> grafo(p, vector<int>());
		int p1, p2;
		for (int i = 0; i < c; ++i) {
			cin >> p1 >> p2;
			grafo[p1 - 1].push_back(p2 - 1);
			grafo[p2 - 1].push_back(p1 - 1);
		}
		vector<bool> visitados(p, false);
		dfs(grafo, visitados, 0);
		bool conexo = true;
		for (bool visitado : visitados) {
			if (!visitado) {
				conexo = false;
				break;
			}
		}
		if (conexo) cout << "BICI\n";
		else cout << "A PIE\n";
	}

	return 0;
}