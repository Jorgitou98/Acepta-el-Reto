#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;



int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n != 0) {
        vector<pair<int,int>> posiciones(n);
        for (int i = 0; i < n; ++i) {
            cin >> posiciones[i].first >> posiciones[i].second;
        }
        int maximo = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int distancia = abs(posiciones[i].first - posiciones[j].first) + abs(posiciones[i].second - posiciones[j].second);
                maximo = max(maximo, distancia);
            }
        }
        cout << maximo << '\n';

        cin >> n;
    }

    return 0;
}