#include <iostream>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int n; 
		cin >> n;
		cout << n / 3 << '\n';
	}

	return 0;
}