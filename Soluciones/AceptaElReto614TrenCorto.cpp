#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int t, e;
	cin >> t >> e;
	while (t != 0 || e != 0) {
		vector<int> personas(e);
		for (int i = 0; i < e; ++i) cin >> personas[i];
		int i = 0, j = t - 1;
		int delante = 0, detras = 0;
		long long int valorDelante = 0, valorDetras = 0;
		for (int k = j + 1; k < e; ++k) {
			detras += personas[k];
			valorDetras += (k - j) * personas[k];
		}
		long long int mejor = valorDelante + valorDetras;
		while (j+1 < e) {
			delante += personas[i];
			valorDelante += delante;
			valorDetras -= detras;
			detras -= personas[j+1];
			mejor = min(mejor, valorDelante + valorDetras);
			i++;
			j++;
		}
		cout << mejor << '\n';
		cin >> t >> e;
	}

	return 0;
}