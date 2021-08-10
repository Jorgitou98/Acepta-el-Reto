#include <iostream>
#include <algorithm>
using namespace std;


int altura() {
	char c;
	cin >> c;
	if (c == '.') return 0;
	else return max(altura(), altura()) + 1;
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		cout << altura() << '\n';
	}

	return 0;
}