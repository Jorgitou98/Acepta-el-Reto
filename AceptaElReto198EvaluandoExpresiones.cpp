#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <stdexcept>
using namespace std;


int operacion(long long int valor1, long long int valor2, char car){
	if (car == '+') return valor1 + valor2;
	else if (car == '*') return valor1 * valor2;
	else if (car == '-') return valor1 - valor2;
	else if (car == '/'){
		if (valor2 == 0) throw domain_error("ERROR");
		else return valor1 / valor2;
	}
}

long long int operaPila(string linea){
	stack <long long int> pila;
	for (char car : linea){
		if (isdigit(car)){
			pila.push((long long int) car - 48);
		}
		else {
			long long int valor11 = pila.top();
			pila.pop();
			long long int valor12 = pila.top();
			pila.pop();
			long long int resultadoParcial1 = operacion(valor12, valor11, car);
			pila.push(resultadoParcial1);
		}
	}
	return pila.top();
}

long long int operaCola(string linea){
	queue <long long int> cola;
	for (char car : linea){
		if (isdigit(car)){
			cola.push((long long int) car - 48);
		}
		else {
			long long int valor21 = cola.front();
			cola.pop();
			long long int valor22 = cola.front();
			cola.pop();
			long long int resultadoParcial2 = operacion(valor22, valor21, car);
			cola.push(resultadoParcial2);
		}
	}
	return cola.front();
}


bool resuelveCaso() {
	string linea;
	getline(cin, linea);
	if (!std::cin)
		return false;
	long long int resultado1;
	bool primeroError = false;
	try{
		resultado1 = operaPila(linea);
		cout << resultado1;
	}
	catch (domain_error e){
		cout << e.what();
		primeroError = true;
	}
	try{
		int resultado = operaCola(linea);
		if (!primeroError && resultado1 == resultado) cout << " = ";
		else cout << " != ";
		cout << resultado << '\n';
	}
	catch (domain_error e){
		if (primeroError) cout << " = ";
		else cout << " != ";
		cout << e.what() << '\n';
	}

		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
