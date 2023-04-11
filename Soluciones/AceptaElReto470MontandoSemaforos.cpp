#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	string bombillas;
	while (cin >> bombillas) {
		int cont_sem = 0;
		stack<char> pila;
		for (char car : bombillas) {
			if (car == 'V' && !pila.empty()) {
				if (pila.top() == 'A') {
					pila.pop();
					if (!pila.empty() && pila.top() == 'R') {
						pila.pop();
						cont_sem++;
					}
					else {
						pila.push('A');
						pila.push('V');
					}
				}
				else pila.push('V');
			}
			else pila.push(car);
		}

		cout << cont_sem << '\n';
	}
	return 0;
}
