#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


long long int base9_a_decimal(int a) {
	long long int decimal = 0;
	int potencia = 1;
	while (a != 0) {
		int resto = a % 10;
		if (resto >= 5) resto--;
		decimal += resto * potencia;
		potencia *= 9;
		a /= 10;
	}
	return decimal;
}

string base_9(long long int n) {
	string num_base_9;
	do {
		num_base_9.push_back(n % 9 + 48);
		n /= 9;
	} while (n != 0);
	reverse(num_base_9.begin(), num_base_9.end());
	return num_base_9;
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int a, b;
	while (cin >> a >> b) {
		long long int dec_a = base9_a_decimal(a);
		long long int dec_b = base9_a_decimal(b);

		long long int prod = dec_a * dec_b;

		string rel_base_9 = base_9(prod);

		for (int i = 0; i < rel_base_9.length(); ++i) {
			if (rel_base_9[i] >= 5 + 48) rel_base_9[i]++;
		}
		cout << rel_base_9 << '\n';
	}

	return 0;
}