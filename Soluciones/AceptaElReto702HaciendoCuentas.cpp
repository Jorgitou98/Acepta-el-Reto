#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int get_mes(string const& mes_string) {
	return (mes_string[0] - '0') * 10 + mes_string[1] - '0';
}

int main() {
	int saldo_inicial, movimientos;
	while (cin >> saldo_inicial >> movimientos) {
		string fecha;
		int cantidad;
		string concepto;
		unordered_map<int, int> balance;
		for (int i = 0; i < movimientos; ++i) {
			cin >> fecha >> cantidad;
			getline(cin, concepto);
			int mes = get_mes(fecha.substr(3, 2));
			if (!balance.count(mes)) balance[mes] = cantidad;
			else balance[mes] += cantidad;
		}
		for (int i = 1; i < 12; ++i) {
			saldo_inicial += balance[i];
			cout << saldo_inicial << ' ';
		}
		saldo_inicial += balance[12];
		cout << saldo_inicial << '\n';
	}

	return 0;
}