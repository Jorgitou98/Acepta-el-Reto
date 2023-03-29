#include <iostream>
#include <vector>
using namespace std;


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m, tiempo;
	while (cin >> n >> m >> tiempo) {
		vector<int> hilera1(n+1, 0);
		vector<int> hilera2(m+1, 0);

		for (int i = n; i > 0; --i)
			cin >> hilera1[i];

		for (int i = m; i > 0; --i)
			cin >> hilera2[i];

		for (int i = 2; i <= n; ++i)
			hilera1[i] += hilera1[i - 1];

		for (int i = 2; i <= m; ++i)
			hilera2[i] += hilera2[i - 1];

		int max_trozos = 0;
		int ind2 = 0;
		for (int ind1 = 0; ind1 <= n; ++ind1) {
			while ((ind2 + 1) <= m && (hilera1[ind1] + hilera2[ind2 + 1]) <= tiempo) ind2++;
			while ((ind2 - 1) >= 0 && (hilera1[ind1] + hilera2[ind2]) > tiempo) ind2--;
			if ((hilera1[ind1] + hilera2[ind2]) > tiempo) break;
			if (max_trozos < (ind1 + ind2)) max_trozos = ind1 + ind2;
		}
		cout << max_trozos << '\n';
	}


	return 0;
}