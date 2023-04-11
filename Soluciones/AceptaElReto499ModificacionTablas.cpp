#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int f, c, n;
	cin >> f >> c >> n;
	while (f != 0 || c != 0 || n != 0) {
		vector<vector<int>> tabla(f, vector<int>(c, 0));
		int ind, a, b, m;
		for (int i = 0; i < n; ++i) {
			cin >> ind >> a >> b >> m;
			tabla[a][ind] += m;
			if (b < f - 1) tabla[b + 1][ind] -= m;
		}

		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c - 1; ++j) {
				if (i > 0) tabla[i][j] += tabla[i - 1][j];
				cout << tabla[i][j] << ' ';
			}
			if (i > 0) tabla[i][c - 1] += tabla[i - 1][c - 1];
			cout << tabla[i][c - 1] << '\n';
		}


		cin >> f >> c >> n;
	}


	return 0;
}