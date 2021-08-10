#include <iostream>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		if (n == 1) cout << "1";
		else if (n % 2 == 1) cout << n-1;
		else cout << n;
		cout << '\n';
		cin >> n;
	}

	return 0;
}
