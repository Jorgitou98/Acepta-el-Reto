#include <iostream>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; ++i) {
		long long int num;
		cin >> num;
		num /= 10;
		if (num != 0) cout << num * (num + 1) << "25\n";
		else cout << "25\n";
	}

}