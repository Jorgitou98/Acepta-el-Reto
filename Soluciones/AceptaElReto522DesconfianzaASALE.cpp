#include <iostream>
#include <string>
using namespace std;


string traducirPalabra(string const& palabra) {
	string traduccion = "";
	int i = 0;
	while (i < palabra.size()) {
		if (palabra[i] == 'c' && i < palabra.size() - 1 && palabra[i + 1] == 'h') {
			traduccion.push_back('c' + 1);
			i = i + 2;
		}
		else if (palabra[i] == 'l' && i < palabra.size() - 1 && palabra[i + 1] == 'l') {
			traduccion.push_back('l' + 2);
			i = i + 2;
		}
		else if (palabra[i] > 'l') {
			traduccion.push_back(palabra[i] + 2);
			i++;
		}
		else if (palabra[i] > 'c') {
			traduccion.push_back(palabra[i] + 1);
			i++;
		}
		else {
			traduccion.push_back(palabra[i]);
			i++;
		}
	}
	return traduccion;
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	string palabra1, palabra2;
	while (cin >> palabra1 >> palabra2) {
		string traduccion1 = traducirPalabra(palabra1);
		string traduccion2 = traducirPalabra(palabra2);
		if (traduccion1 <= traduccion2) cout << palabra1 << '\n';
		else cout << palabra2 << '\n';
	}

	return 0;
}
