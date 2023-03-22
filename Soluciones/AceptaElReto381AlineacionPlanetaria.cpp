#include <iostream>
using namespace std;

int mcd(int a, int b) {
    if (a == 0) return b;
    else return mcd(b % a, a);
}

int mcm(int a, int b) {
    return a * b / mcd(a, b);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n != 0) {
        int valor;
        cin >> valor;
        int comunMultiplo = valor;
        for (int i = 1; i < n; ++i) {
            cin >> valor;
            comunMultiplo = mcm(valor, comunMultiplo);
        }
        cout << comunMultiplo << '\n';
        cin >> n;
    }

    return 0;
}