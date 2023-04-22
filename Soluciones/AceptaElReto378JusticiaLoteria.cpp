#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	while (n != 0) {
		vector<pair<int, int>> datos(n);
		for (int i = 0; i < n; ++i)
			cin >> datos[i].first >> datos[i].second;

		sort(datos.begin(), datos.end());
		int i = 1;
		bool justo = true;
		while (i < n && justo) {
			if (datos[i].first > datos[i - 1].first && datos[i].second <= datos[i - 1].second) {
				cout << "NO\n";
				justo = false;
			}
			i++;
		}
		if (justo) cout << "SI\n";
		cin >> n;
	}
	return 0;
}