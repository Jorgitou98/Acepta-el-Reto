#include <iostream>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int entrenamiento;
	cin >> entrenamiento;
	while (entrenamiento != 0) {
		int n;
		cin >> n;
		int acum = 0;
		int comida;
		for (int i = 0; i < n; ++i) {
			cin >> comida;
			acum += comida;
		}
		if (acum % entrenamiento == 0) cout << acum / entrenamiento << '\n';
		else cout << acum / entrenamiento + 1 << '\n';

		cin >> entrenamiento;
	}



	return 0;
}
