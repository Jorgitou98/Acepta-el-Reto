#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		int fotos = 0;
		unordered_map<string, int> espera;
		string nombre;
		for (int i = 0; i < n; ++i) {
			cin >> nombre;
			if (!espera.count(nombre)) espera[nombre] = 1;
			else espera[nombre]++;
			while (espera.count("Mafalda") && espera.size() >= 3) {
				for (auto it = espera.begin(); it != espera.end();) {
					auto sig = it;
					sig++;
					if (it->second == 1) espera.erase(it);
					else it->second--;
					it = sig;
				}
				fotos++;
			}
		}
		int esperando = 0;
		for (auto it = espera.begin(); it != espera.end(); it++) esperando += it->second;
		cout << fotos << " " << esperando << '\n';
		cin >> n;
	}
	return 0;
}