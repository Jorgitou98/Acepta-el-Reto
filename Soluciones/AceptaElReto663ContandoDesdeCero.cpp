#include <iostream>
using namespace std;


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	int anyo;
	for (int i = 0; i < num_casos; ++i) {
		cin >> anyo;
		if (anyo > 0) cout << anyo - 1 << '\n';
		else cout << anyo << '\n';
	}

	return 0;
}