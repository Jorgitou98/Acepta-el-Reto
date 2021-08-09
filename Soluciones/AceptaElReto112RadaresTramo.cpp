#include <iostream>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int dist, velMax, tiempo;
	cin >> dist >> velMax >> tiempo;
	while (dist != 0 || velMax != 0 || tiempo != 0) {
		if (dist <= 0 || velMax <= 0 || tiempo <= 0) cout << "ERROR\n";
		else {
			double vel = 3.6 * dist / tiempo;
			if (vel <= velMax) cout << "OK\n";
			else if (vel < velMax * 1.2) cout << "MULTA\n";
			else cout << "PUNTOS\n";
		}

		cin >> dist >> velMax >> tiempo;
	}

	return 0;
}