#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	unordered_map<string, string> paises = {{"0", "EEUU"}, {"380", "Bulgaria"} , {"50", "Inglaterra"}, 
											{"539", "Irlanda"}, {"560", "Portugal"}, {"70", "Noruega"},
											{"759", "Venezuela"} , {"850", "Cuba"} , {"890", "India"} };
	string codigo;
	cin >> codigo;
	while (codigo != "0") {
		int valor = 0;
		for (int i = 0; i < codigo.length() - 1; ++i) {
			if(i % 2 == 0) valor += 3* (codigo[codigo.length() - 2 - i] - 48);
			else valor += (codigo[codigo.length() - 2 - i] - 48);
		}
		bool correcto = (valor + (codigo[codigo.length() - 1] - 48)) % 10 == 0;
		if (correcto) cout << "SI";
		else cout << "NO";
		if (codigo.length() > 8 && correcto) {
			if (codigo.length() < 13) cout << " EEUU";
			else if (paises.count(codigo.substr(0, 1)))
				cout << ' ' << paises[codigo.substr(0, 1)];

			else if (paises.count(codigo.substr(0, 2)))
				cout << ' ' << paises[codigo.substr(0, 2)];

			else if (paises.count(codigo.substr(0, 3)))
				cout << ' ' << paises[codigo.substr(0, 3)];
			else cout << " Desconocido";
		}
		cout << '\n';


		cin >> codigo;
	}
}