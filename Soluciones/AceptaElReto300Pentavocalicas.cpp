#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		string palabra;
		cin >> palabra;
		unordered_set<char> vocalesEncontradas;
		for (char car : palabra) {
			if (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u' ) vocalesEncontradas.insert(car);
		}
		if (vocalesEncontradas.size() == 5) cout << "SI\n";
		else cout << "NO\n";

	}
	return 0;
}