#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int max_peso, n;
	cin >> max_peso >> n;
	while (max_peso != 0 || n != 0) {
		vector<int> pesos(n);
		for (int i = 0; i < n; ++i) {
			cin >> pesos[i];
		}
		sort(pesos.begin(), pesos.end());
		int viajes = 0;
		int i = 0, j = n - 1;
		while (i <= j) {
			if (i == j) {
				viajes++;
				break;
			}
			if (pesos[i] + pesos[j] <= max_peso) {
				i++;
				j--;
			}
			else j--;
			viajes++;
			
		}
		cout << viajes << '\n';

		cin >> max_peso >> n;
	}

	return 0;
}