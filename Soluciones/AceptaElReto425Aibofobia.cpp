#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	string palabra;
	while (cin >> palabra) {
		int n = palabra.length();
		vector<vector<int>> minParaPalindromo(n, vector<int>(n, 0));
		for (int d = 1; d < n; d++) 
			for (int j = d; j < n; j++) {
				int i = j - d;
				if (palabra[i] == palabra[j]) minParaPalindromo[i][j] = minParaPalindromo[i + 1][j - 1];
				else minParaPalindromo[i][j] = 1 + min(minParaPalindromo[i][j - 1], minParaPalindromo[i+1][j]);
			}
		cout << minParaPalindromo[0][n - 1] << '\n';
	}
	return 0;
}