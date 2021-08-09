#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		char aux;
		cin.get(aux);
		string linea;
		map<string, vector<int>> palabras;
		for (int i = 1; i <= n; ++i){
			getline(cin, linea);
			stringstream ss(linea);
			string nombre;
			while (ss >> nombre) {
				if (nombre.size() <= 2) continue;
				transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
				if (!palabras.count(nombre)) palabras[nombre] = { i };
				else if (palabras[nombre][palabras[nombre].size() - 1] < i) palabras[nombre].push_back(i);
			}
		}
		for (auto par : palabras) {
			cout << par.first << ' ';
			for (int i = 0; i < par.second.size(); ++i) {
				cout << par.second[i];
				if (i < par.second.size() - 1) cout << ' ';
			}
			cout << '\n';
		}
		cout << "----\n";
		cin >> n;
	}

	return 0;
}