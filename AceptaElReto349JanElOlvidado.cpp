#include <iostream>

int operar () {
	char valor;
	std::cin >> valor;
	if (isalnum(valor)) return valor - '0';
	else {
		int sum1 = operar();
		int sum2 = operar();
		if (valor == '+') return sum1 + sum2;
		else if (valor =='-') return sum1 - sum2;
		else if (valor == '*') return sum1 * sum2;
		else return sum1 / sum2;
	}
}

void resuelveCaso() {
	std::cout << operar() << '\n';
}
int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
