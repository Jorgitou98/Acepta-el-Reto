#include <iostream>
#include <string>
using namespace std;


void muestra_derivada(int coef, int grado, bool & mostrado_alguno) {
	if (grado == 0) return;
	if (mostrado_alguno) cout << '+';
	if (grado == 1) cout << coef;
	else if (grado == 2) {
		if (coef * grado != 1) cout << coef * grado;
		cout << 'x';
	}
	else {
		if (coef * grado != 1) cout << coef * grado;
		cout << "x^" << grado - 1;
	}
	mostrado_alguno = true;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	string funcion;
	while (cin >> funcion) {
		bool algo_mostrado = false;
		bool lee_coef = true;
		bool lee_grado = false;
		bool mostrado_alguno = false;
		int coef = 0;
		int grado = 0;

		for (int i = 0; i < funcion.size(); ++i) {
			if (funcion[i] == '+') {
				muestra_derivada(coef, grado, mostrado_alguno);
				coef = 0;
				grado = 0;
				lee_coef = true;
				lee_grado = false;
			}
			else if (funcion[i] == 'x') {
				if (i == funcion.size() || funcion[i + 1] != '^')
					grado = 1;
				if (coef == 0) coef = 1;
				lee_coef = false;
			}
			else if (funcion[i] == '^') {
				lee_grado = true;
			}
			else if (lee_coef) {
				coef *= 10;
				coef += funcion[i] - '0';
			}
			else if (lee_grado) {
				grado *= 10;
				grado += funcion[i] - '0';
			}

		}
		muestra_derivada(coef, grado, mostrado_alguno);
		if (!mostrado_alguno) cout << '0';
		cout << '\n';



	}



	return 0;
}