#include <iostream>
using namespace std;
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while (cin >> n) {
		int cifras = 1;
		int dividendo = 1;
		while ((dividendo % n) != 0) {
			dividendo = (dividendo % n) * 10 + 1;
			cifras++;
		}
		cout << cifras << '\n';
	}
	return 0;
}