//Jorge Villarrubia Elvira

#include<iostream>
#include<vector>
using namespace std;

int numAbadias(vector <int> const& v);

int numAbadias(vector <int> const& v){
	int abadias = 1, max = v[v.size() -1];
	for (int i = v.size() - 2; i >= 0; --i){
		if (v[i] > max) {
			abadias++;
			max = v[i];
		}
	}
	return abadias;
}

bool resuelveCaso() {
	int montanas;
	cin >> montanas;
	if (montanas == 0)
		return false;
	vector <int> v;
	int valor;
	for (int i = 0; i < montanas; ++i){
		cin >> valor;
		v.push_back(valor);
	}
	int numeroAbadias = numAbadias(v);
	cout << numeroAbadias << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
