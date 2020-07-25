#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
bool resuelveCaso() {
	int C, F, n;
	std::cin >> C >> F >> n;
	if (C == 0 && F == 0 && n == 0)
		return false;
	int v1, v2;
	std::vector <std::pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		std::cin >> v1 >> v2;
		v.push_back({ v1, v2 });
	}
	int min = 0;
	int fin = C;
	sort(v.begin(), v.end());
	bool imposible = false, salir = false;
	std::stack <std::pair<int, int>> pila;
	int i = 0;
	while (i < n & !imposible && !salir) {
		if (v[i].first > fin && !pila.empty()) {
			if (pila.top().first <= fin) {
				min++;
				fin = pila.top().second;
				pila.pop();
			}
			else imposible = true;
		}
		if (fin >= F) salir = true;
		if (v[i].first <= fin && !salir) {
			if (pila.empty() || v[i].second >= pila.top().second) pila.push(v[i]);
		}
		++i;
	}

	if (!pila.empty() && !salir) {
		if (pila.top().first <= fin) {
			min++;
			fin = pila.top().second;
			pila.pop();
		}
		else imposible = true;
	}

	if (fin < F) imposible = true;

	if (imposible) std::cout << "Imposible\n";
	else std::cout << min << '\n';
	return true;
}
int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
