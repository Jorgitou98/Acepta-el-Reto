#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, n;
	cin >> a >> b >> n;
	while (a != 0 || b != 0 || n != 0) {
		if ((n % 6) == 0) cout <<  a << '\n';
		else if ((n % 6) == 1) cout << b << '\n';
		else if ((n % 6) == 2) cout << (b - a) << '\n';
		else if ((n % 6) == 3) cout << -a << '\n';
		else if ((n % 6) == 4) cout << -b << '\n';
		else cout << (a - b) << '\n';
		cin >> a >> b >> n;
	}
	return 0;
}