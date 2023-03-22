#include <iostream>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    while (cin >> x >> n) {
        int potencia = 1, suma = 1;
        for (int i = 0; i < n; ++i) {
            potencia = (potencia * x) % 1000007;
            suma = (suma + potencia) % 1000007;
        }
        cout << suma << '\n';
    }
    return 0;
}