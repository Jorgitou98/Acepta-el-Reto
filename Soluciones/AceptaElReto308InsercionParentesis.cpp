#include <iostream>
#include <vector>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	string expresion;
	while (cin >> expresion) {
		int n = expresion.size();
		vector<vector<vector<bool>>> tabla(n, vector<vector<bool>>(n, vector<bool>(3, false)));
		for (int i = 0; i < n; ++i) {
			tabla[i][i][expresion[i] - 'a'] = true;
		}
		for (int d = 1; d < n; d++) {
			for (int i = 0; i < n - d; i++) {
				int j = i + d;
					for (int k = i; k < j; k++) {
						if (tabla[i][k][0] && tabla[k+1][j][2] || tabla[i][k][1] && tabla[k+1][j][2] || tabla[i][k][2] && tabla[k+1][j][0]) tabla[i][j][0] = true;
						if (tabla[i][k][0] && tabla[k+1][j][0] || tabla[i][k][0] && tabla[k+1][j][1] || tabla[i][k][1] && tabla[k+1][j][1]) tabla[i][j][1] = true;
						if (tabla[i][k][1] && tabla[k+1][j][0] || tabla[i][k][2] && tabla[k+1][j][1] || tabla[i][k][2] && tabla[k+1][j][2]) tabla[i][j][2] = true;
					}
			}
		}
		if (tabla[0][n - 1][0]) cout << "SI\n";
		else cout << "NO\n";
	}

	return 0;
}