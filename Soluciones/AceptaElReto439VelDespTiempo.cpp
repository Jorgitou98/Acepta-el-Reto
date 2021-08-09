#include <iostream>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int v = -1, d = -1, t = -1;
		int valor;
		char variable, aux;
		cin >> variable >> aux >> valor;
		if (variable == 'D') d = valor;
		else if (variable == 'V') v = valor;
		else t = valor;
		cin >> variable >> aux >> valor;
		if (variable == 'D') d = valor;
		else if (variable == 'V') v = valor;
		else t = valor;
		if (v == -1) cout << "V=" << d / t << '\n';
		else if (d == -1) cout << "D=" << v * t << '\n';
		else cout << "T=" << d / v << '\n';
	}
	return 0;
}