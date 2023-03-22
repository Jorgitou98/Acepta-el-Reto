#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int p;
	cin >> p;
	while (p != 0) {
		int ultimaFecha = 0;
		int d, n;
		for (int i = 0; i < p; ++i) {
			cin >> d >> n;
			if (ultimaFecha >= d) {
				int k = (ultimaFecha - d) / n + 1;
				ultimaFecha = d + k * n;
			}
			else ultimaFecha = d;
		}
		cout << ultimaFecha << '\n';
		cin >> p;
	}

	return 0;
}