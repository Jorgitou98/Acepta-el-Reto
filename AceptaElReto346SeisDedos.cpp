//Jorge Villarrubia Elvira
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int polidactilia(vector<int> &v, int A) {
	int max = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		while (abs(v[i] - v[v.size() - 1]) >= A) v.pop_back();
		if ((v.size() - i) > max) max = (v.size() - i);
	}
	return max;
  }

bool resuelveCaso() {
	int N, A, valor;
	vector<int> v;

	cin >> N;

	if (N == 0)
		return false;

	cin >> A;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	cout << polidactilia(v, A) << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}
