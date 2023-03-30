#include <iostream>
#include <string>
using namespace std;

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	string arbol;
	while (cin >> arbol) {
		int pos = 0;
		string sol;
		while (pos < arbol.length() - 2) {
			if (arbol[pos] != '.' && arbol[pos + 1] == '.' && arbol[pos + 2] == '.') {
				sol.push_back(arbol[pos]);
				pos += 3;
			}
			else pos++;
		}
		cout << sol << '\n';
	}
	return 0;
}