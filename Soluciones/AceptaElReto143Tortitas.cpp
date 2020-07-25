#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void haceGiro(int numGiradas, stack <int> &pilaTortitas){
	vector <int> aux;
	for (int i = 0; i < numGiradas; ++i){
		aux.push_back(pilaTortitas.top());
		pilaTortitas.pop();
	}
	for (int i = 0; i < aux.size(); ++i){
		pilaTortitas.push(aux[i]);
	}
}



bool resuelveCaso() {
	string cad;
	int tamano, volteos, numGiradas;
	cin >> tamano;
	stack <int> pilaTortitas = stack <int>();
	while (tamano != -1){
		pilaTortitas.push(tamano);
		cin >> tamano;
	}
	cin >> volteos;
	if (pilaTortitas.size() == 0)
		return false;
	for (int i = 0; i < volteos; ++i){
		cin >> numGiradas;
		haceGiro(numGiradas, pilaTortitas);
	}
	cout << pilaTortitas.top() << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
