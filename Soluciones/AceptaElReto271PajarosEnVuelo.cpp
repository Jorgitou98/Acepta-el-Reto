#include <iostream>
#include <queue>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int mediano, num_parejas;
	cin >> mediano >> num_parejas;
	while (mediano != 0 || num_parejas != 0) {
		int edad1, edad2;
		priority_queue<int> menores;
		priority_queue<int, vector<int>, greater<int>> mayores;
		for (int i = 0; i < num_parejas; ++i) {
			cin >> edad1 >> edad2;
			if (edad1 <= mediano && mediano <= edad2) {
				menores.push(edad1);
				mayores.push(edad2);
			}
			else if (edad2 <= mediano && mediano <= edad1) {
				menores.push(edad2);
				mayores.push(edad1);
			}
			else if (edad1 < mediano && edad2 < mediano) {
				menores.push(edad1);
				menores.push(edad2);
				mayores.push(mediano);
				mediano = menores.top();
				menores.pop();
			}
			else if (edad1 > mediano && edad2 > mediano) {
				mayores.push(edad1);
				mayores.push(edad2);
				menores.push(mediano);
				mediano = mayores.top();
				mayores.pop();
			}
			cout << mediano;
			if (i == num_parejas - 1) cout << '\n';
			else cout << ' ';
		}




		cin >> mediano >> num_parejas;
	}

	return 0;
}