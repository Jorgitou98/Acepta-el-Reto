#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

int iteracionesKaprekar(string numero) {
	if (numero == "6174") return 0;
	else {
		sort(numero.begin(), numero.end());
		int menorAMayor = stoi(numero);
		sort(numero.begin(), numero.end(), greater<int>());
		int mayorAMenor = stoi(numero);
		string resta = to_string(mayorAMenor - menorAMayor);
		while (resta.size() < 4) {
			resta = "0" + resta;
		}
		return 1 + iteracionesKaprekar(resta);
	}
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		string numero;
		cin >> numero;
		while (numero.size() < 4) {
			numero = "0" + numero;
		}
		unordered_set<char> digitos;
		for (char digito : numero) digitos.insert(digito);
		if (digitos.size() == 1) cout << "8\n";
		else cout << iteracionesKaprekar(numero) << '\n';

	}
	return 0;
}