#include <iostream>
#include <string>
#include <list>
using namespace std;
bool resuelveCaso() {
	string cad;
	getline(cin, cad);
	if (!std::cin)
		return false;
	list <char> lista;
	auto it = lista.begin(); //Falla?
	for (char c : cad){
		if (c == '-') it = lista.begin();
		else if (c == '+') it = lista.end();
		else if (c == '*') {
			if (it != lista.end()) it++;
		}
		else if (c == '3') {
			if (it != lista.end()) it = lista.erase(it);
		}
		else {
			it = lista.insert(it, c);
			it++;
		}
	}
	for (char c : lista){
		cout << c;
	}
	cout << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
