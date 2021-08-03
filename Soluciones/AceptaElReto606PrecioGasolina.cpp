#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n > 0) {
		vector<int> precios(n), crecientes(n);
		for (int i = 0; i < n; ++i) cin >> precios[i];
		crecientes[0] = 1;
		for (int i = 1; i < n; ++i) {
			int maxCrec = 1;
			for (int j = 0; j < i; ++j) {
				if (precios[j] < precios[i]) maxCrec = max(maxCrec, crecientes[j] + 1);
			}
			crecientes[i] = maxCrec;
		}
		int mejorCreciente = 1;
		for (int maxCrec : crecientes) mejorCreciente = max(mejorCreciente, maxCrec);
		cout << mejorCreciente << '\n';

		cin >> n;
	}


	return 0;
}