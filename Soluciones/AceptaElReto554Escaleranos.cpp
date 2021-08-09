#include <iostream>
#include <vector>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int peldanos;
	cin >> peldanos;
	while (peldanos != 0) {
		int numPasos;
		cin >> numPasos;
		vector<int> pasos(numPasos);
		for (int i = 0; i < numPasos; ++i) cin >> pasos[i];
		vector<int> manerasSumar(peldanos+1, 0);
		manerasSumar[0] = 1;
		for (int i = 1; i < peldanos + 1; ++i) {
			for (int paso : pasos) {
				int k = i - paso;
				if (k < 0) continue;
				manerasSumar[i] = ((manerasSumar[i] % 1000000007) + (manerasSumar[k] % 1000000007)) % 1000000007;
			}
		}
		cout << manerasSumar[peldanos] << '\n';
		cin >> peldanos;
	}
	return 0;
}