#include <iostream>
#include <list>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
	unordered_map <int, list<int>> mapa;
	vector<int> diams(n + 1);
	int diam;
	for (int i = 0; i < n; ++i) {
		cin >> diams[i];
		mapa[diams[i]].push_back(i);
	}

	diams[n] = INT_MAX;
	long long int distancia = 0;

	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j < diams[i] && j <= 20; ++j) {
			if (!mapa.count(j)) continue;
			auto it = mapa[j].begin();
			while (it != mapa[j].end() && (*it) < i) {
				distancia += i - (*it);
				it = mapa[j].erase(it);
			}
		}
	}
	cout << distancia << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
