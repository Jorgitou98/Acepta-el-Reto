#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num_casos;
	cin >> num_casos;
	for (int caso = 0; caso < num_casos; ++caso) {
		int d;
		cin >> d;
		int suma_taxi = 0;
		int d_cuadrado = d * d;
		for (int x = 1; x < d; ++x) {
			double raiz = sqrt(d_cuadrado - x * x);
			if (ceil(raiz) == floor(raiz)) {
				suma_taxi = x + ceil(raiz);
				break;
			}
		}
		cout << suma_taxi << '\n';
	}


	return 0;
}