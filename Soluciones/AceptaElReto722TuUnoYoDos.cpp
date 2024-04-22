#include <iostream>
using namespace std;


int main(){
    long long int fila1, fila2, elige1, elige2;
    cin >> fila1 >> fila2 >> elige1 >> elige2;
    while(fila1 != 0 || fila2 != 0 || elige1 != 0 || elige2 != 0){
        if (elige1 == elige2){
            if (fila1 == fila2 && fila1 % elige1 == 0) cout << "SI\n";
            else cout << "NO\n";
            cin >> fila1 >> fila2 >> elige1 >> elige2;
            continue;
        }
        long long int numerador1 = fila1*elige2-fila2*elige1;
        long long int denominador1 = elige2 * elige2 - elige1 * elige1;
        if (numerador1 < 0 && denominador1 > 0 || numerador1 > 0 && denominador1 < 0 || numerador1 % denominador1 != 0 ){
            cout << "NO\n";
            cin >> fila1 >> fila2 >> elige1 >> elige2;
            continue;
        }
        long long int x = numerador1 / denominador1;
        long long int numerador2 = fila2 - elige1*x;
        long long int denominador2 = elige2;
        if (numerador2 < 0 || numerador2 % denominador2 != 0 ){
            cout << "NO\n";
            cin >> fila1 >> fila2 >> elige1 >> elige2;
            continue;
        }

        cout << "SI\n";

        cin >> fila1 >> fila2 >> elige1 >> elige2;
    }



    return 0;
}