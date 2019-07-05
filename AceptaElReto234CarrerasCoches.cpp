#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

void resuelveCaso() {
	int pilas, voltaje;
	deque<int> colaDoble;
	int volt;
	cin >> pilas >> voltaje;
	for (int i = 0; i < pilas; ++i) {
		cin >> volt;
		colaDoble.push_back(volt);
	}
	sort(colaDoble.begin(), colaDoble.end());
	int coches = 0;
	while (colaDoble.size() > 1) {
		if (colaDoble.front() + colaDoble.back() >= voltaje) {
			coches++;
			colaDoble.pop_front();
			colaDoble.pop_back();
		}
		else colaDoble.pop_front();
	}
	cout << coches << '\n';

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
