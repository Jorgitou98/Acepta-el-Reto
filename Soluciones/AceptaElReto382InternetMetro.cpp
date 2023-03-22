#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int numcasos;
    cin >> numcasos;
    for (int i = 0; i < numcasos; ++i) {
        int longitud, antenas;
        cin >> longitud >> antenas;
        int pos, radio;
        int fin = 0;
        for (int j = 0; j < antenas; ++j) {
            cin >> pos >> radio;
            if (pos - radio <= fin) fin = max(fin,pos + radio);
        }
        if(fin >= longitud) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}