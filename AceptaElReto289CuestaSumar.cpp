#include <iostream>
#include <functional>
#include <queue>
using namespace std;
bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
		priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
		long long int valor, coste = 0;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			pq.push(valor);
		}
		long long int sum1, sum2, sum;
		while (pq.size() > 1) {
				sum1 = pq.top();
				pq.pop();
				sum2 = pq.top();
				pq.pop();
				sum = sum1 + sum2;
				coste += sum;
				pq.push(sum);
		}
		cout << coste << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
