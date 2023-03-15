#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<char>> const& mat, vector<vector<bool>>& visited, int i, int j, int n, int m) {
	visited[i][j] = true;
	int num_plantas = 1;
	if (i > 0 && mat[i - 1][j] == '#' && !visited[i - 1][j]) num_plantas += dfs(mat, visited, i - 1, j, n, m);
	if (j > 0 && mat[i][j - 1] == '#' && !visited[i][j - 1]) num_plantas += dfs(mat, visited, i, j - 1, n, m);
	if (i < n-1 && mat[i + 1][j] == '#' && !visited[i + 1][j]) num_plantas += dfs(mat, visited, i + 1, j, n, m);
	if (j < m-1 && mat[i][j+1] == '#' && !visited[i][j + 1]) num_plantas += dfs(mat, visited, i, j + 1, n, m);
	return num_plantas;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	while (cin >> n >> m) {
		char aux;
		vector<vector<char>> mat (n, vector<char>(m));
		for (int i = 0; i < n; ++i) {
			cin.get(aux);
			for (int j = 0; j < m; ++j)
				cin.get(mat[i][j]);
		}

		vector<vector<bool>> visited (n, vector<bool>(m, false));
		int max_plantas = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == '#' && !visited[i][j]) {
					int num_plantas = dfs(mat, visited, i, j, n, m);
					if (num_plantas > max_plantas) max_plantas = num_plantas;
				}
			}
		cout << max_plantas << '\n';
	}
	return 0;
}