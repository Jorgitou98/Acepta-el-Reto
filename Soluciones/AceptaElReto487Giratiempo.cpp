#include <iostream>
#include <algorithm>
using namespace std;

long long int vueltasExtra(long long int const& ant, long long int const& n) {
	long long int nuevo = (n + ant) / 3600;
	if (nuevo == ant) return ant;
	else vueltasExtra(nuevo, n);
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	long long int n;
	for (int i = 0; i < numcasos; ++i) {
		cin >> n;
		cout << n + vueltasExtra(0, n) << '\n';
	}

	return 0;
}