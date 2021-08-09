#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	vector<int> manerasSumar(10001, 0);
	// Solo con un número
	for (int i = 1; i <= 10; ++i) manerasSumar[i] = 1;
	// Con mas de un numero
	for (int i = 3; i < 10001; ++i) {
		for (int j = 2; j <= 11; j++) {
			int k = i - j;
			if (k <= 0) break;
			manerasSumar[i] = ((manerasSumar[i] % 1000000007) + (manerasSumar[k] % 1000000007)) % 1000000007;
		}
	}
	int numcasos;
	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		int n; 
		cin >> n;
		cout << manerasSumar[n] << '\n';
	}


	return 0;
}