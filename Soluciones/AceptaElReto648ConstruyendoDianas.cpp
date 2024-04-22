#include <iostream>
#include <vector>
using namespace std;

struct estado {
	int ultimo;
	int usados;
};


void resolver(int objetivo, int suma, int usados, vector<int> const& sectores, vector<estado> & mejor_ultimo) {
	
	for (int sector : sectores) {
		if (suma + sector > objetivo) continue;
		if (mejor_ultimo[suma + sector].usados == -1 || usados + 1 < mejor_ultimo[suma + sector].usados) {
			mejor_ultimo[suma + sector].ultimo = sector;
			mejor_ultimo[suma + sector].usados = usados + 1;
			if (suma + sector < objetivo) resolver(objetivo, suma + sector, usados + 1, sectores, mejor_ultimo);
		}
	}
}

vector<int> reconstruye_sol(int objetivo, vector<estado> const& mejor_ultimo) {
	vector<int> sol(mejor_ultimo[objetivo].usados);
	int num = objetivo;
	for (int pos = sol.size() - 1; pos >= 0; --pos) {
		sol[pos] = mejor_ultimo[num].ultimo;
		num -= mejor_ultimo[num].ultimo;
	}
	return sol;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int objetivo, num_sectores;
	while (cin >> objetivo >> num_sectores) {
		vector<int> sectores(num_sectores);
		for (int i = num_sectores - 1; i >= 0; i--)
			cin >> sectores[i];

		vector<estado> mejor_ultimo(objetivo + 1, {-1, -1});
		resolver(objetivo, 0, 0, sectores, mejor_ultimo);
		if (mejor_ultimo[objetivo].usados == -1) cout << "Imposible\n";
		else {
			vector<int> sol = reconstruye_sol(objetivo, mejor_ultimo);
			cout << sol.size() << ':';
			for (int valor : sol) cout << ' ' << valor;
			cout << '\n';
		}

	}




	return 0;
}