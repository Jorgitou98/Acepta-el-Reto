#include <iostream>
#include <vector>
using namespace std;


void muestraPreorden(vector<int> const& nodos, int ini, int fin, vector<int> & preorden) {
	if (ini > fin) return;
	else if (ini == fin) {
		preorden.emplace_back(nodos[ini]);
		return;
	}
	int mitad = ini + (fin - ini + 1) / 2;
	preorden.emplace_back(nodos[mitad]);
	muestraPreorden(nodos, ini, mitad-1, preorden);
	muestraPreorden(nodos, mitad+1, fin, preorden);
}

void muestraPostorden(vector<int> const& nodos, int ini, int fin, vector<int> & postorden) {
	if (ini > fin) return;
	else if (ini == fin) {
		postorden.emplace_back(nodos[ini]);
		return;
	}
	int mitad = ini + (fin - ini + 1) / 2;

	muestraPostorden(nodos, ini, mitad - 1, postorden);
	muestraPostorden(nodos, mitad + 1, fin, postorden);
	postorden.emplace_back(nodos[mitad]);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int val;
	cin >> val;
	while (val != -1) {
		vector<int> nodos;
		do {
			nodos.emplace_back(val);
			cin >> val;
		} while (val != -1);
		vector<int> preorden;
		muestraPreorden(nodos, 0, nodos.size() - 1, preorden);
		for (int i = 0; i < preorden.size() - 1; ++i) {
			cout << preorden[i] << ' ';
		}
		cout << preorden[preorden.size() - 1] << '\n';


		vector<int> postorden;
		muestraPostorden(nodos, 0, nodos.size() - 1, postorden);
		for (int i = 0; i < postorden.size() - 1; ++i) {
			cout << postorden[i] << ' ';
		}
		cout << postorden[postorden.size() - 1] << '\n';

		cin >> val;
	}




	return 0;
}
