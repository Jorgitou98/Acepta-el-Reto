#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> sums(31);
	sums[0] = 1;
	sums[1] = 2;
	int an = 1;
	int an1 = 1;
	for (int i = 2; i < 31; ++i) {
		int an2 = an1 + 2 * an;
		sums[i] += sums[i-1] + an2;
		an = an1;
		an1 = an2;
	}
	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; ++i){
		int n;
		cin >> n;
		for (int j = 0; j < 31; ++j) {
			if (sums[j] >= n) {
				cout << j+1 << '\n';
				break;
			}
		}
	}
	return 0;
}