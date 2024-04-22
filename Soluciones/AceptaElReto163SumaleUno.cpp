#include <iostream>
#include <string>
using namespace std;


char siguiente(char valor){
    if (valor == '9') return 'A';
    if (valor == 'F') return '0';
    return valor + 1;
}

int main(){
    string numero;
    cin >> numero;
    while(numero != "FIN"){
        int acarreo = 1;
        int pos = numero.length() - 1;
        while (pos >= 0 && acarreo == 1){
            if (numero[pos] != 'F') acarreo = 0;
            numero[pos] = siguiente(numero[pos]);
            pos--;
        }
        if (acarreo == 1) numero = '1' + numero;
        cout << numero << '\n';
    
        cin >> numero;
    }
    return 0;
}
