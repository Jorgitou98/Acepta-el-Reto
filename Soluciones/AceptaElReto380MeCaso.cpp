#include <iostream>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n != 0) {
        int suma = 0, valor;
        for (int i = 0; i < n; ++i) {
            cin >> valor;
            suma += valor;
        }
        cout << suma << '\n';
        cin >> n;
    }

    return 0;
}