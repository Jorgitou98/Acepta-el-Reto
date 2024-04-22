#include <iostream>
using namespace std;

#define MOD 46337

int main(){
	int n, p;
	cin >> n >> p;
	while (n != 0 || p != 0) {
		int suma = 0;
		for (int i = 1; i <= n; ++i) {
			int sumando = 1;
			for (int j = 0; j < p; ++j) {
				sumando = (sumando * i) % MOD;
			}
			suma = (suma + sumando) % MOD;
		}
		cout << suma << '\n';

		cin >> n >> p;
	}
}