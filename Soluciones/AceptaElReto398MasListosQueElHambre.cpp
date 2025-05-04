#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Punto {
    int x, y;
};

struct Estado {
    int tA, tB;
};

int distancia_manhattan(Punto const& p1, Punto const& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void insert_pareto(vector<Estado>& vec, Estado estado) {
    int tA = estado.tA, tB = estado.tB;
    // 1) Descarta si está dominado
    for (auto const& otro_estado : vec) {
        if (otro_estado.tA <= tA && otro_estado.tB <= tB) {
            return;
        }
    }
    // 2) Elimina los que estado domina
    vector<Estado> filtrado;
    for (auto const& otro_estado : vec) {
        if (tA > otro_estado.tA || tB > otro_estado.tB) {
            filtrado.emplace_back(otro_estado);
        }
    }
    vec = move(filtrado);
    // 3) Añade estado
    vec.emplace_back(Estado{ tA, tB });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int filas, columnas, num_botones;
    while (cin >> filas >> columnas) {
        cin >> num_botones;
        vector<Punto> botones(num_botones + 1);
        // inicio en (1,1)
        botones[0] = { 1,1 };
        for (int i = 1; i <= num_botones; i++) {
            cin >> botones[i].x >> botones[i].y;
        }

        vector<vector<vector<Estado>>> dp(
            num_botones + 1,
            vector<vector<Estado>>(num_botones + 1)
        );
        dp[0][0].emplace_back(Estado{ 0, 0 });

        // DP sobre el número de botones ya pulsados
        for (int boton = 0; boton < num_botones; boton++) {
            // Recorre todos i,boton
            for (int i = 0; i <= boton; i++) {
                int dist_i = distancia_manhattan(botones[i], botones[boton + 1]);
                int dist_boton = distancia_manhattan(botones[boton], botones[boton + 1]);
                for (auto const& estado : dp[i][boton]) {
                    int tA = estado.tA, tB = estado.tB;
                    int dist_avance = max(0, dist_i - (tB - tA));
                    // Opción: A pulsa el siguiente botón
                    insert_pareto(dp[boton][boton + 1], { tB, tB + dist_avance });
                    // Opción: B pulsa el siguiente botón
                    insert_pareto(dp[i][boton + 1], { tA, tB + dist_boton });
                }
            }
        }

        // Fase final: ya se pulsaron N botones, ambos deben llegar a salida
        int sol = INT_MAX;
        for (int i = 0; i <= num_botones; i++) {
            int dist_i = distancia_manhattan(botones[i], { filas, columnas });
            int dist_boton = distancia_manhattan(botones[num_botones], { filas, columnas });
            // Estados (i,N)
            for (auto const& estado : dp[i][num_botones]) {
                int tA = estado.tA, tB = estado.tB;
                int dist_avance = max(0, dist_i - (tB - tA));
                int finA = tB + dist_avance;
                int finB = tB + dist_boton;
                sol = min(sol, max(finA, finB) + 1);
            }
        }

        cout << sol << "\n";
    }

    return 0;
}