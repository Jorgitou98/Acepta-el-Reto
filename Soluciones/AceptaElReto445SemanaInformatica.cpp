#include <iostream>
#include <queue>
#include <vector>
bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin) // fin de la entrada
		return false;
	int v1, v2;
	std::priority_queue <int, std::vector<int>, std::greater<int>> pqIni, pqFin;
	for (int i = 0; i < n; ++i) {
		std::cin >> v1 >> v2;
		pqIni.push(v1);
		pqFin.push(v2);
	}
	int maxAmigos = -1;
	int amigos = -1;
	// Vemos cuantos inis son menores que el fin mas pequeño
	while (!pqIni.empty()) {
		if (pqIni.top() < pqFin.top()) {
			amigos++;
			pqIni.pop();
		}
		else {
			amigos--;
			pqFin.pop();
		}
		if (amigos > maxAmigos) maxAmigos = amigos;
	}

	std::cout << maxAmigos << '\n';
	return true;
}
int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
