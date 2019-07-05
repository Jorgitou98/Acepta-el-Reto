#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
	vector <int> v1, v2;
	int valor;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		v1.push_back(valor);
	}
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		v2.push_back(valor);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int suma = 0;
	for (int i = 0; i < n; ++i) {
		suma += abs(v2[i] - v1[i]);
	}
	cout << suma << '\n';
		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
