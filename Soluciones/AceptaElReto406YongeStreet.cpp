#include <iostream>
using namespace std;

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	string calle;
	while (cin >> calle) {
		int avanza = 200001;
		for (int i = calle.size() - 1; i >= 0; --i) {
			if (calle[i] == '|') avanza = 0;
			else if (calle[i] == '.') avanza++;
			else {
				if (i + avanza < calle.size()) calle[i + avanza] = calle[i];
				if (avanza > 0) calle[i] = '.';
			}
		}
		int n;
		cin >> n;
		int pos;
		for (int i = 0; i < n - 1; ++i) {
			cin >> pos;
			cout << calle[pos - 1] << ' ';
		}
		cin >> pos;
		cout << calle[pos - 1] << '\n';
	}

	return 0;
}