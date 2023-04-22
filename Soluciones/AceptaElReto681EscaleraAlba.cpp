#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while (cin >> n) {
		vector<int> piezas(n);
		for (int i = 0; i < n; ++i)
			cin >> piezas[i];
		sort(piezas.begin(), piezas.end(), greater<int>());
		long long int max_piezas = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (piezas[i + 1] >= piezas[i]) piezas[i + 1] = piezas[i] - 1;
			if(piezas[i] > 0) max_piezas += piezas[i];
		}
		if (piezas[n - 1] > 0) max_piezas += piezas[n-1];
		cout << max_piezas << '\n';
	}



	return 0;
}
