#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

#define MOD 1000000007

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		string simbolo;
		unordered_map<char, map<unsigned int, vector<string>>> simbolos;
		for (int i = 0; i < n; ++i) {
			cin >> simbolo;
			if (!simbolos.count(simbolo[0])) {
				simbolos[simbolo[0]] = { { simbolo.length(), {simbolo} } };
			}
			else if (!simbolos[simbolo[0]].count(simbolo.length())) {
				simbolos[simbolo[0]][simbolo.length()] = { simbolo };
			}
			else simbolos[simbolo[0]][simbolo.length()].push_back(simbolo);
		}
		string mensaje;
		cin >> mensaje;
		vector<int> posibilidades(mensaje.length() + 1, 0);
		posibilidades[0] = 1;
		for (int i = 0; i < mensaje.length(); ++i) {
			if (mensaje[i] == '0') {
				posibilidades[i + 1] = posibilidades[i];
				continue;
			}
			if (!simbolos.count(mensaje[i])) continue;
			for (const auto& par : simbolos[mensaje[i]]) {
				if (i + par.first > mensaje.length()) break;
				for (string const& simb : par.second) {
					if (mensaje.substr(i, par.first) == simb) {
						posibilidades[i + par.first] += posibilidades[i];
						posibilidades[i + par.first] %= MOD;
					}
				}
			}
		}

		cout << posibilidades[mensaje.length()] << '\n';

		cin >> n;
	}

}