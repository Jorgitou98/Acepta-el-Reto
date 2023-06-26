#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int cols, filas;
	cin >> cols >> filas;
	while (cols != 0 || filas != 0) {
		int area = 0;
		char c;
		for (int i = 0; i < filas; ++i) {
			bool par = false;
			for (int j = 0; j < cols; j++) {
				cin >> c;
				if (c == '.') {
					if (par) area++;
				}
				else {
					par = !par;
					if (par) area++;
				}
			}
		}
		cout << area << '\n';
		cin >> cols >> filas;
	}
}