#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		int temp;
		cin >> temp;
		int minimo = temp;
		int maximo = temp;
		int ultimo_min = 0;
		int ultimo_max = 0;
		int min_dist = 0;
		for (int i = 1; i < n; ++i) {
			cin >> temp;
			if (temp == minimo) {
				ultimo_min = i;
				if (ultimo_min - ultimo_max < min_dist)
					min_dist = ultimo_min - ultimo_max;
			}
			if (temp == maximo) {
				ultimo_max = i;
				if (ultimo_max - ultimo_min < min_dist)
					min_dist = ultimo_max - ultimo_min;
			}
			if (temp < minimo) {
				minimo = temp;
				ultimo_min = i;
				min_dist = ultimo_min - ultimo_max;
			}
			if (temp > maximo) {
				maximo = temp;
				ultimo_max = i;
				min_dist = ultimo_max - ultimo_min;
			}

		}

		cout << minimo << ' ' << maximo << ' ' << min_dist << '\n';

		cin >> n;
	}



	return 0;
}