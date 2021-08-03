#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	vector<int> primos;
	for (int i = 2; i <= 46340; ++i) {
		bool esPrimo = true;
		for (int j = 2; j <= sqrt(i); ++j) {
			if (i % j == 0) {
				esPrimo = false;
				break;
			}
		}
		if (esPrimo) primos.push_back(i);
	}
	int casos;
	cin >> casos;
	int n;
	for (int i = 0; i < casos; ++i) {
		cin >> n;
		int k = n;
		for (int primo: primos) {
			if (primo > sqrt(k)) break;
			while (k % (primo * primo) == 0) k /= (primo * primo);
		}
		cout << k << '\n';
	}
	
	return 0;
}