#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		vector<int> pasajeros(n);
		unordered_set<int> cubiertas;
		for (int i = 0; i < n; ++i) {
			cin >> pasajeros[i];
			cubiertas.insert(pasajeros[i]);
		}

		int num_operaciones;
		cin >> num_operaciones;
		int tam_cola = n;
		string operacion;
		int valor;
		for (int i = 0; i < num_operaciones; ++i) {
			cin >> operacion >> valor;
			if (operacion == "CONSULTA")
				cout << pasajeros[valor-1] << '\n';
			else if (operacion == "EMBARQUE") {
				auto it = cubiertas.find(valor);
				if (it == cubiertas.end()) {
					cout << tam_cola << '\n';
					continue;
				}
				int act = 0;
				int borrados = 0;
				for (int j = 0; j < tam_cola; ++j) {
					if (pasajeros[j] != valor) {
						pasajeros[act] = pasajeros[j];
						act++;
					}
					else borrados++;
				}
				tam_cola -= borrados;
				cubiertas.erase(it);
				cout << tam_cola << '\n';
			}
		}

		cout << "*\n";
		cin >> n;
	}
}