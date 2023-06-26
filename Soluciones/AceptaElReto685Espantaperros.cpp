#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int x_torre, y_torre, x_intruso, y_intruso;
	cin >> x_torre >> y_torre >> x_intruso >> y_intruso;
	while (x_torre != 0 || y_torre != 0 || x_intruso != 0 || y_intruso != 0) {
		if (x_torre == x_intruso || y_torre == y_intruso || (y_intruso - y_torre) == (x_intruso - x_torre) || (y_intruso - y_torre) ==  (x_torre - x_intruso))
			cout << "SI\n";
		else cout << "NO\n";
		cin >> x_torre >> y_torre >> x_intruso >> y_intruso;
	}

	return 0;
}