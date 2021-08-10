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
		int numCeros = 0;
		int divCincos = n/5;
		while (divCincos > 0){
			numCeros += divCincos;
			divCincos /= 5;
		}
		cout << numCeros << '\n';
	}
	return 0;
}