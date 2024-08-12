#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include <queue>
using namespace std;


class DisjSet { 
    int *rank, *parent, n; 
  
public: 
    
    // Constructor to create and 
    // initialize sets of n items 
    DisjSet(int n) { 
        rank = new int[n]; 
        parent = new int[n]; 
        this->n = n; 
        makeSet(); 
    } 
  
    // Creates n single item sets 
    void makeSet() { 
        for (int i = 0; i < n; i++) { 
            parent[i] = i; 
        } 
    } 
  
    // Finds set of given item x 
    int find(int x) { 
        // Finds the representative of the set 
        // that x is an element of 
        if (parent[x] != x) { 
  
            // if x is not the parent of itself 
            // Then x is not the representative of 
            // his set, 
            parent[x] = find(parent[x]); 
  
            // so we recursively call Find on its parent 
            // and move i's node directly under the 
            // representative of this set 
        } 
  
        return parent[x]; 
    } 
  
    // Do union of two sets by rank represented by x and y. 
    void set_union(int x, int y) { 
        // Find current sets of x and y 
        int xset = find(x); 
        int yset = find(y); 
  
        // If they are already in same set 
        if (xset == yset) 
            return; 
  
        // Put smaller ranked item under bigger ranked item if ranks are different 
        if (rank[xset] < rank[yset]) { 
            parent[xset] = yset; 
        } 
        else if (rank[xset] > rank[yset]) { 
            parent[yset] = xset; 
        } 
  
        // If ranks are same, then increment rank. 
        else { 
            parent[yset] = xset; 
            rank[xset] = rank[xset] + 1; 
        } 
    } 
};

// Function to add an edge to the adjacency list
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

bool isCyclic(int V, vector<vector<int>>& adj) {
  
    // stores in-degree of each vertex
    vector<int> inDegree(V, 0); 
  
    // queue to store vertices with 0 in-degree
    queue<int> q; 
  
    int visited = 0; // count of visited vertices

    // Calculate in-degree of each vertex
    for (int u = 0; u < V; u++) {
        for (auto v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Enqueue vertices with 0 in-degree
    for (int u = 0; u < V; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    // BFS traversal
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;

        // Reduce in-degree of adjacent vertices
        for (auto v : adj[u]) {
            inDegree[v]--;
          
            // If in-degree becomes 0, enqueue it
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If not all vertices are visited, cycle
    return visited != V; 
}


int main(){
    int n, c;
    while(cin >> n >> c){
        DisjSet union_find(n+1);
        int num_1, num_2;
        char op;
        vector<pair<int,int>> v_menor;
        for (int i = 0; i < c; i++){
            cin >> num_1 >> op >> num_2;
            if (op == '='){
                union_find.set_union(num_1, num_2);
            }
            else if (op == '<'){
                v_menor.push_back({num_1, num_2});
            }
            else if (op == '>'){
                v_menor.push_back({num_2, num_1});
            }
        }
        bool correcto = true;
        vector<vector<int>> adj(n+1);
        for (auto const & par: v_menor){
            int rep_1 = union_find.find(par.first);
            int rep_2 = union_find.find(par.second);
            addEdge(adj, rep_1, rep_2);
        }
        if (isCyclic(n+1, adj)) cout << "TRAMPAS\n";
        else cout << "DESCONFIADO\n";
    }

    return 0;
}