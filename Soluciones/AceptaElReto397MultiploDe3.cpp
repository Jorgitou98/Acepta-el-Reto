#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


void resuelveCaso() {
	int n;
	cin >> n;
	if (n % 3 == 1) cout << "NO\n";
	else cout << "SI\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
