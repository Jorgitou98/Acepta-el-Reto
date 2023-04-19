#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int p;
	cin >> p;
	while (p != 0) {
		int n = (-1 + sqrt(1 + 8 * p)) / 2;
		int sob = p - n * (n + 1) / 2;
		cout << n << ' ' << sob << '\n';
		cin >> p;
	}


	return 0;
}