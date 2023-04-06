#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; ++i) {
		int n, k;
		cin >> n >> k;
		int dif_min = k + 1;
		vector<long long int> mejoropcion(n + dif_min, 0);
		for (int i = dif_min; i < n + dif_min; ++i) {
			cin >> mejoropcion[i];
		}
		for (int i = dif_min; i < n + dif_min; ++i) {
			mejoropcion[i] = max(mejoropcion[i-1], mejoropcion[i] + mejoropcion[i-dif_min]);
		}
		cout << mejoropcion[n + dif_min - 1] << '\n';
	}



	return 0;
}