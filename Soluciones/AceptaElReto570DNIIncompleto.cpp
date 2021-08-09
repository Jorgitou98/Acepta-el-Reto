#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;


int conversion(char letra) {
	if (letra == 'T') return 0;
	else if (letra == 'R') return 1;
	else if (letra == 'W') return 2;
	else if (letra == 'A') return 3;
	else if (letra == 'G') return 4;
	else if (letra == 'M') return 5;
	else if (letra == 'Y') return 6;
	else if (letra == 'F') return 7;
	else if (letra == 'P') return 8;
	else if (letra == 'D') return 9;
	else if (letra == 'X') return 10;
	else if (letra == 'B') return 11;
	else if (letra == 'N') return 12;
	else if (letra == 'J') return 13;
	else if (letra == 'Z') return 14;
	else if (letra == 'S') return 15;
	else if (letra == 'Q') return 16;
	else if (letra == 'V') return 17;
	else if (letra == 'H') return 18;
	else if (letra == 'L') return 19;
	else if (letra == 'C') return 20;
	else if (letra == 'K') return 21;
	else if (letra == 'E') return 22;
	else return 23;
}

int positiveMod(int n, int m) {
	int mod = n % m;
	if (mod < 0) {
		mod += m;
	}
	return mod;
}

bool DNIPosible(vector<unordered_set<int>> const& modulosPotencias10, char letra, int suma, int pos) {
	return modulosPotencias10[pos].count(positiveMod(conversion(letra) - suma, 23));
}

int numFormas(vector<unordered_set<int>> const& modulosPotencias10, char letra, int incognita, int suma, vector<int> const& posInterrogaciones) {
	if (incognita == posInterrogaciones.size()-1) {
		if (DNIPosible(modulosPotencias10, letra, suma, posInterrogaciones[incognita])) return 1;
		else return 0;
	}
	else {
		int maneras = 0;
		for (char c = '0'; c <= '9'; c++) {
			int sumaNueva = (suma + ((c - '0') * (int)pow(10, 7 - posInterrogaciones[incognita]) % 23)) % 23;
			maneras += numFormas(modulosPotencias10, letra, incognita+1, sumaNueva, posInterrogaciones);
		}
		return maneras;
	}
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	vector<unordered_set<int>> modulosPotencias10(8);
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 10; ++j) {
			modulosPotencias10[7-i].insert((j * (int)pow(10, i)) % 23);
		}
	}
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		string dni;
		cin >> dni;
		int sumaModulosConocidos = 0;
		vector<int> posInterrogaciones;
		for (int i = 0; i < dni.size(); ++i) {
			if (dni[i] == '?') posInterrogaciones.push_back(i);
			else {
				sumaModulosConocidos += ((dni[i] - '0') * (int)pow(10, 7 - i)) % 23;
				sumaModulosConocidos %= 23;
			}
		}
		cout << numFormas(modulosPotencias10, dni[dni.size()-1], 0, sumaModulosConocidos, posInterrogaciones) << '\n';
	}
	return 0;
}