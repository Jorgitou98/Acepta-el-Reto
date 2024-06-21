#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n, p;
    while(cin >> n >> p){
        vector<bool> diagonal_atacada(2*n-1, false);
        vector<bool> fila_atacada(n, false);
        int fila, columna;
        for (int i = 0; i < p; i++){
            cin >> fila >> columna;
            diagonal_atacada[fila - columna + n - 1] = true;
            fila_atacada[fila - 1] = true;           
        }
        vector<int> filas_menores(n);
        int filas_no_atacadas = 0;
        for (int i = 0; i < n; i++){
            if (!fila_atacada[i]) filas_no_atacadas++;
            filas_menores[i] = filas_no_atacadas;
        }
        long long int pos_no_ataques = 0;
        for (int d = 0; d < 2*n-1; d++){
            if (diagonal_atacada[d]) continue;
            int num_diag = d - n + 1;
            if (num_diag <= 0){
                int fila_limite = n-1+num_diag;
                pos_no_ataques += filas_menores[fila_limite];
            }
            else{
                pos_no_ataques += filas_menores[n-1] - filas_menores[num_diag-1];
            }
        }
        cout << pos_no_ataques << '\n';
    }

    return 0;
}