#include <iostream>
#include <vector>
using namespace std;


bool posible(int act, int num_op, int objetivo, vector<int> const& cifras) {
	if (num_op == 4) {
		if (act + cifras[4] == objetivo) return true;
		if (act - cifras[4] == objetivo) return true;
		if (act * cifras[4] == objetivo) return true;
		if (cifras[4] != 0 && act % cifras[4] == 0 && act / cifras[4] == objetivo) return true;
		return false;
	}
	else if (posible(act + cifras[num_op], num_op + 1, objetivo, cifras)) return true;
	else if (posible(act - cifras[num_op], num_op + 1, objetivo, cifras)) return true;
	else if (posible(act * cifras[num_op], num_op + 1, objetivo, cifras)) return true;
	else if (cifras[num_op] != 0 && act % cifras[num_op] == 0 && posible(act / cifras[num_op], num_op + 1, objetivo, cifras)) return true;
	return false;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int objetivo;
	while (cin >> objetivo) {
		vector<int> cifras(5);
		for (int i = 0; i < 5; ++i)
			cin >> cifras[i];

		if (posible(cifras[0], 1, objetivo, cifras)) cout << "SI\n";
		else cout << "NO\n";
	}

	return 0;
}