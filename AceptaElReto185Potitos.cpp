#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ingredientes{
private:
	vector <string> lista;
public:
	ingredientes(){}
	void anadirIngrediente(string ingrediente){
		if (lista.size() == 0) lista.push_back(ingrediente);
		else if (!binary_search(lista.begin(), lista.end(), ingrediente)){
			auto pos = lower_bound(lista.begin(), lista.end(), ingrediente);
			lista.insert(pos, 1, ingrediente);
		}
	}
	bool estaElIngrediente(string ingrediente){
		return binary_search(lista.begin(), lista.end(), ingrediente);
	}
	void eliminarIngrediente(string ingrediente){ // Se asume que el elemento buscado esta. Si no la funcion no hace lo esperado
		auto pos = lower_bound(lista.begin(), lista.end(), ingrediente);
		lista.erase(pos);
	}
	int size(){
		return lista.size();
	}
	string getElemento(int pos){
		return lista[pos];
	}

};
ostream &operator <<(ostream & out, ingredientes lista){
	for (int i = 0; i < lista.size() - 1; ++i){
		out << lista.getElemento(i) << " ";
	}
	if (lista.size() > 0) out << lista.getElemento(lista.size() - 1);
	return out;
}

bool resuelveCaso() {
	int potitos;
	cin >> potitos;
	if (potitos == 0)
		return false;
	string leGusta, ingrediente;
	ingredientes buenos = ingredientes();
	ingredientes malos = ingredientes();
	for (int i = 0; i < potitos; ++i){
		cin >> leGusta;
		cin >> ingrediente;
		if (leGusta == "SI:"){
			while (ingrediente != "FIN"){
				buenos.anadirIngrediente(ingrediente);
				if (malos.estaElIngrediente(ingrediente)) malos.eliminarIngrediente(ingrediente);
				cin >> ingrediente;
			}
		}
		else{
			while (ingrediente != "FIN"){
				if (!buenos.estaElIngrediente(ingrediente))malos.anadirIngrediente(ingrediente);
				cin >> ingrediente;
			}
		}
	}
	cout << malos << '\n';
	
		return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
