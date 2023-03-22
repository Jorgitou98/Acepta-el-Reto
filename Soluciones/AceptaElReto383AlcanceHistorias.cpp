#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int numcasos;
    cin >> numcasos;
    for (int i = 0; i < numcasos; ++i) {
        int paginas;
        cin >> paginas;
        int valor;
        cin >> valor;
        int maximo = valor, maxSalto = -299999;
        for (int j = 1; j < paginas; ++j) {
            cin >> valor;
            maxSalto = max(maxSalto, maximo - valor);
            maximo = max(maximo, valor);
        }
        cout << maxSalto << '\n';
    }

    return 0;
}