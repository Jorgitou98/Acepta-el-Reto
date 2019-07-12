#include <iostream>

bool resuelveCaso() {
	long long int p, n;
	std::cin >> p;
	std::cin >> n;
		if (p <= 0 && n <= 0)
			return false;
	if ((p == 1 || p <= n) && p >= 0 && n >= 0) std::cout << "YES\n";
	else std::cout << "NO\n";
		return true;
}
int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
