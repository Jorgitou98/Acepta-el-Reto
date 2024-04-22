#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		unordered_map <int, int> apariciones;
		int val;
		for (int i = 0; i < n; ++i) {
			cin >> val;
			if (!apariciones.count(val)) apariciones[val] = 1;
			else apariciones[val]++;
		}
		int maximo = 0;
		int val_max;
		for (auto par : apariciones) {
			if (par.second > maximo) {
				maximo = par.second;
				val_max = par.first;
			}
		}
		cout << val_max << '\n';

		cin >> n;
	}

	return 0;
}
