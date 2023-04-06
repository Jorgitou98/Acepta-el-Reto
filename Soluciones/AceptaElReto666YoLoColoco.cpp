#include <iostream>
#include <stdio.h>
using namespace std;


int main() {
	int num_casos;
	cin >> num_casos;
	getchar();
	for (int i = 0; i < num_casos; ++i) {
		string frase1, frase2;
		char car;
		car = getchar();
		while (car != '\n') {
			if (car >= 'A' && car <= 'Z') {
				frase1.push_back(car + 32);
			}
			else if (car >= 'a' && car <= 'z') {
				frase1.push_back(car);
			}
			car = getchar();
		}

		car = getchar();
		while (car != '\n') {
			if (car >= 'A' && car <= 'Z') {
				frase2.push_back(car + 32);
			}
			else if (car >= 'a' && car <= 'z') {
				frase2.push_back(car);
			}
			car = getchar();
		}

		if (frase1 == frase2) cout << "SI\n";
		else cout << "NO\n";

	}



	return 0;
}
