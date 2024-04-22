#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numerador, denominador;
	while (cin >> numerador >> denominador) {
		int pos = 0;
		int marca_periodo = -1;
		vector<int> resultado;
		vector<int> numeradores_calculados(denominador * 10, -1);
		numerador *= 10;
		while (numerador != 0) {
			if (numeradores_calculados[numerador] != -1) {
				marca_periodo = numeradores_calculados[numerador];
				break;
			}
			numeradores_calculados[numerador] = pos;
			while (numerador < denominador) {
				numerador *= 10;
				resultado.push_back(0);
				pos++;
				if (numeradores_calculados[numerador] != -1) {
					marca_periodo = numeradores_calculados[numerador];
					break;
				}
				numeradores_calculados[numerador] = pos;
			}
			if (marca_periodo != -1) break;
			resultado.push_back(numerador / denominador);
			numerador = (numerador % denominador) * 10;
			pos++;
		}
		cout << "0.";
		for (int i = 0; i < resultado.size(); ++i) {
			if (marca_periodo == i) cout << '|';
			cout << resultado[i];
		}
		if(marca_periodo != -1) cout << '|';
		cout << '\n';
	}

	return 0;
}