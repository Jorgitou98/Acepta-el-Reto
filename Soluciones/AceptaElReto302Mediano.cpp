#include <iostream> 
#include <queue>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	while (cin >> n) {
		int valor;
		bool primeraSalida = true;
		priority_queue<int> p1;
		priority_queue<int, vector<int>, greater<int>> p2;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			if (valor == 0) {
				if (p1.empty() && p2.empty()) {
					if (primeraSalida) primeraSalida = false;
					else cout << ' ';
					cout << "ECSA";
				}
				else if ((p1.size() + p2.size()) % 2 == 0) {
					if (primeraSalida) primeraSalida = false;
					else cout << ' ';
					cout << p1.top();
					p1.pop();
				}
				else {
					if (primeraSalida) primeraSalida = false;
					else cout << ' ';
					cout << p2.top();
					p2.pop();
				}
				continue;
			}
			if ((p1.size() + p2.size()) % 2 == 0) {
				if (p2.empty() || valor > p2.top()) p2.push(valor);
				else {
					p1.push(valor);
					p2.push(p1.top());
					p1.pop();
				}
			}
			else {
				if (p1.empty() || valor > p2.top()) {
					p2.push(valor);
					p1.push(p2.top());
					p2.pop();
				}
				else p1.push(valor);
			}
		}
		cout << '\n';
	}

	return 0;
}