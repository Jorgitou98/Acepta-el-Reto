#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int llave1, llave2;
		char guion;
		cin >> llave1 >> guion >> llave2;
		if (abs(llave1 - llave2) == 1 && min(llave1, llave2) % 2 == 0) cout << "SI\n";
		else cout << "NO\n";
	}

	return 0;
}