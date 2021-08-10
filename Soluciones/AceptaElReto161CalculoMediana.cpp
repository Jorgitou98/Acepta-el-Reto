#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		if (n % 2 == 0) {
			cout << v[n / 2 - 1] + v[n / 2];
		}
		else cout << 2* v[n / 2];
		cout << '\n';
		cin >> n;
	}

	return 0;
}
