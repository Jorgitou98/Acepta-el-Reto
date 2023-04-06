#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void overlap(vector<pair<int, int>> const& v){
    int maxOverlap = 0;
    int count = 0;
    vector<pair<int, char> > data;
    for (int i = 0; i < v.size(); i++) {
        data.push_back({ v[i].first, 'y' });
        data.push_back({ v[i].second, 'x' });
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++) {
        if (data[i].second == 'y') count++;
        if (data[i].second == 'x') count--;
        if (count > maxOverlap) maxOverlap = count;
    }
    int lastMaxOverlap = 0;
    int timeMax = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i].second == 'y') {
            count++;
            if (count == maxOverlap) lastMaxOverlap = data[i].first;
        }
        if (data[i].second == 'x') {
            if (count == maxOverlap) timeMax += (data[i].first - lastMaxOverlap);
            count--;
        }
        
    }
    cout << maxOverlap << ' ' << timeMax << '\n';
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    int comensales;
    cin >> comensales;
    while (comensales != 0) {
        vector<pair<int, int>> intervalos(comensales);
        for (int i = 0; i < comensales; ++i) {
            cin >> intervalos[i].first >> intervalos[i].second;
        }
        overlap(intervalos);
        cin >> comensales;
    }



    return 0;
}