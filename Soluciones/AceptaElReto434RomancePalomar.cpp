#include <iostream>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		int n, m;
		cin >> n >> m;
		if (n <= m) cout << "ROMANCE\n";
		else cout << "PRINCIPIO\n";
	}

	return 0;
}