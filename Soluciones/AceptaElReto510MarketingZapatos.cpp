#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		vector<bool> positivo(n, false);
		vector<int> tallasHombre, tallasMujer;
		int valor;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			if (valor > 0) {
				positivo[i] = true;
				tallasHombre.push_back(valor);
			}
			else tallasMujer.push_back(valor);
		}
		sort(tallasHombre.begin(), tallasHombre.end());
		sort(tallasMujer.begin(), tallasMujer.end(), greater<int>());
		int h = 0, m = 0;
		for (int i = 0; i < n; ++i) {
			if (positivo[i]) {
				cout << tallasHombre[h];
				h++;
			}
			else {
				cout << tallasMujer[m];
				m++;
			}
			if (i < n - 1) cout << " ";
		}
		cout << "\n";
		cin >> n;
	}

	return 0;
}