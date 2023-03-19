#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		vector<int> hechizos(n);
		long long int suma = 0;
		for (int i = 0; i < n; ++i) {
			cin >> hechizos[i];
			suma += hechizos[i];
		}
		long long int dano;
		cin >> dano;

		int obj = suma - dano;
		int i = 0, j = n-1;
		int hech_1 = 0, hech_2 = 0;
		while (i < j) {
			if (hechizos[i] + hechizos[j] > obj) j--;
			else if (hechizos[i] + hechizos[j] < obj) i++;
			else {
				hech_1 = hechizos[i];
				hech_2 = hechizos[j];
				break;
			}
		}
		cout << hech_1 << ' ' << hech_2 << '\n';
		cin >> n;
	}

	return 0;
}