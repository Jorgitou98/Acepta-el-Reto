#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while (cin >> n) {
		vector<int> cajas(n);
		for (int i = 0; i < n; i++) {
			cin >> cajas[i];
		}
		sort(cajas.begin(), cajas.end());
		priority_queue<int, vector<int>, greater<int>> pq;
		int num_pilas = 0;
		for (int caja: cajas){
			if (!pq.empty() && pq.top() <= caja) {
				// La apilo debajo de esa pila
				int cima = pq.top();
				pq.pop();
				pq.push(cima + 1);
			}
			// Abro una nueva pila
			else {
				pq.push(1);
				num_pilas++;
			}
		}
		cout << num_pilas << '\n';
	}

}