#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	char aux;
	cin.get(aux);
	for (int caso = 0; caso < num_casos; ++caso) {
		string frase;
		getline(cin, frase);
		stringstream ss(frase);
		string palabra;
		while (ss >> palabra) {
			if (palabra[0] > 64 && palabra[0] < 91)
				cout << palabra[0];
		}
		cout << '\n';


	}


	return 0;
}