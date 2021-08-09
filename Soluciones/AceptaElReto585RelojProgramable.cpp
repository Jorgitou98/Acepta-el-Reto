#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		double aguja1, aguja2;
		cin >> aguja1 >> aguja2;
		double aguja1Seis = aguja1 / 6;
		double aguja2Trienta = (aguja2 - aguja1Seis / 2) / 30;
		if (aguja1Seis == trunc(aguja1Seis) && aguja2Trienta == trunc(aguja2Trienta)) {
			cout << setfill('0') << setw(2) << (int)aguja2Trienta << ":" << setfill('0') << setw(2) << (int)aguja1Seis << '\n';
			continue;
		}
		double aguja2Seis = aguja2 / 6;
		double aguja1Trienta = (aguja1 - aguja2Seis / 2) / 30;
		if (aguja2Seis == trunc(aguja2Seis) && aguja1Trienta == trunc(aguja1Trienta)) {
			cout << setfill('0') << setw(2) << (int)aguja1Trienta << ":" << setfill('0') << setw(2) << (int)aguja2Seis << '\n';
			continue;
		}
		cout << "ERROR\n";
	}
	
	return 0;
}