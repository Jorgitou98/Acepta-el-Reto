#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	long long int n;
	cin >> n;
	while (n != 0) {
		long long int entreCeroYUno = 0, mayoresUno = 0;
		double valor;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			if (0 < valor && valor < 1) entreCeroYUno++;
			else if(valor > 1) mayoresUno++;
		}
		long long int opciones = (n * (n-1))/2 - entreCeroYUno * mayoresUno;
		cout << opciones << '\n';
		cin >> n;
	}

	return 0;
}