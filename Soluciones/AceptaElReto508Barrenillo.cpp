#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxIntersecta(vector<pair<int, int> > const &v)
{
	int ans = 0;
	int count = 0;
	vector<pair<int, char> > data;

	for (int i = 0; i < v.size(); i++) {
		data.push_back({ v[i].first, 'x' });
		data.push_back({ v[i].second, 'y' });
	}

	sort(data.begin(), data.end());
	for (int i = 0; i < data.size(); i++) {
		if (data[i].second == 'x')
			count++;
		if (data[i].second == 'y')
			count--;
		ans = max(ans, count);
	}
	return ans;
}


bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;

	vector<pair<int, int> > v(n);
	int x, y;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		v[i].first = x - y;
		v[i].second = x + y;
	}

	cout << maxIntersecta(v) << '\n';
		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}