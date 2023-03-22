#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int losetasAncho, losetasAlto;
		cin >> losetasAncho >> losetasAlto;
		int losetasTotal = losetasAncho * losetasAlto;
		int mitad = losetasTotal / 2;
		if (losetasTotal % 2 == 0) cout << mitad << ' ' << mitad;
		else cout << mitad + 1 << ' ' << mitad;
		cout << '\n';
	}
	return 0;
}