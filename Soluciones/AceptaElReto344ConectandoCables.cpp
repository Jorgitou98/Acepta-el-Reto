#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	for (int caso = 0; caso < num_casos; ++caso) {
		int cables;
		cin >> cables;
		int machos = 0;
		int hembras = 0;
		string cable_desc;
		for (int i = 0; i < cables; ++i) {
			cin >> cable_desc;
			if (cable_desc[0] == 'H') hembras++;
			else machos++;
			if (cable_desc[1] == 'H') hembras++;
			else machos++;
		}
		if (hembras == machos) cout << "POSIBLE\n";
		else cout << "IMPOSIBLE\n";
	}


	return 0;
}