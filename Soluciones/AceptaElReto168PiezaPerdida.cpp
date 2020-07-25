//Jorge Villarrubia Elvira

#include<iostream>
#include<vector>
using namespace std;

int piezaQueFalta(vector <int> const& v, vector <bool> u);

int piezaQueFalta(vector <int> const& v, vector <bool> u){
	int piezaQueNoEsta;
	for (int i = 0; i < v.size(); ++i){
		u[v[i] - 1] = true;
	}
	int j = 0;
	while (j < u.size() && u[j]) j++;
	piezaQueNoEsta = j + 1;
	return piezaQueNoEsta;
}

bool resuelveCaso() {
	int numPiezas;
	cin >> numPiezas;
	if (numPiezas == 0)
		return false;
	vector <int> v;
	vector <bool> u;
	int valor;
	for (int i = 0; i < numPiezas - 1; ++i){
		cin >> valor;
		v.push_back(valor);
		u.push_back(false);
	}
	u.push_back(false); // Tiene que tener uno mas de las piezas que introduzco.
	int piezaAusente = piezaQueFalta(v, u);
	cout << piezaAusente << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
