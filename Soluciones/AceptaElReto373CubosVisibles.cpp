#include <iostream>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		long long int n;
		cin >> n;
		long long int cubitos = 6*n*n-12*n+8;
		cout << cubitos << '\n';
	}

	return 0;
}