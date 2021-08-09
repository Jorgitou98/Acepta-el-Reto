#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int maneraSumar(vector<int> const& pesos, int pos, long long int suma, int uvasCogidas, int peso, int uvas) {
	if (uvasCogidas == 12 && suma <= peso) return 1;
	else if (pos == uvas || suma > peso) return 0;
	return maneraSumar(pesos, pos+1, suma, uvasCogidas, peso, uvas) + maneraSumar(pesos, pos+1, suma + pesos[pos], uvasCogidas+1, peso, uvas);
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int peso, uvas;
	cin >> peso >> uvas;
	while (peso != 0 || uvas != 0) {
		vector<int> pesos(uvas);
		sort(pesos.begin(), pesos.end());
		for (int i = 0; i < uvas; ++i) cin >> pesos[i];
		cout << maneraSumar(pesos, 0, 0, 0, peso, uvas) << '\n';
		cin >> peso >> uvas;
	}

	return 0;
}