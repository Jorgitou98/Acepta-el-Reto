#include <iostream>
#include <vector>
using namespace std;



int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n != 0) {
        int numero;
        vector<int> apariciones(10, 0);
        for (int i = 0; i < n; ++i) {
            cin >> numero;
            apariciones[numero % 10]++;
        }
        bool varios = false;
        int maximo = 0, aparicionesMaximo = apariciones[0];
        for (int i = 1; i < 10; ++i) {
            if (apariciones[i] == aparicionesMaximo) varios = true;
            else if (apariciones[i] > aparicionesMaximo) {
                aparicionesMaximo = apariciones[i];
                maximo = i;
                varios = false;
            }
        }
        if (varios) cout << "VARIAS\n";
        else cout << maximo << '\n';

        cin >> n;
    }

    return 0;
}