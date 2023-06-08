#include <iostream>
using namespace std;

int ceilDiv(int n, int k) {
	if (n % k == 0) return n / k;
	return n / k + 1;
}

int main() {
	cin.sync_with_stdio(false);
	int p1, b1, f1, p2, b2, f2;
	cin >> p1 >> b1 >> f1 >> p2 >> b2 >> f2;
	while (p1 != 0 && p2 != 0) {
		int viajes1 = 1, viajes2 = 1;
		p1 -= b1; p2 -= b2;
		if (p1 <= 0 && p2 <= 0) {
			cout << "EMPATE 1\n";
			cin >> p1 >> b1 >> f1 >> p2 >> b2 >> f2;
			continue;
		}
		else if (p1 <= 0) {
			cout << "YO 1\n";
			cin >> p1 >> b1 >> f1 >> p2 >> b2 >> f2;
			continue;
		}
		else if (p2 <= 0) {
			cout << "VECINO 1\n";
			cin >> p1 >> b1 >> f1 >> p2 >> b2 >> f2;
			continue;
		}
		int difRestoViajes1 = b1 - f1;
		int difRestoViajes2 = b2 - f2;
		if (difRestoViajes1 > 0 && difRestoViajes2 <= 0)
			cout << "YO " << viajes1 + ceilDiv(p1, difRestoViajes1) << '\n';
		else if (difRestoViajes1 <= 0 && difRestoViajes2 > 0)
			cout << "VECINO " << viajes2 + ceilDiv(p2, difRestoViajes2) << '\n';
		else {
			viajes1 += ceilDiv(p1, difRestoViajes1);
			viajes2 += ceilDiv(p2, difRestoViajes2);
			if (viajes1 < viajes2) cout << "YO " << viajes1 << '\n';
			else if (viajes1 > viajes2) cout << "VECINO " << viajes2 << '\n';
			else cout << "EMPATE " << viajes1 << '\n';
		}
		
		cin >> p1 >> b1 >> f1 >> p2 >> b2 >> f2;
	}



	return 0;
}