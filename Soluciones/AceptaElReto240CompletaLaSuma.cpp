#include <iostream>
#include <string>
using namespace std;

int pos_incognita(string const& cad) {
	for (int i = 0; i < cad.length(); ++i) {
		if (cad[i] == '-') return i;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	string sum_1, sum_2, res;
	while (cin >> sum_1 >> sum_2 >> res) {
		int incog_1 = pos_incognita(sum_1);
		int incog_2 = pos_incognita(sum_2);
		int incog_res = pos_incognita(res);
		int ini_1 = 0;
		int ini_2 = 0;
		int ini_res = 0;
		if (incog_1 == 0 && sum_1.length() > 1) ini_1 = 1;
		if (incog_2 == 0 && sum_2.length() > 1) ini_2 = 1;
		if (incog_res == 0 && res.length() > 1) ini_res = 1;
		sum_1[incog_1] = '0';
		sum_2[incog_2] = '0';
		res[incog_res] = '0';

		int sum_1_base = stoi(sum_1);
		int sum_2_base = stoi(sum_2);
		int res_base = stoi(res);

		int pot10[10] = { 1, 10, 100, 1000, 10000,
		100000, 1000000, 10000000, 100000000, 1000000000
		};
		int pot_10_sum_1 = pot10[sum_1.length() - 1 - incog_1];
		int pot_10_sum_2 = pot10[sum_2.length() - 1 - incog_2];
		int pot_10_res = pot10[res.length() - 1 - incog_res];

		int num_sols = 0;
		int sol_1, sol_2, sol_res;
		for (int c_1 = ini_1; c_1 <= 9; c_1++) {
			int pos_1 = sum_1_base + c_1 * pot_10_sum_1;
			for (int c_2 = ini_2; c_2 <= 9; c_2++) {
				int pos_2 = sum_2_base + c_2 * pot_10_sum_2;
				for (int c_res = ini_res; c_res <= 9; c_res++) {
					int pos_res = res_base + c_res * pot_10_res;
					if (pos_1 + pos_2 == pos_res) {
						sol_1 = pos_1;
						sol_2 = pos_2;
						sol_res = pos_res;
						num_sols++;
					}
					if (num_sols > 1) break;
				}
			}
		}
		if (num_sols > 1) cout << "VARIAS\n";
		else if (num_sols == 1) cout << sol_1 << ' ' << sol_2 << ' ' << sol_res << '\n';
		else cout << "IMPOSIBLE\n";
	}
}