#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return v.first * 10001 + v.second;
    }
};

class Graph {
    int V;
    list<pair<int, int> >* adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int numShortestsPaths(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}


int Graph::numShortestsPaths(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    unordered_set<pair<int, int>, pair_hash> settled;
    vector<int> dist(V, INF);
    vector<int> num_formas(V, 0);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    num_formas[src] = 1;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        list<pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (settled.count(make_pair(v, u))) continue;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                num_formas[v] = num_formas[u];
            }
            else if (dist[v] == (dist[u] + weight)) {
                num_formas[v] += num_formas[u];
            }
            settled.insert(make_pair(v, u));
        }
    }
    return num_formas[V - 1];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    while (cin >> V) {
        Graph g(V);
        cin >> E;
        int ini, fin, peso;
        for (int i = 0; i < E; ++i) {
            cin >> ini >> fin >> peso;
            g.addEdge(ini - 1, fin - 1, peso);
        }

        cout << g.numShortestsPaths(0) << '\n';
    }

    return 0;
}