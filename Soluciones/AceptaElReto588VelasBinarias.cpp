#include <iostream>
using namespace std;



int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	long long int n;
	cin >> n;
	while (n != 0) {
		// Pasamos a binario olvidando los ceros del final
		string binario = "";
		bool primerNoCero = false;
		while (n != 1) {
			if (!primerNoCero && n % 2 == 1) primerNoCero = true;
			if (primerNoCero) {
				if(n % 2 == 0) binario = "0" + binario;
				else binario = "1" + binario;
			}
			n /= 2;
		}
		binario = "1" + binario;
		int l = binario.size();
		bool simetrico = true;
		for (int i = 0; i < l/2; ++i) {
			if (binario[i] != binario[l - 1 - i]) {
				simetrico = false;
				break;
			}
		}
		if (simetrico) cout << "SI\n";
		else cout << "NO\n";
		cin >> n;
	}

	return 0;
}