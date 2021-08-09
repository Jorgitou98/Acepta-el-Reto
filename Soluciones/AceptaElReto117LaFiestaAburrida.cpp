#include <iostream>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		string palabra;
		cin >> palabra >> palabra;
		cout << "Hola, " << palabra << ".\n";
	}

	return 0;
}