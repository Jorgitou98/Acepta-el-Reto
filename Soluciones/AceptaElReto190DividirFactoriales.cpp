#include <iostream>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int num, den;
	cin >> num >> den;
	while (num >= den) {
		long long int divFact = 1;
		for (int i = num; i > den; --i) divFact *= i;
		cout << divFact << '\n';
		cin >> num >> den;
	}

	return 0;
}