#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	// Criba de Eratostenes (hallar Pi)
	int tamMax = 100000;
	vector<int> pi(tamMax+1, 0);
	vector<bool> marcado(tamMax+1, true);
	marcado[0] = false;
	marcado[1] = false;
	for (int i = 2; i <= sqrt(tamMax); ++i) {
		for (int j = i; j <= tamMax / i; ++j) {
			marcado[i * j] = false;
		}
	}
	int numPrimos = 0;
	for (int i = 0; i <= tamMax; ++i) {
		if (marcado[i]) numPrimos++;
		pi[i] = numPrimos;
	}
	int n, m;
	cin >> n >> m;
	while (n != 0 || m != 0) {
		double error = abs(pi[n] * log(n) - n);
		double tolerancia = n * log(n) * pow(10, -m);
		if (error == tolerancia) cout << "Igual\n";
		else if (error > tolerancia) cout << "Mayor\n";
		else cout << "Menor\n";
		cin >> n >> m;
	}

	return 0;
}