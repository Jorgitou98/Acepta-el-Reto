#include <iostream>
#include <vector>
#include <set>
using namespace std;


set<int> posMaximos(vector<int> const& v) {
	set<int> posMaximos = {0};
	int maximo = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] == maximo) posMaximos.insert(i);
		else if (v[i] > maximo) {
			maximo = v[i];
			posMaximos.clear();
			posMaximos.insert(i);
		}
	}
	return posMaximos;
}

set<int> posMinimos(vector<int> const& v) {
	set<int> posMinimos = { 0 };
	int minimo = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] == minimo) posMinimos.insert(i);
		else if (v[i] < minimo) {
			minimo = v[i];
			posMinimos.clear();
			posMinimos.insert(i);
		}
	}
	return posMinimos;
}

vector<int> columna(vector<vector<int>> const& m, int j) {
	vector<int> col(m.size());
	for (int i = 0; i < m.size(); ++i) {
		col[i] = m[i][j];
	}
	return col;
}

int main() {
	int f, c;
	cin >> f >> c;
	while (f != 0 || c != 0) {
		//cin.sync_with_stdio(false);
		//cin.tie(nullptr);
		vector<vector<int>> m(f, vector<int>(c));
		vector<set<int>> colsMax(f);
		vector<set<int>> colsMin(f);
		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> m[i][j];
			}
			colsMax[i] = posMaximos(m[i]);
			colsMin[i] = posMinimos(m[i]);
		}
		bool puntoSilla = false;
		for (int j = 0; j < c && !puntoSilla; ++j) {
			vector<int> col = columna(m, j);
			for (int filaMin : posMinimos(col)) {
				if (colsMax[filaMin].count(j)) {
					puntoSilla = true;
					break;
				}
			}	
			for (int filaMax : posMaximos(col)) {
				if (colsMin[filaMax].count(j)) {
					puntoSilla = true;
					break;
				}
			}
		}
		if (puntoSilla) cout << "SI\n";
		else cout << "NO\n";
		cin >> f >> c;
	}

	return 0;
}