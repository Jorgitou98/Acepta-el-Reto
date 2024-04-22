#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	int eventos;
	while (cin >> eventos) {
		vector<int> tiempos(eventos);
		string palabra_aux;
		for (int i = 0; i < eventos; i++) {
			cin >> tiempos[i];
			getline(cin, palabra_aux);
		}
		int q;
		cin >> q;
		for (int consulta = 0; consulta < q; consulta++) {
			int n_eventos;
			cin >> n_eventos;
			int i = 0, j = n_eventos - 1;
			int min_tiempo = tiempos[j] - tiempos[i];
			int mejor_ini = tiempos[i], mejor_fin = tiempos[j];
			int mejor_num_eventos = n_eventos;
			while (j < eventos) {
				if ((j - i + 1) < n_eventos || j < (eventos - 1) && tiempos[j] == tiempos[j + 1])
					j++;
				else {
					if ((tiempos[j] - tiempos[i]) < min_tiempo || (tiempos[j] - tiempos[i]) == min_tiempo && (j - i + 1) > mejor_num_eventos) {
						min_tiempo = tiempos[j] - tiempos[i];
						mejor_ini = tiempos[i];
						mejor_fin = tiempos[j];
						mejor_num_eventos = j - i + 1;
					}
					i++;
				}
			}
			cout << mejor_ini << ' ' << mejor_fin << ' ' << mejor_num_eventos << '\n';
		}
		cout << "---\n";
	}

	return 0;
}