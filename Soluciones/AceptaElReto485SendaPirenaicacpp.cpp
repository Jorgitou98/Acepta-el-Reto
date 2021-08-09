#include <iostream>
#include <vector>
using namespace std;



int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		vector<int> distancias(n);
		int suma = 0;
		for (int i = 0; i < n; ++i) {
			cin >> distancias[i];
			suma += distancias[i];
		}
		for (int i = 0; i < n; ++i) {
			cout << suma;
			if (i < n-1) cout << " ";
			suma -= distancias[i];
		}
		cout << "\n";

		cin >> n;
	}


	return 0;
}