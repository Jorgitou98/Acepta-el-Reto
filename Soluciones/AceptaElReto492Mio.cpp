#include <iostream>
using namespace std;

long long int mcd(long long int a, long long int b) {
    return b == 0 ? a : mcd(b, a % b);
}

long long int mcm(long long int a, long long int b) {
    return (a / mcd(a, b)) * b;
}

int main() {
    int D, M, N;
    cin >> D >> M >> N;
    while (D != 0 || M != 0 || N != 0) {
        int num_repeticiones = N / mcm(D, M);
        cout << num_repeticiones << '\n';

        cin >> D >> M >> N;
    }

    return 0;
}
