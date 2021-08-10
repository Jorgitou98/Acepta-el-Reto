#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n, t;
	while (cin >> n >> t) {
		vector<int> filasTorres(t);
		vector<int> columnasTorres(t);
		for (int i = 0; i < t; ++i) {
			cin >> filasTorres[i] >> columnasTorres[i];
		}
		sort(filasTorres.begin(), filasTorres.end());
		sort(columnasTorres.begin(), columnasTorres.end());
		cout << filasTorres[(t - 1) / 2] << " " << columnasTorres[(t - 1) / 2] << '\n';
	}

	return 0;
}
