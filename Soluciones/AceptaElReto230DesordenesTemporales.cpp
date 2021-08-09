#include <iostream>
#include <vector>
using namespace std;

long long int MergeSort(vector<int>& v, int ini, int fin) {
	if (ini == fin) return 0;
	int m = (ini + fin) / 2;
	long long int coste = MergeSort(v, ini, m);
	coste += MergeSort(v, m+1, fin);
	int izq = ini, der = m+1, general = ini;
	fin++;
	vector<int> w;
	while (izq != m+1 && der != fin) {
		if (v[izq] <= v[der]) {
			w.push_back(v[izq]);
			izq++;
		}
		else {
			w.push_back(v[der]);
			coste += der - general;
			der++;
		}
		general++;
	}
	while (izq != m+1) {
		w.push_back(v[izq]);
		izq++;
	}
	while (der != fin) {
		w.push_back(v[der]);
		der++;
	}
	general = ini;
	while (general != fin) {
		v[general] = w[general - ini];
		general++;
	}
	fin--;
	return coste;
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		int num;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			cin >> num;
			v.push_back(num);
		}

		int ini = 0;
		n--;
		cout << MergeSort(v, ini, n) << "\n";
		cin >> n;
	}

	return 0;
}