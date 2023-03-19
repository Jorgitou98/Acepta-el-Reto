#include <iostream>
#include <string>
using namespace std;


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	string nombre_dias[6] = {"MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};
	double valor;
	cin >> valor;
	while (valor != -1) {
		int dia_max = 0, dia_min = 0;
		double max_val = valor;
		double min_val = valor;
		double media = valor;
		for (int i = 1; i < 6; ++i) {
			cin >> valor;
			if (valor > max_val) {
				max_val = valor;
				dia_max = i;
			}
			if (valor < min_val) {
				min_val = valor;
				dia_min = i;
			}
			media += valor;
		}
		media /= 6;
		cout << nombre_dias[dia_max] << ' ' << nombre_dias[dia_min] << ' ';
		if (valor > media) cout << "SI\n";
		else cout << "NO\n";

		cin >> valor;
	}

	return 0;
}
