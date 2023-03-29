#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string termino(int k, int m) {
	int resto = 1;
	string term(m + 1, ' ');
	for (int i = 0; i <= m; ++i) {
		term[i] = resto / k + 48;
		resto = (resto % k) * 10;
	}
	return term;
}



void suma(string & sum1, string const& sum2, int m) {
	int acarreo = 0;
	for (int i = m; i >= 0; --i) {
		int val = (sum1[i] - 48) + (sum2[i] - 48) + acarreo;
		sum1[i] = (val % 10) + 48;
		acarreo = val / 10;
	}
}

void resta(string & res1, string const& res2, int m) {
	int acarreo = 0;
	for (int i = m; i >= 0; --i) {
		int val = (res1[i] - 48) - (res2[i] - 48) - acarreo;
		if (val < 0) {
			val += 10;
			acarreo = 1;
		}
		else acarreo = 0;
		res1[i] = (val) + 48;
	}
}


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		int m;
		cin >> m;
		string acum(m+1, '0');
		for (int i = 0; i < n; i++) {
			int den = 2 * i + 1;
			if(i % 2 == 0) suma(acum, termino(den, m), m);
			else resta(acum, termino(den, m), m);
		}
		cout << acum[0] << '.' << acum.substr(1) << '\n';
		cin >> n;
	}
	return 0;
}