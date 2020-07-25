#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool yaEncontrado(vector <int> const& v, int n){
	bool encontrado = false;
	int i = 0;
	while (!encontrado && i < v.size()-1){
		if (v[i] == n) encontrado = true;
		i++;
	}
	return encontrado;
}

int siguienteNumero(int n){
	int sig = 0;
	int cociente = n;
	while (cociente > 0){
		sig += pow((cociente % 10), 3);
		cociente = cociente / 10;
	}
	sig += cociente;
	return sig;
}

bool cubifinito(int n, vector <int> &v){
	v.push_back(n);
	if (n == 1) return true;
	else{
		if (yaEncontrado(v, n)) return false;
		else return cubifinito(siguienteNumero(n), v);
	}
}


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector <int> v;
	bool cubiFinito = cubifinito(n, v);
	for (int i = 0; i < v.size()-1; ++i){
		cout << v[i] << " - ";
	}
	cout << v[v.size() - 1] << " -> ";
	if (cubiFinito) cout << "cubifinito.\n";
	else cout << "no cubifinito.\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
