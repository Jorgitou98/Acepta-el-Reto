#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool resuelveCaso() {
	string linea;
	cin >> linea;
	vector <int> ascii;
		if (!std::cin) // fin de la entrada
			return false;
	int j = 0;
	while (j < linea.size()) {
		if (linea[j] == '1') {
			ascii.push_back(stoi(linea.substr(j, 3)));
			j = j + 3;
		}
		else {
			ascii.push_back(stoi(linea.substr(j, 2)));
			j = j + 2;
		}
	}
	for (int valor : ascii) {
		cout << char(valor);
	}
	cout << '\n';

		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
