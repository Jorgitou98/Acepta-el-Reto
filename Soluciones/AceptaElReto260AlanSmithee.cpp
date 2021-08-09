#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	char aux;
	cin.get(aux);
	for (int i = 0; i < numcasos; ++i) {
		string frase1;
		getline(cin, frase1);
		unordered_map <char, int> numApariciones;
		for (char c : frase1) {
			if (c == ' ') continue;
			c = tolower(c);
			if (!numApariciones.count(c)) numApariciones[c] = 1;
			else numApariciones[c]++;
		}
		string frase2;
		getline(cin, frase2);
		bool frase2ContenidaEn1 = true;
		for (char c : frase2) {
			if (c == ' ') continue;
			c = tolower(c);
			if (!numApariciones.count(c)) {
				frase2ContenidaEn1 = false;
				break;
			}
			else if (numApariciones[c] == 1) numApariciones.erase(c);
			else numApariciones[c]--;
		}
		if (frase2ContenidaEn1 && numApariciones.empty()) cout << "SI\n";
		else cout << "NO\n";
	}

	return 0;
}