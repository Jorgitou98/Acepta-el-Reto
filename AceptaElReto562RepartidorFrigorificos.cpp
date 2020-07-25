#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool resuelveCaso() {
	int C, F, N;
	cin >> C >>  F >> N;
	if (C == 0)
			return false;


	vector <int> equis(N);
	vector <int> ies(N);
	for (int i = 0; i < N; ++i) {
		cin >> equis[i] >> ies[i];
	}
	sort(equis.begin(), equis.end());
	sort(ies.begin(), ies.end());

	cout << equis[(N-1) / 2] << " " << ies[(N-1) / 2] << '\n';

		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
