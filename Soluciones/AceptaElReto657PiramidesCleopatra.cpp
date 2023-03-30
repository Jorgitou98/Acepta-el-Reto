#include <iostream>
using namespace std;

int main() {
	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		int distIzq = b - a;
		int distDer = c - b;
		if (a < 0 && b > 0) distIzq--;
		else if (b < 0 && c > 0) distDer--;

		if (distIzq < distDer) cout << a << '\n';
		else if (distIzq > distDer) cout << c << '\n';
		else cout << "EMPATE\n";
	}

	return 0;
}