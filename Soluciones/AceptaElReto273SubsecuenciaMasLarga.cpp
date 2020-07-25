#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	std::string cad1, cad2;
	std::cin >> cad1;
	if (!std::cin) // fin de la entrada
		return false;
	std::cin >> cad2;
	std::vector<int> subsecuencia(cad2.size()+1, 0);
	int guardaAnt, maximo;
	for (int i = 0; i < cad1.size(); ++i) {
		guardaAnt = 0;
		for (int j = 1; j < cad2.size() + 1; ++j) {
			if (cad1[i] == cad2[j-1]) maximo = std::max(std::max(subsecuencia[j], subsecuencia[j - 1]), guardaAnt + 1);
			else maximo = std::max(std::max(subsecuencia[j], subsecuencia[j - 1]), guardaAnt);
			guardaAnt = subsecuencia[j];
			subsecuencia[j] = maximo;
		}
	}
	std::cout << subsecuencia[cad2.size()] << '\n';
	return true;
}
int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
