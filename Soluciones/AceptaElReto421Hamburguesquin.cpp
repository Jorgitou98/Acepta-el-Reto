#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tIntervalo {
	int ini, fin;
};

bool menor(tIntervalo const& i1, tIntervalo const& i2) {
	return i1.ini < i2.ini;
}


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int l, n;
	while (cin >> l >> n) {
		if (n == 0) {
			cout << -1 << '\n';
			continue;
		}
		vector<tIntervalo> intervalos(n);
		int centro, radio;
		for (int i = 0; i < n; ++i) {
			cin >> centro >> radio;
			intervalos[i].ini = centro - radio;
			intervalos[i].fin = centro + radio;
		}
		sort(intervalos.begin(), intervalos.end(), menor);
		if (intervalos[0].ini > 0) {
			cout << -1 << '\n';
			continue;
		}
		int pos = 0, numIntervalos = 0;
		bool puedeCubrir = true, cubierto = false;
		int finOrigen = 0, finObt = 0;
		while (pos < n && puedeCubrir && !cubierto) {
			while (pos < n && intervalos[pos].ini <= finOrigen) {
				if (intervalos[pos].fin > finObt) finObt = intervalos[pos].fin;
				pos++;
			}
			if (finObt > finOrigen) {
				if (finObt >= l) cubierto = true;
				else finOrigen = finObt;
				numIntervalos++;
			}
			else puedeCubrir = false;
		}
		if (cubierto) cout << intervalos.size() - numIntervalos << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}