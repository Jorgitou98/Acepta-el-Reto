#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int necesarios, recompensa, iniciales;
	cin >> necesarios >> recompensa >> iniciales;
	while (iniciales != 0 || necesarios != 0 || recompensa != 0) {
		if (necesarios > iniciales || recompensa == 0) {
			cout << iniciales << ' ' << iniciales << '\n';
			cin >> necesarios >> recompensa >> iniciales;
			continue;
		}

		if (recompensa >= necesarios) {
			cout << "RUINA\n";
			cin >> necesarios >> recompensa >> iniciales;
			continue;
		}

		int num_iteraciones_recompensa = (iniciales - necesarios) / (necesarios - recompensa) + 1;
		int total_comidos = iniciales + num_iteraciones_recompensa * recompensa;
		int restantes = iniciales - num_iteraciones_recompensa * (necesarios - recompensa);

		cout << total_comidos << ' ' << restantes << '\n';
		cin >> necesarios >> recompensa >> iniciales;
	}
	return 0;
}