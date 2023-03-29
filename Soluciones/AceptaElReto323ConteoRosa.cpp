#include <iostream>
#include <string>
using namespace std;


int main() {
	int p1, p2;

	cin >> p1 >> p2;
	while (p1 != 0 || p2 != 0) {
		int total_digitos = 0;
		int act = p1;
		int dig_act = to_string(p1).length();
		int sig = 1;
		for (int i = 0; i < dig_act; ++i)
			sig *= 10;

		while (sig <= p2) {
			total_digitos += dig_act * (sig - act);
			act = sig;
			sig *= 10;
			dig_act++;
		}
		total_digitos += dig_act * (p2 + 1 - act);
		int mitad = total_digitos/2;

		int total_adso = 0;
		act = p1;
		dig_act = to_string(p1).length();
		sig = 1;
		for (int i = 0; i < dig_act; ++i)
			sig *= 10;
		while ((total_adso + dig_act * (sig - act)) <= mitad) {
			total_adso += dig_act * (sig - act);
			act = sig;
			sig *= 10;
			dig_act++;
		}
		int k = (mitad - total_adso) / dig_act;
		act += k;

		cout << act - 1 << '\n';

		cin >> p1 >> p2;
	}



	return 0;
}