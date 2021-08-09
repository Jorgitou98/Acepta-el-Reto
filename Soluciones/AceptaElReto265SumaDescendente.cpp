#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	string numero;
	cin >> numero;
	while (numero != "0") {
		int n = numero.size();
		long long int suma = 0;
		for (int i = 0; i < n; ++i) {
			suma += (numero[i]-'0') * (i + 1) * pow(10,n-1-i);
		}
		cout << suma << '\n';
		cin >> numero;
	}

	return 0;
}
