#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		if (n == 1) cout << "10\n";
		else if (n == 2) cout << "9\n";
		else {
			cout << "9" << setw((n - 1) / 2 + 1 ) << setfill('0') << "\n";
		}
		cin >> n;
	}

	return 0;
}