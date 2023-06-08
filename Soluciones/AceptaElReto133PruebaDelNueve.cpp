#include <iostream>
using namespace std;

int reduccion(string const& dato, int cons_prueba) {
	int reducido = 0;
	for (char c : dato) {
		if (c <= '9') reducido += (c - '0');
		else reducido += (c + 10 - 'A');
		reducido %= cons_prueba;
	}
	return reducido;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	for (int caso = 0; caso < num_casos; ++caso) {
		int base;
		string dividendo, divisor, cociente, resto;
		cin >> base >> dividendo >> divisor >> cociente >> resto;
		int dividendo_red = reduccion(dividendo, base - 1);
		int divisor_red = reduccion(divisor, base - 1);
		int cociente_red = reduccion(cociente, base - 1);
		int resto_red = reduccion(resto, base - 1);

		int op = (divisor_red * cociente_red) + resto_red;
		op %= (base - 1);
		if (op == dividendo_red)
			cout << "POSIBLEMENTE CORRECTO\n";
		else cout << "INCORRECTO\n";

	}


	return 0;
}
