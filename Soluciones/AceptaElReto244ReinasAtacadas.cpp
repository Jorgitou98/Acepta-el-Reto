#include <iostream>
#include <vector>
using namespace std;


int main() {
	int dim, num_reinas;
	cin >> dim >> num_reinas;
	while (dim != 0 || num_reinas != 0) {
		vector<bool> filas(dim, false);
		vector<bool> columnas(dim, false);
		int num_diags = 2 * dim - 1;
		vector<bool> diagonales(num_diags, false);
		vector<bool> otras_diagonales(num_diags, false);
		bool ataques = false;
		int fila, columna;
		for (int reina = 0; reina < num_reinas; reina++) {
			cin >> fila >> columna;
			fila--;
			columna--;

			if (filas[fila])
				ataques = true;
			if(columnas[columna])
				ataques = true;
			int diagonal = columna - fila;
			if(diagonales[diagonal + num_diags / 2])
				ataques = true;
			if (otras_diagonales[fila + columna])
				ataques = true;

			filas[fila] = true;
			columnas[columna ] = true;
			diagonales[diagonal + num_diags / 2] = true;
			otras_diagonales[fila + columna] = true;
		}
		if (ataques) cout << "SI\n";
		else cout << "NO\n";


		cin >> dim >> num_reinas;
	}




	return 0;
}