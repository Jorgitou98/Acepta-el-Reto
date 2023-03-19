#include <iostream>
#include <string>
using namespace std;

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int num_jugadores, rondas;
	string disposicion;
	cin >> num_jugadores >> rondas;
	while (num_jugadores != 0 || rondas != 0) {
		cin >> disposicion;
		int jugados = 0;
		int sig_part = 2;
		int sig_rival = 1;
		for (int i = 0; i < rondas; ++i) {
			for (int j = 0; j < num_jugadores; j += sig_part) {
				if (disposicion[j] == '1' && disposicion[j + sig_rival] == '1') jugados++;
				else if (disposicion[j + sig_rival] == '1') disposicion[j] = '1';
			}
			sig_part *= 2;
			sig_rival *= 2;
		}
		cout << jugados << '\n';
		cin >> num_jugadores >> rondas;
	}

	return 0;
}