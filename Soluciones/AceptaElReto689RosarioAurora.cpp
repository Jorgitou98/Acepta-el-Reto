#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> const& adj, vector<int> &col, int ini, int col1, int col2, int &num_col1, int & num_col2){
    queue<pair<int, int> > q;
    q.push({ ini, col1 });
    col[ini] = col1;
    num_col1++;
    bool bipartito = true;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int v = p.first;
        int c = p.second;
        for (int j : adj[v]) {
            if (col[j] == c) bipartito = false;
            if (col[j] == -1) {
                int otro = col2;
                if (c == col1) {
                    col[j] = col2;
                    q.push({ j, col2 });
                    num_col2++;
                }
                else {
                    col[j] = col1;
                    q.push({ j, col1 });
                    num_col1++;
                }
                
            }
        }
    }
    return bipartito;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E, A;
    while (cin >> V >> E >> A) {
        vector<vector<int>> adj(V);
        int ini, fin;
        for (int i = 0; i < E; i++) {
            cin >> ini >> fin;
            ini--;
            fin--;
            adj[ini].push_back(fin);
            adj[fin].push_back(ini);
        }
        int col1 = 0;
        int col2 = 1;
        vector<int> col(V, -1);
        vector<pair<int, int>> pares_cols;
        for (int i = 0; i < V; ++i) {
            if (col[i] == -1) {
                int num_col1 = 0;
                int num_col2 = 0;
                if (isBipartite(adj, col, i, col1, col2, num_col1, num_col2))
                    pares_cols.push_back({ num_col1, num_col2 });
                col1++;
                col2++;
            }
        }
        // DP sums
        vector<int> sum(A+1, -2);
        sum[0] = -1;
        for (int i = 0; i < pares_cols.size(); ++i) {
            for (int j = 0; j < A + 1; j++) {
                if (sum[j] != -2) continue;
                if (j >= pares_cols[i].first && sum[j- pares_cols[i].first] != -2 && sum[j - pares_cols[i].first] != i){
                    sum[j] = i;
                }
                else if (j >= pares_cols[i].second && sum[j - pares_cols[i].second] != -2 && sum[j - pares_cols[i].second] != i) {
                    sum[j] = i;
                }
            }
        }
        for (int i = A; i >= 0; i--) {
            if (sum[i] > -2) {
                cout << i << '\n';
                break;
            }
        }
    }
    
    return 0;
}