#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
	vector <pair <int, int>> v;
	int v1, v2;
	for (int i = 0; i < n; ++i) {
		cin >> v1 >> v2;
		v.push_back({ v1, v2 });
	}
	sort(v.begin(), v.end());

	int iInt = v[0].first, fInt = v[0].second;
	int pasarelas = 1;

	for (int i = 1; i < v.size(); ++i) {
		if (v[i].first < fInt) {
			iInt = v[i].first;
			if (v[i].second < fInt) fInt = v[i].second;
		}
		else {
			pasarelas++;
			iInt = v[i].first;
			fInt = v[i].second;
		}
	}
	cout << pasarelas << '\n';

		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
