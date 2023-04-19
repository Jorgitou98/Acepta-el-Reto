#include <iostream>
#include <vector>
using namespace std;

#define RAIZ_MAX 46340

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> primos;
	// Raíz del máximo
	vector<bool> marcado(RAIZ_MAX + 1, false);
	for (int i = 2; i < RAIZ_MAX; ++i) {
		if (!marcado[i]) {
			primos.push_back(i);
			for (int j = i * i; j < RAIZ_MAX; j += i) {
				marcado[j] = true;
			}
		}
	}
	int k;
	while (cin >> k) {
		int div_cuad = 1;
		for (int primo : primos) {
			if (primo * primo > k) break;
			int veces = 0;
			while (k % primo == 0) {
				k = k / primo;
				veces++;
			}
			if (veces > 0) div_cuad *= (2 * veces + 1);
		}
		if (k != 1) div_cuad *= 3;
		cout << (div_cuad + 1) / 2 << '\n';
	}
}