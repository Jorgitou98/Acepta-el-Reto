// Jorge Villarrubia Elvira
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool poliDivisible(long long int num, int tamano){
	bool poli;
	if (tamano == 1) poli = true;
	else if (num % tamano == 0) poli = poliDivisible(num / 10, tamano -1);
	else poli = false;
	return poli;
}

bool resuelveCaso() {
	long long int num;
	cin >> num;
	string numero;
	numero = to_string(num);
	if (!std::cin)
		return false;
	bool poli = poliDivisible(num, numero.size());
	if (poli) cout << "POLIDIVISIBLE\n";
	else cout << "NO POLIDIVISIBLE\n";
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
