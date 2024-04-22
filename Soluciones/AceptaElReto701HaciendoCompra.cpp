#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int unidades;
	cin >> unidades;
	while (unidades != 0) {
		int bloques;
		cin >> bloques;
		unordered_map<int, int> caducidad;
		int num, fecha_cad;
		for (int i = 0; i < bloques; ++i) {
			cin >> num >> fecha_cad;
			if (!caducidad.count(fecha_cad)) caducidad[fecha_cad] = num;
			else caducidad[fecha_cad] += num;
		}
		vector<pair<int, int>> pares_cad(caducidad.begin(), caducidad.end());
		sort(pares_cad.begin(), pares_cad.end(), greater<pair<int,int>>());
		int cont = 0;
		int min_tomada = 0;
		while (cont < pares_cad.size() && unidades > 0) {
			int tomar = min(pares_cad[cont].second, unidades);
			unidades -= tomar;
			min_tomada = pares_cad[cont].first;
			cont++;
		}
		cout << min_tomada << '\n';



		cin >> unidades;
	}


	return 0;
}
