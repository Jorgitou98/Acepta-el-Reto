#include <iostream>
using namespace std;

void resuelveCaso() {
	bool cero = false, nueve = false;
	float num;
	for (int i = 0; i < 5; ++i) {
		cin >> num;
		if (num == 0.0) cero = true;
		else if (num >= 9.0) nueve = true;
	}

	if (cero && !nueve) {
		cout << "SUSPENSO DIRECTO\n";
	}
	else cout << "MEDIA\n";
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
