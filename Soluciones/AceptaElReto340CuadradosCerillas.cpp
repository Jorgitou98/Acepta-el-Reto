#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int n, m;
		cin >> m >> n;
		cout << n * (m + 1) + m * (n + 1) << '\n';
	}
	
	return 0;
}