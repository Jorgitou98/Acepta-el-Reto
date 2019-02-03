#include <iostream>
#include <deque>
#include <string>
using namespace std;

bool esVocal(char c){
	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') return true;
	else return false;
}


bool resuelveCaso() {
	string linea;
	getline(cin, linea);
	if (!std::cin)
		return false;
	deque<char> cola;
	deque<char> aux;
	int i = 0;
	cout << linea << " => ";
	for (char c : linea){
			if (i % 2 == 0) cola.push_back(c);
			else aux.push_back(c);
			i++;
	}
	while (!aux.empty()){
		cola.push_back(aux.back());
		aux.pop_back();
	}
	deque<char> colaFinal;
	while (!cola.empty()){
		if (esVocal(cola.front())){
			while (!aux.empty()){
				colaFinal.push_back(aux.back());
				aux.pop_back();
			}
			colaFinal.push_back(cola.front());
		}
		else{
			aux.push_back(cola.front());
			if (cola.size() == 1) {
				while (!aux.empty()){
					colaFinal.push_back(aux.back());
					aux.pop_back();
				}
			}
		}
		cola.pop_front();
	}

	while (!colaFinal.empty()){
		cout << colaFinal.front();
		colaFinal.pop_front();
	}
	cout << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
