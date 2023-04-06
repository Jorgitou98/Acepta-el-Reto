#include <iostream>
using namespace std;


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int paginaIni;
	cin >> paginaIni;
	while (paginaIni != 0) {
		cout << paginaIni;
		int paginaAnt = paginaIni;
		int ultimaEscrita = paginaIni;
		int pagina;
		cin >> pagina;
		while (pagina != 0) {
			if (paginaAnt + 1 < pagina) {
				if (ultimaEscrita < paginaAnt) cout << '-' << paginaAnt;
				cout << ',' << pagina;
				ultimaEscrita = pagina;
			}
			paginaAnt = pagina;
			cin >> pagina;
		}
		if (ultimaEscrita < paginaAnt) cout << '-' << paginaAnt;
		cout << '\n';
		cin >> paginaIni;
	}

	return 0;
}