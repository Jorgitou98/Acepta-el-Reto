#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		int num_aristas = 0;
		int origen, destino;
		cin >> origen >> destino;
		while (origen != 0 || destino != 0) {
			num_aristas++;
			cin >> origen >> destino;
		}

		cout << num_aristas - (n - 1) << '\n';
		cin >> n;
	}



	return 0;
}