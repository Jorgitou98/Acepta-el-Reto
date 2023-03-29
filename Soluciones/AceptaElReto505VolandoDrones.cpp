#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
	int n, a, b;
	while (cin >> n >> a >> b) {
		priority_queue<int> pilasA, pilasB;

		int duration;
		for (int i = 0; i < a; ++i) {
			cin >> duration;
			pilasA.push(duration);
		}
		for (int i = 0; i < b; ++i) {
			cin >> duration;
			pilasB.push(duration);
		}
		bool primera = true;
		while (!pilasA.empty() && !pilasB.empty()) {
			int drones = 0;
			vector<int> usados_a, usados_b;
			while (drones < n && !pilasA.empty() && !pilasB.empty()) {
				usados_a.push_back(pilasA.top());
				pilasA.pop();
				usados_b.push_back(pilasB.top());
				pilasB.pop();
				drones++;
			}
			int vuela = 0;
			for (int i = 0; i < usados_a.size(); ++i) {
				int uso = min(usados_a[i], usados_b[i]);
				vuela += uso;
				if (usados_a[i] - uso > 0) pilasA.push(usados_a[i] - uso);
				if (usados_b[i] - uso > 0) pilasB.push(usados_b[i] - uso);
			}
			if (!primera) cout << ' ';
			cout << vuela;
			primera = false;
		}
		cout << '\n';

	}

	return 0;
}
