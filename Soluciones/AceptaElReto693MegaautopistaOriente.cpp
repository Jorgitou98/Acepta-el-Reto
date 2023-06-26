#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	while (cin >> n >> k) {
		vector<int> pos(n);
		for (int i = 0; i < n; ++i) {
			cin >> pos[i];
		}
		vector<int> beneficios(n);
		for (int i = 0; i < n; ++i) {
			cin >> beneficios[i];
		}
		vector<int> anteriorPos(n, -1);
		int anteriorDescansoPos = -1;
		for (int descansoAct = 1; descansoAct < n; descansoAct++) {
			while ((pos[descansoAct] - pos[anteriorDescansoPos + 1]) >= k) anteriorDescansoPos++;
			anteriorPos[descansoAct] = anteriorDescansoPos;
		}
		vector<int> maxBeneficio(n+1);
		maxBeneficio[0] = 0;
		for (int i = 0; i < n; ++i) {
			maxBeneficio[i+1] = max(maxBeneficio[anteriorPos[i] + 1] + beneficios[i], maxBeneficio[i]);
		}

		cout << maxBeneficio[n] << '\n';

	}




	return 0;
}
