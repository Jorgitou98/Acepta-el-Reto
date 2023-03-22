#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct tGrupo {
    int maxComparte, partituras, posicion;
    tGrupo(int maxComparte, int partituras, int posicion) {
        this->maxComparte = maxComparte;
        this->partituras = partituras;
        this->posicion = posicion;
    }
};

class Compare {
public:
    bool operator()(tGrupo const& grupo1, tGrupo const& grupo2) {
        return grupo1.maxComparte < grupo2.maxComparte;
    }

};


int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int p, n;
    while (cin >> p >> n) {
        vector<int> musicos(n);
        priority_queue<tGrupo, vector<tGrupo>, Compare> cola;
        for (int i = 0; i < n; ++i) {
            cin >> musicos[i];
            cola.push(tGrupo(musicos[i],1,i));
        }
        p -= n;
        while (p > 0) {
            tGrupo valor = cola.top();
            cola.pop();
            int nuevoValorPartituras = valor.partituras + 1;
            if (musicos[valor.posicion] % nuevoValorPartituras == 0) cola.push(tGrupo(musicos[valor.posicion] / nuevoValorPartituras, nuevoValorPartituras, valor.posicion));
            else cola.push(tGrupo(musicos[valor.posicion] / nuevoValorPartituras + 1, nuevoValorPartituras, valor.posicion));
            p--;
        }

        cout << cola.top().maxComparte << '\n';
    }

    return 0;
}