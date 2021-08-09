#include <iostream>
#include <vector>
using namespace std;

int mod(int n, int m) {
	if (n < 0) n += m;
	return n % m;
}


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	while (n != 0 || k != 0) {
		// El numero con que llega a la posición (n-1,0)
		int numActual = n*(n / 2) + k;
		cout << n * (2 * numActual + n - 1) / 2 << '\n';
		cin >> n >> k;
	}

	return 0;
}