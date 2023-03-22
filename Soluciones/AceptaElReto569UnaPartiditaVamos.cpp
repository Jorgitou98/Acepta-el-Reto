#include <iostream>
using namespace std;

int cambioAMinutos(int hora, int minutos) {
	return 60 * hora + minutos;
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int l, n;
		cin >> l >> n;
		int hora, minutos, duracion, jugado = 0, ini = cambioAMinutos(8, 0);
		char aux;
		for (int k = 0; k < n; ++k) {
			cin >> hora >> aux >> minutos >> duracion;
			int minutosComienzo = cambioAMinutos(hora, minutos);
			int margen = minutosComienzo - ini;
			if (margen >= l) jugado += margen;
			ini = minutosComienzo + duracion;
		}
		int vueltaCasa = cambioAMinutos(14, 0);
		if (vueltaCasa - ini >= l) jugado += vueltaCasa - ini;
		cout << jugado << '\n';
	}

	return 0;
}