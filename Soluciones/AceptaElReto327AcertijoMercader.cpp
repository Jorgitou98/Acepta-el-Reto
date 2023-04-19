#include<iostream>
#define INF 1000000001
using namespace std;

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void minNum(long long int num_divisores, long long int act_num, int act_primo, long long int& res, int n) {
    if (num_divisores == n && act_num < res) res = act_num;
    else if (num_divisores >= n) return;

    for (int power = 1;; power++) {
        act_num *= primes[act_primo];

        if (num_divisores * (power + 1) > n || act_num > res)
            break;

        minNum(num_divisores * (power + 1), act_num, act_primo + 1, res, n);
    }
    return;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n != 0) {
        long long int res = INF;
        minNum(1, 1, 0, res, n);
        if (res == INF) cout << "+INF\n";
        else cout << res << '\n';
        cin >> n;
    }

    return 0;
}