#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void resuelveCaso() {
	int dado1, dado2;
	cin >> dado1 >> dado2;
	vector <int> v (dado1+dado2+2, 0);
	for (int i = 1; i <= dado1; ++i)
		for (int j = 1; j <= dado2; ++j)
			v[i + j]++;
	int maxim = 0;
	for (int i = 0; i < v.size(); ++i) maxim = max(maxim, v[i]);
	bool primera = true;
	for (int i = 0; i < v.size(); ++i)
		if (v[i] == maxim) {
			if (primera) {
				cout << i;
				primera = false;
			}
			else cout << " " << i;
		}
	cout << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
