#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; ++i) {
		int comp, no_comp;
		cin >> comp >> no_comp;
		int mitad = (comp + no_comp) / 2;
		comp -= mitad;
		cout << ((long long int)comp * 100)/ mitad << '\n';

	}
	return 0;
}