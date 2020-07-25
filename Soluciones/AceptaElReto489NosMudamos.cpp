#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool resuelveCaso() {
	int gruposActuales;
	cin >> gruposActuales;
		if (!std::cin) // fin de la entrada
			return false;
	int aulasNuevoEdificio;
	cin >> aulasNuevoEdificio;

	vector<int> grupos(gruposActuales), aulas(aulasNuevoEdificio);

	for (int i = 0; i < gruposActuales; ++i)
		cin >> grupos[i];

	for (int i = 0; i < aulasNuevoEdificio; ++i)
		cin >> aulas[i];

	if (aulasNuevoEdificio >= gruposActuales) {

		sort(grupos.begin(), grupos.end());
		sort(aulas.begin(), aulas.end());
		int j = 0;
		bool correcto = true;
		for (int i = 0; i < gruposActuales && correcto; ++i) {
			correcto = false;
			while (!correcto && j < aulasNuevoEdificio) {
				correcto = (grupos[i] <= aulas[j]);
				++j;
			}
		}
		if (correcto) cout << "SI\n";
		else cout << "NO\n";
	}
	else cout << "NO\n";

		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}