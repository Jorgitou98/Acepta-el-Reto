#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int n;
		cin >> n;
		int picos = 0, valles = 0;
		int antAnt, ant, act;
		for (int i = 0; i < n; ++i) {
			if (i == 0) cin >> antAnt;
			else if (i == 1) cin >> ant;
			else {
				cin >> act;
				if (antAnt < ant && ant > act) picos++;
				else if (antAnt > ant && ant < act) valles++;
				antAnt = ant;
				ant = act;
			}
		}
		cout << picos << ' ' << valles << '\n';
	}
	return 0;
}