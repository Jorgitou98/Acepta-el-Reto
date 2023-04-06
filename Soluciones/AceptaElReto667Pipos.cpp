#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;



int main() {
	int anyo;
	cin >> anyo;
	while (anyo != 0) {
		unordered_map<int, int> uvas_persona;
		for (int i = 0; i < 4; ++i) {
			int cifra = anyo % 10;
			if (!uvas_persona.count(cifra)) uvas_persona.insert({ cifra,1 });
			else uvas_persona[cifra]++;
			anyo /= 10;
		}
		for (auto iter = uvas_persona.begin(); iter != uvas_persona.end(); ++iter) {
			iter->second *= 3;
		}

		vector<int> uvas(10);
		for (int i = 0; i < 10; ++i) cin >> uvas[i];

		int min_invitados = 1000000000;
		for (auto iter = uvas_persona.begin(); iter != uvas_persona.end(); ++iter) {
			int pers = uvas[iter->first] / iter->second;
			if (pers < min_invitados) min_invitados = pers;
		}
		cout << min_invitados << '\n';
		cin >> anyo;
	}

	return 0;
}