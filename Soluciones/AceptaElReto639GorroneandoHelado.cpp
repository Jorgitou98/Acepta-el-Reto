#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while (cin >> n) {
		vector<int> frutos(n);
		int suma = 0;
		for (int i = 0; i < n; ++i) {
			cin >> frutos[i];
			suma += frutos[i];
		}
		int i = 0, j = n - 1;
		int izq = frutos[i], der = frutos[j];
		int medio = suma - izq - der;
		int minDif = max(izq, max(medio, der)) - min(izq, min(medio, der));
		while (i < j) {
			int minAct = min(izq, min(medio, der));
			int maxAct = max(izq, max(medio, der));
			int DifMueveI = max(izq + frutos[i + 1], max(medio - frutos[i + 1], der)) - min(izq + frutos[i + 1], min(medio - frutos[i + 1], der));
			int DifMueveJ = max(izq, max(medio - frutos[j - 1], der + frutos[j - 1])) - min(izq, min(medio - frutos[j - 1], der + frutos[j - 1]));
			minDif = min(minDif, DifMueveI);
			minDif = min(minDif, DifMueveJ);
			if (izq + frutos[i + 1] < der + frutos[j - 1]) {
				i++;
				izq += frutos[i];
				medio -= frutos[i];
			}
			else {
				j--;
				der += frutos[j];
				medio -= frutos[j];
			}
		}

		cout << minDif << '\n';

	}


	return 0;
}