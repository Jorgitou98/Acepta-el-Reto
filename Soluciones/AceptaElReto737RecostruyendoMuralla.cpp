#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num_casos;
    cin >> num_casos;
    for (int caso = 0; caso < num_casos; caso++){
        int n;
        cin >> n;
        int maximo = 0; 
        vector<int> alturas(n+1);
        for (int i = 1; i < n+1; ++i){
            cin >> alturas[i];
            if (alturas[i] > maximo) maximo = alturas[i];
        }
        long long int acum = 0;
        vector<long long int> diferencias_acum(n+1);
        for (int i = 1; i < n+1; ++i){
            acum += maximo - alturas[i];
            diferencias_acum[i] = acum;
        }
        int q;
        cin >> q;
        for (int consulta = 0; consulta < q; ++consulta){
            int ini, fin;
            cin >> ini >> fin;
            cout << diferencias_acum[fin] - diferencias_acum[ini-1] << '\n';
        }
        cout << "---\n";
    }
    return 0;
}