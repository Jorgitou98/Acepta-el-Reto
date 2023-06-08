#include <iostream>
#include <cctype>
#include <unordered_set>
#include <string>
using namespace std;

void to_lower_string(string &texto) {
	for (int i = 0; i < texto.length(); ++i) {
		texto[i] = tolower(texto[i]);
	}
}

bool es_vocal(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	char aux;
	cin.get();
	for (int caso = 0; caso < num_casos; ++caso) {
		string texto;
		getline(cin, texto);
		to_lower_string(texto);
		unordered_set<string> silabas;
		int i = 0;
		while (i < texto.size()) {
			if (texto[i] == ' ') i++;
			else if (es_vocal(texto[i])) {
				silabas.insert(texto.substr(i, 1));
				i++;
			}
			else if (i < texto.size() - 1 && es_vocal(texto[i+1])) {
					if (i < texto.size() - 2 && texto[i + 2] != ' ' && !es_vocal(texto[i + 2])) {
						if (i < texto.size() - 3 && es_vocal(texto[i + 3])) {
							silabas.insert(texto.substr(i, 2));
							i += 2;
						}
						else {
							silabas.insert(texto.substr(i, 3));
							i += 3;
						}
					}
					else {
						silabas.insert(texto.substr(i, 2));
						i += 2;
					}
			}
			else i++;
		}
		cout << silabas.size() << '\n';
	}

	return 0;
}