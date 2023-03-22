#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <ctype.h>
using namespace std;


struct valorNodo {
    int coste, nodoI, nodoJ;
    valorNodo(int coste, int nodoI, int nodoJ) {
        this->coste = coste;
        this->nodoI = nodoI;
        this->nodoJ = nodoJ;
    }

};


vector<pair<int, int>> vecinos(int i, int j) {
    return { {i - 1,j}, {i + 1,j} , {i,j - 1} , {i,j + 1} };
}


int bfs(vector<vector<char>> const& M, int entradaI, int entradaJ, int salidaI, int salidaJ, int alto, int ancho) {
    queue<valorNodo> cola;
    vector<vector<bool>> visited(alto, vector<bool>(ancho, false));
    cola.push(valorNodo(0, entradaI, entradaJ));
    visited[entradaI][entradaJ] = true;
    while (!cola.empty()) {
        valorNodo u = cola.front();
        cola.pop();
        for (pair<int, int> par: vecinos(u.nodoI, u.nodoJ)) {
            if (par.first < 0 || par.first >= alto || par.second < 0 || par.second >= ancho || M[par.first][par.second] == '#' || M[par.first][par.second] == 'R' || isdigit(M[par.first][par.second])) continue;
            else if (par.first == salidaI && par.second == salidaJ) return u.coste + 1;
            else if (!visited[par.first][par.second]) {
                visited[par.first][par.second] = true;
                cola.push(valorNodo(u.coste+1, par.first, par.second));
            }
        }
    }
    return -1;
}


int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int numcasos;
    cin >> numcasos;
    for (int c = 0; c < numcasos; ++c) {
        int ancho, alto;
        cin >> ancho >> alto;
        vector<vector<char>> M(alto, vector<char>(ancho));
        int entradaI, entradaJ, salidaI, salidaJ;
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                cin >> M[i][j];
                if (M[i][j] == 'E') {
                    entradaI = i;
                    entradaJ = j;
                }
                else if (M[i][j] == 'P') {
                    salidaI = i;
                    salidaJ = j;
                }
            }
        }
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                if(isdigit(M[i][j])){
                    //Norte
                    for (int n = 1; n <= (M[i][j] - '0') && i - n >= 0; n++) {
                        if (M[i - n][j] == '#') break;
                        else if(!isdigit(M[i - n][j])) M[i - n][j] = 'R';
                    }
                    // Sur
                    for (int s = 1; s <= (M[i][j] - '0') && i + s < alto; s++) {
                        if (M[i + s][j] == '#') break;
                        else if (!isdigit(M[i + s][j])) M[i + s][j] = 'R';
                    }
                    // Este
                    for (int e = 1; e <= (M[i][j] - '0') && j + e < ancho; e++) {
                        if (M[i][j + e] == '#') break;
                        else if (!isdigit(M[i][j + e])) M[i][j + e] = 'R';
                    }
                    // Oeste
                    for (int o = 1; o <= (M[i][j] - '0') && j - o >= 0; o++) {
                        if (M[i][j - o] == '#') break;
                        else if (!isdigit(M[i][j - o])) M[i][j - o] = 'R';
                    }
                }
            }
        }
        if (M[entradaI][entradaJ] == 'R' || M[salidaI][salidaJ] == 'R') {
            cout << "NO\n";
            continue;
        }
        int pasos = bfs(M, entradaI, entradaJ, salidaI, salidaJ, alto, ancho);
        if (pasos == -1) cout << "NO\n";
        else cout << pasos << '\n';
    }

    return 0;
}