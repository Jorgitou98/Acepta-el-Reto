#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		vector<pair<int, int>> ciclistas(n);
		for (int i = 0; i < n; ++i)
			cin >> ciclistas[i].first >> ciclistas[i].second;
		sort(ciclistas.begin(), ciclistas.end());

		int min_choque = INT_MAX;
		for (int i = 0; i < n-1; ++i) {
			int dif_pos = ciclistas[i + 1].first - ciclistas[i].first;
			if (dif_pos == 0) {
				min_choque = 0;
				break;
			}
			int dif_vel = ciclistas[i].second - ciclistas[i + 1].second;
			if ((dif_pos > 0 && dif_vel > 0) || (dif_pos < 0 && dif_vel < 0))
				min_choque = min(min_choque, dif_pos / dif_vel);
		}
		if (min_choque == INT_MAX)
			cout << "SIN COLISION\n";
		else cout << min_choque << '\n';

		cin >> n;
	}

	return 0;
}