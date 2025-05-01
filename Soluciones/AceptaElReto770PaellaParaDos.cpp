#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct pos {
    int x, y;
};


bool divisible_recta(int tropezon_limite, vector<pos> const& mejillones, vector<pos> const& gambas) {
    int tam;
    // Si el tropezon para trazar la recta es mejillon
    if (tropezon_limite == 0) tam = mejillones.size();
    // Si el tropezon para trazar la recta es gamba
    else tam = gambas.size();

    int i = 0;
    while (i < tam) {
        // Contadores para saber cuantos quedan a cada lado
        int mejillones_lado1 = 0, mejillones_lado2 = 0;
        int gambas_lado1 = 0, gambas_lado2 = 0;

        // Posicion del elemento para trazar la recta
        int x_0, y_0;
        if (tropezon_limite == 0) {
            x_0 = mejillones[i].x;
            y_0 = mejillones[i].y;
        }
        else {
            x_0 = gambas[i].x;
            y_0 = gambas[i].y;
        }

        if (x_0 == 0) { // Recta x = 0
            // Cuento mejillones y gambas en cada lado
            for (auto mejillon : mejillones) {
                if (mejillon.x > 0) mejillones_lado1++;
                else if (mejillon.x < 0) mejillones_lado2++;
            }
            for (auto gamba : gambas) {
                if (gamba.x > 0) gambas_lado1++;
                else if (gamba.x < 0) gambas_lado2++;
            }
        }
        // Otra recta
        else {
            double pend = (double)y_0 / (double)x_0; // Saco la pendiente
            // Cuento mejillones y gambas en cada lado
            for (auto mejillon : mejillones) {
                if ((double)mejillon.y > (double) pend * (mejillon.x - x_0) + y_0) mejillones_lado1++;
                else if ((double)mejillon.y < (double)pend * (mejillon.x - x_0) + y_0) mejillones_lado2++;
            }
            for (auto gamba : gambas) {
                if ((double)gamba.y > (double) pend * (gamba.x - x_0) + y_0) gambas_lado1++;
                else if ((double)gamba.y < (double)pend * (gamba.x - x_0) + y_0) gambas_lado2++;
            }
        }
        // Si puedo dejar la misma cantidad en cada lado, es divisible
        if ((tropezon_limite == 0 && abs(mejillones_lado1 - mejillones_lado2) == 1 && gambas_lado1 == gambas_lado2) ||
            (tropezon_limite == 1 && abs(gambas_lado1 - gambas_lado2) == 1 && mejillones_lado1 == mejillones_lado2)) {
            return true;
        }
        i++;
    }

    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, g;
    cin >> m >> g;
    while (m != 0 || g != 0) {
        vector<pos> mejillones(m);
        vector<pos> gambas(g);

        for (int i = 0; i < m; i++) {
            cin >> mejillones[i].x >> mejillones[i].y;
        }
        for (int i = 0; i < g; i++) {
            cin >> gambas[i].x >> gambas[i].y;
        }
        bool divisible = divisible_recta(0, mejillones, gambas);
        if (!divisible) divisible = divisible_recta(1, mejillones, gambas);


        if (divisible) cout << "SI" << endl;
        else cout << "NO" << endl;

        cin >> m >> g;
    }
    return 0;
}