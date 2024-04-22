#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int num_casos;
    cin >> num_casos;
    while(num_casos--){
        string numero;
        cin >> numero;
        vector<int> menores(numero.length());
        vector<int> mayores(numero.length());
        int minimo = 10;
        int maximo = -1;
        for (int i = 0; i < numero.length(); ++i){
            mayores[i] = maximo;
            maximo = max(maximo, numero[i] - '0');
        }
        for (int i = numero.length()-1; i >= 0 ; --i){
            menores[i] = minimo;
            minimo = min(minimo, numero[i] - '0');
        }
        int codigo = 0;
        bool impar = true;
        bool no_cero_izquierda = false;
        for (int i = 0; i < numero.length(); ++i){
            if(numero[i] != '0' || no_cero_izquierda){
                if (impar) codigo += (numero[i] - '0') * 3 + menores[i];
                else codigo += (numero[i] - '0') * 2 + mayores[i];
                no_cero_izquierda = true;
            }
            impar = !impar;
        }

        cout << codigo << '\n';

    }


    return 0;
}