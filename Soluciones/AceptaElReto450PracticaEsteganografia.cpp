#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int r, n;
	while (cin >> r >> n) {
		unordered_map <int, int> pos_clave;
		int num_clave;
		for (int i = 0; i < r; ++i) {
			cin >> num_clave;
			pos_clave[num_clave] = i;
		}
		vector<int> ini_ultima_hasta_indice(r, n);
		int num_msg;
		int min_dist = n;
		for (int i = 0; i < n; ++i) {
			cin >> num_msg;
			auto it = pos_clave.find(num_msg);
			if (it != pos_clave.end()) {
				if (it->second == 0) {
					ini_ultima_hasta_indice[0] = i;
				}
				else if (it->second == r - 1) {
					if (ini_ultima_hasta_indice[r - 2] < i && i - ini_ultima_hasta_indice[r - 2] + 1 < min_dist) {
						min_dist = i - ini_ultima_hasta_indice[r - 2] + 1;
					}
				}
				else if (ini_ultima_hasta_indice[it->second - 1] < i) {
					ini_ultima_hasta_indice[it->second] = ini_ultima_hasta_indice[it->second - 1];
				}
			}
		}
		cout << min_dist << '\n';

	}




	return 0;
}