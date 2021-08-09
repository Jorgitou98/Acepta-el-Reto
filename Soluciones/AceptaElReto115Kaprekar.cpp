#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	long long int n;
	cin >> n;
	while (n != 0) {
		string cuadrado = to_string((long long int) n * (long long int) n);
		bool kaprekar = false;
		for (int i = 0; i < cuadrado.size(); ++i) {
			if (i > to_string(n).size()) break;
			string parte1 = cuadrado.substr(0, i);
			string parte2 = cuadrado.substr(i, cuadrado.size()-i); 
			long long int entero1;
			if (parte1 == "") entero1 = 0;
			else entero1 = stoll(parte1);
			long long int entero2 = stoll(parte2);
			if (entero2 == 0) break;
			if (entero1 + entero2 == n) {
				kaprekar = true;
				break;
			}
		}
		if (kaprekar) cout << "SI\n";
		else cout << "NO\n";
		cin >> n;
	}

	return 0;
}