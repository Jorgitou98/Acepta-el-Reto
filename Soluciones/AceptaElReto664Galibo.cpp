#include <iostream>
using namespace std;


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int num_puentes;
	cin >> num_puentes;
	while (num_puentes != 0) {
		int min_requerido = 801;
		for (int i = 0; i < num_puentes; ++i) {
			int carriles;
			int maximo_carriles = 0;
			cin >> carriles;
			int altura;
			for (int j = 0; j < carriles; j++) {
				cin >> altura;
				if (altura > maximo_carriles)
					maximo_carriles = altura;
			}
			if (maximo_carriles < min_requerido)
				min_requerido = maximo_carriles;
		}
		cout << min_requerido << '\n';

		cin >> num_puentes;
	}




	return 0;
}