#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	while (cin >> n) {
		int numAnillos = 1 + (n - 1) / 2;
		vector<long long int> sumaGrosor(numAnillos, 0);
		long long int grosor;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int anillo = min(min(min(i, n + 1 - i), j), n + 1 - j);
				cin >> grosor;
				sumaGrosor[anillo-1] += grosor;
			}
		}
		for (int i = sumaGrosor.size() - 1; i >= 0; i--) {
			cout << sumaGrosor[i];
			if (i > 0) cout << " ";
		}
		cout << "\n";
	}

	return 0;
}