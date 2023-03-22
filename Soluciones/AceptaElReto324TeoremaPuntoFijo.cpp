#include <iostream>
#include <vector>
using namespace std;


// Recursive function to return gcd of a and b
int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// Function to return LCM of two numbers
int lcm(int a, int b){
	return (a / gcd(a, b)) * b;
}


int vuelvePosicionOriginal(int pos, vector<int> const& cambio) {
	int posActual = cambio[pos-1];
	int pasos = 1;
	while (posActual != pos) {
		posActual = cambio[posActual-1];
		pasos++;
	}
	return pasos;
}

int main() {
	int numParticulas;
	cin >> numParticulas;
	while (numParticulas != 0) {
		vector<int> cambio(numParticulas);
		for (int i = 0; i < numParticulas; i++) cin >> cambio[i];
		int mcms = vuelvePosicionOriginal(1, cambio);
		for (int i = 1; i < numParticulas; i++) mcms = lcm(mcms, vuelvePosicionOriginal(i+1, cambio));
		cout << mcms << '\n';

	cin >> numParticulas;
	}
	return 0;
}