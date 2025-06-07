#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
using namespace std;

vector<int> dijkstra(int src, vector<vector<pair<int,int>>> const& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto par = pq.top();
        auto d = par.first;
        auto u = par.second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& par : adj[u]) {
            auto v = par.first;
            auto w = par.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int np, nc;
    while (cin >> np >> nc) {
        vector<vector<pair<int, int>>> adj(np);
        for (int i = 0; i < nc; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        int c;
        cin >> c;
        for (int i = 0; i < c; i++) {
            int num_pueblos;
            cin >> num_pueblos;
            vector<int> pueblos(num_pueblos);
			unordered_set<int> pueblos_set;
            for (int j = 0; j < num_pueblos; j++) {
                cin >> pueblos[j];
                pueblos[j]--;
				pueblos_set.insert(pueblos[j]);
            }

			// c ejecuciones de Dijkstra desde cada pueblo con colegio
            vector<vector<int>> dist(num_pueblos, vector<int>(np));
            for (int i = 0; i < num_pueblos; i++) {
                dist[i] = dijkstra(pueblos[i], adj);
            }

			// Construir matriz D_ij de distancias entre pueblos con colegio
            vector<vector<int>> dist_pueblos(num_pueblos, vector<int>(num_pueblos, INT_MAX));
            for (int i = 0; i < num_pueblos; i++) {
                for (int j = 0; j < num_pueblos; j++) {
                    dist_pueblos[i][j] = dist[i][pueblos[j]];
                }
            }

            // DP: dp[mask][s][e] = mejor costo arrancando en s, visitando mask (incluye s y e), y terminando en e.
            int MS = 1 << num_pueblos;
			vector<vector<vector<int>>> dp(MS, vector<vector<int>>(num_pueblos, vector<int>(num_pueblos, INT_MAX)));

            // Máscara con solo s
            for (int s = 0; s < num_pueblos; s++) {
                dp[1 << s][s][s] = 0;
            }

            for (int mask = 0; mask < MS; mask++) {
                for (int s = 0; s < num_pueblos; s++) {
					if (!(mask & (1 << s))) continue; // La máscara debe incluir s
                    for (int e = 0; e < num_pueblos; e++) {
						if (!(mask & (1 << e))) continue; // La máscara debe incluir e
                        int cur = dp[mask][s][e];
                        if (cur == INT_MAX) continue;
                        // añadimos un nuevo colegio j que no esté en mask
                        for (int j = 0; j < num_pueblos; j++) {
							if (mask & (1 << j)) continue; // Si ya está en mask, no lo añadimos
                            int nmask = mask | (1 << j);
                            dp[nmask][s][j] = min(dp[nmask][s][j], cur + dist_pueblos[e][j]);
                        }
                    }
                }
            }

            int todos_mask = MS - 1;
            int mejorNodo = -1, mejorCoste = INT_MAX;
            for (int nodo = 0; nodo < np; nodo++) {
				// no puede vivir en un pueblo con colegio
                if (pueblos_set.count(nodo)) continue;

                int costeNodo = INT_MAX;
                // probamos todos (s,e) extremos
                for (int s = 0; s < num_pueblos; s++) {
                    if (dist[s][nodo] == INT_MAX) continue;
                    for (int e = 0; e < num_pueblos; e++) {
                        if (dist[e][nodo] == INT_MAX) continue;
                        int tour = dp[todos_mask][s][e];
                        if (tour == INT_MAX) continue;
                        costeNodo = min(costeNodo, dist[s][nodo] + tour + dist[e][nodo]);
                    }
                }
                if (costeNodo < mejorCoste) {
                    mejorCoste = costeNodo;
                    mejorNodo = nodo;
                }
            }


            cout << mejorNodo + 1 << ' ' << mejorCoste << '\n';
        }
        cout << "---\n";
    }
    return 0;
}
