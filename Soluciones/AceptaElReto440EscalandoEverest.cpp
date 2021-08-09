#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		int valor;
		cin >> valor;
		int grupos = 1, tamGrupo = 1, grupoMin = n, grupoMax = 0, velGrupo = valor;
		for (int i = 1; i < n; ++i) {
			cin >> valor;
			if (valor < velGrupo) {
				grupos++;
				grupoMin = min(grupoMin, tamGrupo);
				grupoMax = max(grupoMax, tamGrupo);
				tamGrupo = 1;
				velGrupo = valor;
			}
			else tamGrupo++;
		}
		grupoMin = min(grupoMin, tamGrupo);
		grupoMax = max(grupoMax, tamGrupo);
		cout << grupos << " " << grupoMin << " " << grupoMax << '\n';
		cin >> n;
	}
	return 0;
}