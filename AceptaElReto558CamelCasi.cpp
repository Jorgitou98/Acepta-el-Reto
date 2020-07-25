#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

string minusculas(string cadena) {
	for (int i = 0; i < cadena.length(); i++) {
		// Y cambiar cada letra por su representación
		// minúscula
		cadena[i] = tolower(cadena[i]);
	}
	return cadena;
}


bool resuelveCaso() {
	int n;
	cin >> n;
		if (!std::cin) // fin de la entrada
			return false;
	unordered_map <string, string> camel;
	string cad;
	vector <string> palabras(n);
	for (int i = 0; i < n; ++i) {
		cin >> cad;
		string cadenaMinuscula = minusculas(cad);
		palabras[i] = cadenaMinuscula;
		if (!camel.count(cadenaMinuscula) || cad < camel[cadenaMinuscula]) camel[cadenaMinuscula] = cad;
	}
	for (auto const& elem : palabras) {
		cout << camel[elem] << '\n';
	}

	cout << "---\n";

		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
