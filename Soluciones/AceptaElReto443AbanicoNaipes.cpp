#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num_cartas;
	cin >> num_cartas;
	while (num_cartas != 0) {
		vector<int> cartas(num_cartas);
		vector<int> cartas_copia(num_cartas);
		for (int i = 0; i < num_cartas; ++i) {
			cin >> cartas[i];
			cartas_copia[i] = cartas[i];
		}
		sort(cartas_copia.begin(), cartas_copia.end());
		int i = 0, j = 0;
		int quietas = 0;
		while (i < num_cartas && j < num_cartas) {
			if (cartas[i] != cartas_copia[j]) i++;
			else if (cartas[i] == cartas_copia[j]) {
				quietas++;
				i++;
				j++;
			}
		}
		cout << num_cartas - quietas << '\n';

		cin >> num_cartas;
	}


	return 0;
}
