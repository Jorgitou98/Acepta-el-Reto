#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	long long int f;
	long long int b;
	cin >> f >> b;
	while (f != 0 || b != 0) {
		long long int total = f * (f + 1) / 2;
		long long int tirados = (f - b + 1) * (f - b + 2) / 2;
		cout << total - tirados << '\n';
		cin >> f >> b;
	}
	return 0;
}