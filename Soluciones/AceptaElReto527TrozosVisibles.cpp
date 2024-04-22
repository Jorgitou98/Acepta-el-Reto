#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


int main() {
	int num_casos;
	cin >> num_casos;
	getchar();
	for (int caso = 0; caso < num_casos; caso++) {
		int num_ceros = 0;
		int suma_no_ceros = 0;
		string linea;
		getline(cin, linea);
		for (char car : linea) {
			if (car == '0') num_ceros++;
			else if (car > '0' && car <= '9') suma_no_ceros += (car - '0');
		}
		if (suma_no_ceros == 0) {
			cout << "COMPLETO\n";
			continue;
		}
		if (num_ceros >= 2 && (suma_no_ceros % 9) == 0) cout << "COMPLETO";
		if (num_ceros < 2) {
			for (int i = num_ceros; i < 2; ++i) cout << '0';
		}
		if ((suma_no_ceros % 9) != 0) cout << (9 - (suma_no_ceros % 9));
		cout << '\n';
	}



	return 0;
}