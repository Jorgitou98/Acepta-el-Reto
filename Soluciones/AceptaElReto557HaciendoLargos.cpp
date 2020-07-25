#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void resuelveCaso() {
	long long int N, T, M, D, I;
	cin >> N >> T >> M >> D >> I;
	long long int tLargos = N*T;
	long long int descansos = ceil(double(N) / double(M)) - 1;
	long long int tDescansos = descansos * (D + D + (descansos - 1) *I) / 2;
	cout << tLargos + tDescansos << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
