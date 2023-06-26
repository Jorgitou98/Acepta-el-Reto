#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> get_cifras(int n) {
	vector<int> cifras;
	while (n > 0) {
		cifras.push_back(n % 10);
		n /= 10;
	}
	return cifras;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		vector<int> cifras = get_cifras(n);
		sort(cifras.begin(), cifras.end());
		int mayor = 0;
		int pot = 1;
		for (int i = 0; i < cifras.size(); i++) {
			mayor += cifras[i] * pot;
			pot *= 10;
		}
		int menor = 0;
		pot = 1;
		for (int i = cifras.size() - 1; i >= 0; i--) {
			menor += cifras[i] * pot;
			pot *= 10;
		}
		int diferencia = mayor - menor;
		int cociente = diferencia / 9;

		cout << mayor << " - " << menor << " = " << diferencia << " = " << cociente << " x 9\n";

		cin >> n;
	}


}