#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		vector<vector<int>> M(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> M[i][j];

		int i = n / 2, j = n / 2;
		pair<int, int> dirs[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
		int dir_act = 0;
		int num_mov = 1;
		int num_restantes = 2;
		long long int suma = 0;
		while (i >= 0 && i < n && j >= 0 && j < n) {
			suma += (long long int) M[i][j];
			num_restantes--;
			if (num_restantes == 0) {
				num_mov++;
				num_restantes = num_mov;
				dir_act = (dir_act + 1) % 4;
			}
			i += dirs[dir_act].first;
			j += dirs[dir_act].second;
		}

		cout << suma << '\n';



		cin >> n;
	}
	return 0;
}