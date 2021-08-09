#include <iostream> 
#include <cstdio> 
#include <vector>
#include <algorithm> 
#include <functional>
#include <utility>
#include <queue>
#include <climits>
using namespace std;


struct dest {
	int coste, destino;
	dest(int coste, int destino) {
		this->coste = coste;
		this->destino = destino;
	}
};

struct valorNodo {
	int coste, nodo, pasos;
	valorNodo(int coste, int nodo, int pasos) {
		this->coste = coste;
		this->nodo = nodo;
		this->pasos = pasos;
	}

};

class Compare {
public:
	bool operator()(valorNodo const& nodo1, valorNodo const& nodo2) {
		return nodo1.coste > nodo2.coste;
	}

};

void dijkstra(vector<vector<dest>> const& adjList, vector<pair<int,int>>& dist, int ini) {
	dist[ini].first = 0;
	dist[ini].second = 0;

	priority_queue<valorNodo, vector<valorNodo>, Compare> cola;
	cola.push(valorNodo(0,ini,0));
	while (!cola.empty()) {
		valorNodo s = cola.top();
		cola.pop();
		if (s.coste > dist[s.nodo].first) continue;
		for (int i = 0; i < adjList[s.nodo].size(); i++) {
			dest to = adjList[s.nodo][i];
			if (to.coste + dist[s.nodo].first < dist[to.destino].first || to.coste + dist[s.nodo].first <= dist[to.destino].first && dist[s.nodo].second + 1 < dist[to.destino].second) {
				dist[to.destino].first = to.coste + dist[s.nodo].first;
				dist[to.destino].second = s.pasos + 1;
				cola.push(valorNodo(dist[to.destino].first, to.destino, s.pasos+1));
			}
		}
	}
}


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n, c;
	while (cin >> n) {
		cin >> c;
		vector<vector<dest>> grafo(n, vector<dest>());
		vector<vector<dest>> grafoUnos(n, vector<dest>());
		int origen, destino, valor;
		for (int i = 0; i < c; ++i){
			cin >> origen >> destino >> valor;
			grafo[origen - 1].push_back(dest(valor, destino-1));
			grafo[destino - 1].push_back(dest(valor, origen-1));
			grafoUnos[origen - 1].push_back(dest(1, destino - 1));
			grafoUnos[destino - 1].push_back(dest(1, origen - 1));
		}
		int k;
		cin >> k;
		int ini, fin;
		for (int i = 0; i < k; ++i) {
			cin >> ini >> fin;
			vector<pair<int, int>> dist(n, { INT_MAX, INT_MAX });
			dijkstra(grafo, dist, ini-1);
			if (dist[fin - 1].first == INT_MAX) cout << "SIN CAMINO\n";
			else {
				cout << dist[fin - 1].first << " ";
				vector<pair<int, int>> distOpt(n, { INT_MAX, INT_MAX });
				dijkstra(grafoUnos, distOpt, ini - 1);
				if (dist[fin - 1].second == distOpt[fin - 1].first) cout << "SI\n";
				else cout << "NO\n";
			}
		}
		cout << "----\n";		
	}

	return 0;
}