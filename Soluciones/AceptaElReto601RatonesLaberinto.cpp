#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
    int V;
    list<pair<int, int> >* adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    vector<int> shortestPath(int s);
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<iPair>[V];
}
void Graph::addEdge(int u, int v, int w){
    adj[v].push_back(make_pair(u, w));
}

vector<int> Graph::shortestPath(int src){
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main(){
    int N, S, P, T;
    while(cin >> N >> S >> T >> P){
        Graph g(N);
        int v1, v2, w;
        for (int i = 0; i < P; i++){
            cin >> v1 >> v2 >> w;
            g.addEdge(v1-1, v2-1, w);
        }
        vector<int> dist = g.shortestPath(S-1);
        int alcanzan = 0;
        for (int i = 0; i < N; i++){
            if (i != S -1 && dist[i] <= T) alcanzan++;
        }
        cout << alcanzan << '\n';
        
    }
 
    return 0;
}