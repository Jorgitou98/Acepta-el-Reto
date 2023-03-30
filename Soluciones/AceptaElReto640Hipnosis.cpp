#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string base_9(int n) {
	string num_base_9;
	while (n != 0) {
		num_base_9.push_back(n % 9 + 48);
		n /= 9;
	}
	reverse(num_base_9.begin(), num_base_9.end());
	return num_base_9;
}


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, d;
	cin >> n >> d;
	while (n != 0 || d != 0) {
		string num_base9 = base_9(n);
		for (int i = 0; i < num_base9.length(); ++i) {
			if (num_base9[i] >= 48 + d) num_base9[i]++;
		}
		cout << num_base9 << '\n';
		cin >> n >> d;
	}



	return 0;
}
