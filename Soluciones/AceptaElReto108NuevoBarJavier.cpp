#include <iostream>
#include <unordered_map>
#include <float.h>
using namespace std;


string cadena_categoria(char categoria) {
	if (categoria == 'D') return "DESAYUNOS";
	else if (categoria == 'A') return "COMIDAS";
	else if (categoria == 'M') return "MERIENDAS";
	else if (categoria == 'I') return "CENAS";
	else if (categoria == 'C') return "COPAS";
}

string categoria_maximo(unordered_map<char, double>& ventas) {
	string respuesta = "EMPATE";
	double maximo = -DBL_MAX;
	bool empate = true;
	for (auto const& pareja : ventas) {
		if (pareja.second > maximo) {
			maximo = pareja.second;
			respuesta = cadena_categoria(pareja.first);
			empate = false;
		}
		else if (pareja.second == maximo)
			empate = true;
	}
	if (empate) return "EMPATE";
	return respuesta;
}

string categoria_minimo(unordered_map<char, double>& ventas) {
	string respuesta = "EMPATE";
	double minimo = DBL_MAX;
	bool empate = true;
	for (auto const& pareja : ventas) {
		if (pareja.second < minimo) {
			minimo = pareja.second;
			respuesta = cadena_categoria(pareja.first);
			empate = false;
		}
		else if (pareja.second == minimo)
			empate = true;
	}
	if (empate) return "EMPATE";
	return respuesta;
}

int main() {
	unordered_map<char, double> ventas = { {'D', 0}, {'A', 0}, {'M', 0},
										  {'I', 0}, {'C', 0} };
	double total = 0;
	int num_ventas_a = 0, num_ventas = 0;
	char categoria;
	double valor;
	while (cin >> categoria >> valor) {


		if (categoria == 'N' && valor == 0) {
			cout << categoria_maximo(ventas);
			cout << '#';
			cout << categoria_minimo(ventas);
			cout << '#';
			if (ventas['A'] / num_ventas_a > (total / num_ventas)) cout << "SI\n";
			else cout << "NO\n";
			ventas = { {'D', 0}, {'A', 0}, {'M', 0},
										  {'I', 0}, {'C', 0} };
			total = 0;
			num_ventas = 0;
			num_ventas_a = 0;
		}
		else {
			ventas[categoria] += valor;
			if (categoria == 'A')
				num_ventas_a++;
			total += valor;
			num_ventas++;
		}
	}

	return 0;
}