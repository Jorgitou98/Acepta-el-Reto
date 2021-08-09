#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> diferencia(unordered_set<int> const& c1, unordered_set<int> const& c2) {
	vector<int> resultado;
	for (int elem : c1)
		if (!c2.count(elem)) resultado.push_back(elem);
	sort(resultado.begin(), resultado.end());
	return resultado;
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int n, m;
		unordered_set<int> cromosAlejandro, cromosMateo, repetidosAlejandro, repetidosMateo;
		cin >> n;
		int valor;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			if (!cromosAlejandro.count(valor)) cromosAlejandro.insert(valor);
			else repetidosAlejandro.insert(valor);

		}
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> valor;
			if (!cromosMateo.count(valor)) cromosMateo.insert(valor);
			else repetidosMateo.insert(valor);
		}
		vector<int> paraMateo = diferencia(repetidosAlejandro, cromosMateo);
		vector<int> paraAlejandro = diferencia(repetidosMateo, cromosAlejandro);
	
		if (paraMateo.empty()) cout << "Nada que intercambiar\n";
		else {
			for (int i = 0; i < paraMateo.size(); ++i) {
				cout << paraMateo[i];
				if (i < paraMateo.size() - 1) cout << " ";
			}
			cout << '\n';
		}
		if (paraAlejandro.empty()) cout << "Nada que intercambiar\n";
		else {
			for (int i = 0; i < paraAlejandro.size(); ++i) {
				cout << paraAlejandro[i];
				if (i < paraAlejandro.size() - 1) cout << " ";
			}
			cout << '\n';
		}
	}

	return 0;
}