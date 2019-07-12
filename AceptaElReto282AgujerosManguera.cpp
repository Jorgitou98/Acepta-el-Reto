#include <iostream>
using namespace std;
bool resuelveCaso() {
	int n;
	cin >> n;
		if (!std::cin) // fin de la entrada
			return false;
	int l;
	cin >> l;
	int elem1, elem2;
	int parches = 1;
	cin >> elem1;
	for (int i = 1; i < n; ++i) {
		cin >> elem2;
		if ((elem2 - elem1) > l) {
			parches++;
			elem1 = elem2;
		}
	}
	cout << parches << '\n';
		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
