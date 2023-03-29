#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct cordel {
	int longitud;
	int coste;
};

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, l;
	while (cin >> n >> l) {
		vector<cordel> cordeles(n);
		for (int i = 0; i < n; ++i)
			cin >> cordeles[i].longitud >> cordeles[i].coste;

		vector<long long int> formas_dif(l + 1, 0);
		vector<long long int> min_cordeles(l + 1, LLONG_MAX);
		vector<long long int> min_coste(l + 1, LLONG_MAX);

		formas_dif[0] = 1;
		min_cordeles[0] = 0;
		min_coste[0] = 0;

		for (int i = 0; i < n; ++i)
			for (int j = l; j >= cordeles[i].longitud; --j) {
				formas_dif[j] += formas_dif[j - cordeles[i].longitud];
				if (min_cordeles[j - cordeles[i].longitud] < LLONG_MAX) {
					min_cordeles[j] = min(min_cordeles[j], min_cordeles[j - cordeles[i].longitud] + 1);
					min_coste[j] = min(min_coste[j], min_coste[j - cordeles[i].longitud] + cordeles[i].coste);
				}
			}

		if (formas_dif[l] == 0) cout << "NO\n";
		else cout << "SI" << ' ' << formas_dif[l] << ' ' << min_cordeles[l] << ' ' << min_coste[l] << '\n';
	}

	return 0;
}