#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	string palabra;
	while (cin >> palabra) {
		unordered_map<char, int> apariciones;
		for (char c = '0'; c <= '9'; c++) apariciones[c] = 0;
		for (char c : palabra) apariciones[c]++;
		int aparicionesParaTodos = apariciones['0'];
		bool subnormal = true;
		for (auto par : apariciones) {
			if (par.second != aparicionesParaTodos) {
				subnormal = false;
				break;
			}
		}
		if (subnormal) cout << "subnormal\n";
		else cout << "no subnormal\n";		
	}

	return 0;
}