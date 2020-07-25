//Jorge Villarrubia Elvira

#include<iostream>
#include<vector>
using namespace std;

long long int numParejitas(vector <int> const& v);

long long int numParejitas(vector <int> const& v){
	long long int parejas = 0;
	if (v.size() != 1){
		long long int suma = v[v.size() - 1];
		for (int i = v.size() - 2; i >= 0; --i){
			parejas = parejas + v[i] * suma;
			suma = suma + v[i];
		}
	}
	return parejas;
}

bool resuelveCaso() {
	int paises;
	cin >> paises;
	if (paises == 0)
		return false;
	vector <int> v;
	int valor;
	for (int i = 0; i < paises; ++i){
		cin >> valor;
		v.push_back(valor);
	}
	long long int numParejas = numParejitas(v);
	cout << numParejas << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
