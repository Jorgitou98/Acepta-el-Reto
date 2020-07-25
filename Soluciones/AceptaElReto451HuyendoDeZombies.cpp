#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <functional>
#include <climits>

using namespace std;
using arista = pair<int, int>;
using ii = arista;
using vi = vector<int>;
using vii = vector <arista>;

void dijkstra(int s, vector<vii>  &adjList, vi &dist) {
    dist.assign(adjList.size(), INT_MAX);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq; pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (int j = 0; j < adjList[u].size(); j++) {
            ii v = adjList[u][j];
            if (dist[u] + v.first < dist[v.second]) {
                dist[v.second] = dist[u] + v.first;
                pq.push(ii(dist[v.second], v.second));
            }
        }
    }
}


void resuelveCaso(int N, int M) {
    vector<vector<arista>> listaAdy(M+2, vector<arista>());
    unordered_map<int, vector<arista>> mapa;
    cin.ignore();
    for (int i = 1; i <= M; i++) {
        string tmp;
        getline(cin, tmp);
        int origen, primero, destino, peso, sum_peso=0;
        stringstream ss(tmp);
        ss >> origen; origen--;
        if (origen == 0) {
            listaAdy[i].push_back({ 0, 0 });
            listaAdy[0].push_back({ 0, i });
        }
        else if (origen == N-1) {
            listaAdy[i].push_back({ 0, M + 1 });
            listaAdy[M + 1].push_back({ 0, i });
        }
        if (!mapa.count(origen)) {
            mapa[origen] = vector<arista>();
        }
        else {
            for (auto const& pareja : mapa[origen]) {
                int peso_arista_ida = (pareja.first >= sum_peso) ? pareja.first - sum_peso : 60 + pareja.first - sum_peso;
                int peso_arista_vuelta = (sum_peso >= pareja.first) ? sum_peso - pareja.first : 60 + sum_peso - pareja.first;
                listaAdy[i].push_back({ peso_arista_ida, pareja.second });
                listaAdy[pareja.second].push_back({ peso_arista_vuelta, i });
            }
        }
        mapa[origen].push_back({ 0, i });

        while (ss >> peso >> destino) {
            destino--;
            sum_peso += peso;
            if (destino == 0) {
                listaAdy[i].push_back({ 0, 0 });
                listaAdy[0].push_back({ 0, i });
            }
            else if (destino == N - 1) {
                listaAdy[i].push_back({ 0, M + 1 });
                listaAdy[M + 1].push_back({ 0, i });
            }
            if (!mapa.count(destino)) {
                mapa[destino] = vector<arista>();
            }
            else {
                for (auto const& pareja : mapa[destino]) {
                    int peso_arista_ida = (pareja.first >= sum_peso) ? pareja.first - sum_peso : 60 + pareja.first - sum_peso;
                    int peso_arista_vuelta = (sum_peso >= pareja.first) ? sum_peso - pareja.first : 60 + sum_peso - pareja.first;
                    listaAdy[i].push_back({ peso_arista_ida, pareja.second });
                    listaAdy[pareja.second].push_back({ peso_arista_vuelta, i });
                }
            }
            mapa[destino].push_back({ sum_peso, i });
        }
    }

    vector<int> distancias(M + 2);
    dijkstra(0, listaAdy, distancias);
    if (distancias[M + 1] != INT_MAX) {
        cout << distancias[M + 1] << '\n';
    }
    else {
        cout << "Hoy no vuelvo\n";
    }
    return;
}



int main() {
    int N, M;
    ios::sync_with_stdio(false);
    while (cin >> N >> M) {
        resuelveCaso(N,M);
    }

    return 0;
}
