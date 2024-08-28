#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


// a structure to represent a weighted edge in graph
struct Edge {
    int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
    // V-> Number of vertices, E-> Number of edges
    int V;

    // graph is represented as an array of edges.
    vector<Edge> edges = vector<Edge>();
};



bool relax(Edge const& edge, int dist[], int V){
    int u = edge.src;
    int v = edge.dest;
    int weight = edge.weight;
    if (u != V-1 && dist[u] != INT_MAX && dist[u] + weight < dist[v]){
        dist[v] = dist[u] + weight;
        return true;
    }
    return false;
}


// The main function that finds shortest distances from src
// to all other vertices using Bellman-Ford algorithm.  The
// function also detects negative weight cycle
void solution(Graph const& graph, int src){

    int V = graph.V;
    int dist[V];
    
    // Step 1: Initialize distances from src to all other
    // vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    // Step 2: Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
    for (int i = 1; i <= V - 1; i++) {
        for (Edge edge : graph.edges) {
            relax(edge, dist, V);
        }
    }
    // Step 3: check for negative-weight cycles.  The above
    // step guarantees shortest distances if graph doesn't
    // contain negative weight cycle. If we get a shorter
    // path, then there is a cycle.
    for (Edge edge : graph.edges) {
        if (relax(edge, dist, V)) {
            cout << "EXPLOSION\n";
            return;
        }
    }
    if (dist[V-1] == INT_MAX) cout << "IMPOSIBLE\n";
    else cout << dist[V-1] << '\n';
}




void add_adjacents(vector<vector<char>> const& mapa, Graph & graph, int i, int j, int w, int h){
    int dest = i * w + j;
    if (i > 0 && mapa[i-1][j] == '.'){
        int src = (i-1) * w + j;
        graph.edges.push_back({src, dest, 1});
    }
    if (i < h-1 && mapa[i+1][j] == '.'){
        int src = (i+1) * w + j;
        graph.edges.push_back({src, dest, 1});
    }
    if (j > 0 && mapa[i][j-1] == '.'){
        int src = i * w + j - 1;
        graph.edges.push_back({src, dest, 1});
    }
    if (j < w-1 && mapa[i][j+1] == '.'){
        int src = i * w + j + 1;
        graph.edges.push_back({src, dest, 1});
    }
}

int main(){
    int w, h;
    while(cin >> w >> h){
        vector<vector<char>> mapa (h, vector<char>(w));
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cin >> mapa[i][j];
            }
        }

        Graph graph;
        graph.V = w * h;
        vector<int> agujeros_gusano;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                if (mapa[i][j] == '.') add_adjacents(mapa, graph, i, j, w, h);
                else if (mapa[i][j] == 'O'){
                    add_adjacents(mapa, graph, i, j, w, h);
                    agujeros_gusano.push_back(i * w + j);
                }
            }
        }

        for (int agujero_gusano: agujeros_gusano){
            int x, y, e;
            cin >> x >> y >> e;
            x--;
            y--;
            graph.edges.push_back({agujero_gusano, y * w + x, e});
        }
        solution(graph, 0);

    }



    return 0;
}
