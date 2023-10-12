#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

bool comp(pair<string, int> const& p1, pair<string, int> const& p2) {
	return (p1.second > p2.second || p1.second == p2.second && p1.first < p2.first);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_series;
	cin >> num_series;
	cin.get();
	while (num_series != 0) {
		unordered_map<string, int> series_map;
		for (int i = 0; i < num_series; ++i) {
			int mins;
			cin >> mins;
			cin.get();
			string serie;
			getline(cin, serie);
			if (series_map.count(serie)) series_map[serie] += mins;
			else series_map[serie] = mins;
		}
		vector<pair<string, int>> series_vect(series_map.begin(), series_map.end());
		sort(series_vect.begin(), series_vect.end(), comp);
		int i = 0;
		while (i < series_vect.size() && i < 3) {
			if (series_vect[i].second < 30) break;
			cout << series_vect[i].first << '\n';

			i++;
		}
		cout << "---\n";

		cin >> num_series;
		cin.get();
	}

	return 0;
}