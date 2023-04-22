#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; ++i) {
		string palabra;
		list<string> escrito;
		list<string> guardado;
		cin >> palabra;
		while (palabra != ".") {
			if (palabra == "<") {
				if (!escrito.empty()) {
					guardado.push_front(escrito.back());
					escrito.pop_back();
				}
			}
			else if (palabra == ">") {
				if (guardado.empty()) {
					if (!escrito.empty()) {
						escrito.push_back(escrito.back());
					}
				}
				else {
					escrito.push_back(guardado.front());
					guardado.pop_front();
				}
			}
			else {
				escrito.push_back(palabra);
				guardado.clear();
			}
			cin >> palabra;
		}

		if (escrito.empty()) {
			cout << '\n';
			continue;
		}
		else if (escrito.size() == 1) {
			cout << escrito.front() << '\n';
			continue;
		}
		auto ultimo = escrito.end();
		ultimo--;
		for (auto it = escrito.begin(); it != ultimo; it++) {
			cout << *it << ' ';
		}
		cout << *ultimo << '\n';
	}
}