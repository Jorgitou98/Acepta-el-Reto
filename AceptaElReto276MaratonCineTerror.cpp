#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	int horas1, minutos1;
	char aux;
	vector <pair <int, int>> v;
	int v1, v2, dur;
	for (int i = 0; i < n; ++i) {
		cin >> horas1 >> aux >> minutos1 >> dur;
		int mins = horas1 * 60 + minutos1;
		v.push_back({ mins, mins + dur });
	}
	sort(v.begin(), v.end());

	int iInt = v[0].first, fInt = v[0].second;
	int pelis = 1;

	for (int i = 1; i < v.size(); ++i) {
		if (v[i].first < fInt) {
			if (v[i].second < fInt) fInt = v[i].second;
		}
		else if(v[i].first >= fInt + 10) {
			pelis++;
			fInt = v[i].second;
		}
	}
	cout << pelis << '\n';

	return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
