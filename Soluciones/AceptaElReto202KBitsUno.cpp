#include <iostream>
#define MOD 1000000007
using namespace std;
int comb[1001][1001];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 1001; ++i) {
        comb[0][i] = 0;
        comb[i][0] = 1;
    }
    for (int i = 1; i < 1001; ++i) {
        for (int j = 1; j <= i; ++j) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }
    int n, k;
    cin >> n >> k;
    while (n != 0 || k != 0) {
        if (n == 0 || n < k) cout << "0\n";
        else cout << comb[n][k] << '\n';
        cin >> n >> k;
    }

    return 0;
}