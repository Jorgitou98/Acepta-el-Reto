#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int max_punt(int ind, int n, vector<pair<int, int>> const& canciones, int d, int cinta1, int cinta2, vector<vector<vector<int>>>& sols) {
	if (ind == n) return 0;
	if (sols[cinta1][cinta2][ind] != -1) return sols[cinta1][cinta2][ind];
	// No lo meto
	int mejor = max_punt(ind + 1, n, canciones, d, cinta1, cinta2, sols);
	// La meto en cara A
	if (cinta1 + canciones[ind].first <= d) {
		int caraA = max_punt(ind + 1, n, canciones, d, cinta1 + canciones[ind].first, cinta2, sols);
		mejor = max(mejor, caraA + canciones[ind].second);
	}
	// La meto en cara B
	if (cinta2 + canciones[ind].first <= d) {
		int caraB = max_punt(ind + 1, n, canciones, d, cinta1, cinta2 + canciones[ind].first, sols);
		mejor = max(mejor, caraB + canciones[ind].second);
	}
	sols[cinta1][cinta2][ind] = mejor;
	sols[cinta2][cinta1][ind] = mejor;
	return mejor;
}


int main() {
	int n;
	cin >> n;
	while (n != 0) {
		int d;
		cin >> d;
		vector<pair<int, int>> canciones(n);
		for (int i = 0; i < n; ++i)
			cin >> canciones[i].first >> canciones[i].second;
		vector<vector<vector<int>>> sols(d + 1, vector<vector<int>>(d + 1, vector<int>(n, -1)));

		int mejor = max_punt(0, n, canciones, d, 0, 0, sols);
		cout << mejor << '\n';
		cin >> n;
	}
}