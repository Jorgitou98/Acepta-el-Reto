#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	for (int caso = 0; caso < num_casos; ++caso) {
		int n;
		cin >> n;
		int valor;
		unordered_set<long long int> valores;
		long long int suma = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> valor;
				valores.insert(valor);
				suma += valor;
			}
		if ((suma % 2) == 0 && valores.count(suma / 2))
			cout << "SI\n";
		else cout << "NO\n";

	}


	return 0;
}