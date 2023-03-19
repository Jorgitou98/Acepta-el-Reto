#include <iostream>
#include <vector>
using namespace std;

#define MOD 46337

vector<vector<int>> posibilidades() {
	vector<vector<int>> pos_mat(3001, vector<int>(3001, 0));
	pos_mat[1][1] = 1;
	for (int i = 2; i < 3001; ++i)
		for (int j = 1; j <= i; ++j) {
			pos_mat[i][j] = j * (pos_mat[i - 1][j] + pos_mat[i - 1][j - 1]);
			pos_mat[i][j] %= MOD;
		}
	return pos_mat;
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	vector<vector<int>> pos_mat = posibilidades();
	while (cin >> n) {
		int suma = 0;
		for (int j = 1; j <= n; ++j) {
			suma += pos_mat[n][j];
			suma %= MOD;
		}
		cout << suma << '\n';
	}
	return 0;
}