#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int f, a, c;
	while (cin >> f >> a >> c) {
		priority_queue<int> pq;
		int ocupados;
		for (int i = 0; i < f; ++i) {
			cin >> ocupados;
			pq.push(a - ocupados);
		}

		long long int max_recauda = 0;
		while (c > 0 && !pq.empty()) {
			if (pq.size() == 1) {
				int mejor_fila = pq.top();
				pq.pop();
				int num_terminos = min(c, mejor_fila);
				int min_valor_sum = mejor_fila - num_terminos + 1;
				max_recauda += (((long long int) min_valor_sum + (long long int) mejor_fila) * (long long int) num_terminos) / 2;
				c -= num_terminos;
			}
			else {
				int mejor_fila = pq.top();
				pq.pop();
				int segundo_mejor_fila = pq.top();
				int num_terminos = min(c, mejor_fila - segundo_mejor_fila + 1);
				int min_valor_sum = mejor_fila - num_terminos + 1;
				max_recauda += (((long long int) min_valor_sum + (long long int) mejor_fila) * (long long int) num_terminos) / 2;
				c -= num_terminos;
				if (min_valor_sum > 1) pq.push((min_valor_sum-1));
			}
		}
		cout << max_recauda << '\n';
	}
	return 0;
}