#include <iostream>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int n;
		cin >> n;
		int ini = 0, fin = 0, suma = 0, iniMejor = 0, finMejor = 0, longMejor = 0, sumaMejor = 0;
		int valor;
		for (int i = 1; i <= n; ++i) {
			cin >> valor;
			if (suma + valor <= 0) {
				suma = 0;
				continue;
			}
			else if (suma == 0) {
				ini = i;
				fin = i;
				suma += valor;
			}
			else {
				fin++;
				suma += valor;
			}
			if (suma > sumaMejor || suma == sumaMejor && (fin-ini) < longMejor) {
				sumaMejor = suma;
				iniMejor = ini;
				finMejor = fin;
				longMejor = fin - ini;
			}
		}
		cout << iniMejor << ' ' << finMejor << '\n';
	}

	return 0;
}