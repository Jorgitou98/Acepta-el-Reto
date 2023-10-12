#include <iostream>
#include <math.h>
using namespace std;


long long int movements(int moves, int k) {
	long long int k_move = pow(2, k - 1) + pow(2, k) * (moves - 1);
	return k_move;
}



int main() {
	int k, n;
	cin >> k >> n;
	while (k != 0 || n != 0) {
		cout << k << ' ' << n << ' ';

		long long int k_move = movements(k, k);
		long long int total_moves = pow(2, n) - 1;
		if (k_move <= total_moves) cout << k_move << ' ';
		else cout << "-1 ";

		long long int dif = total_moves - pow(2, k) * k - pow(2, k - 1);
		if (dif >= 0) {
			int moves = (dif / (long long int) pow(2, k)) + 1;
			cout << movements(moves, k) << '\n';
		}
		else cout << "-1\n";

		cin >> k >> n;
	}


	return 0;
}