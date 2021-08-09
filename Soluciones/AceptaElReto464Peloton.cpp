#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct tCorredor {
	int tiempo;
	int posDado, posCarrera;
};


bool menorTiempo(tCorredor const& corredor1, tCorredor const& corredor2) {
	return corredor1.tiempo < corredor2.tiempo;
}

int tiempoEnSegundos(int horas, int minutos, int segundos) {
	return horas * 3600 + minutos * 60 + segundos;
}

bool menorPosicion(tCorredor const& corredor1, tCorredor const& corredor2) {
	return corredor1.posDado < corredor2.posDado;
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	while (cin >> n) {
		char aux;
		vector<tCorredor> corredores(n);
		int hh, mm, ss;
		for (int i = 0; i < n; ++i) {
			cin >> hh >> aux >> mm >> aux >> ss;
			corredores[i].tiempo = tiempoEnSegundos(hh, mm, ss);
			corredores[i].posDado = i;
		}
		sort(corredores.begin(), corredores.end(), menorTiempo);
		int pos = 1;
		corredores[0].posCarrera = pos;
		for (int i = 1; i < n; ++i) {
			if (corredores[i].tiempo - corredores[i-1].tiempo > 1) pos = i+1;
			corredores[i].posCarrera = pos;
		}
		sort(corredores.begin(), corredores.end(), menorPosicion);
		for (tCorredor const& corredor : corredores) cout << corredor.posCarrera << '\n';
		cout << "---\n";
	}


	return 0;
}