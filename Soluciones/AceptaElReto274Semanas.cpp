#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	int dias_anyo, dias_sem, dia_ini;
	for (int i = 0; i < num_casos; ++i) {
		int semanas_total = 0;
		cin >> dias_anyo >> dias_sem >> dia_ini;
		int desfase_ini = dias_sem - dia_ini + 1;
		dias_anyo -= desfase_ini;
		if (dia_ini == 1) semanas_total++;
		semanas_total += dias_anyo / dias_sem;
		cout << semanas_total << '\n';
	}



	return 0;
}