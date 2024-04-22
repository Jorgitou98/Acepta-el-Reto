#include <iostream> 
#include <vector>
using namespace std;


struct fraccion {
    long long int numerador, denominador;
};

long long int gcd(long long int a, long long int b){
    return b == 0 ? a : gcd(b, a % b);
}

long long int lcm(long long int a, long long int b){
    return (a / gcd(a, b)) * b;
}

int main(){
    int n;
    cin >> n;
    while (n != 0) {
        vector<fraccion> fracciones(n);
        string cadena;
        for (int i = 0; i < n; ++i) {
            cin >> cadena;
            fracciones[i].numerador = 0;
            int pos_cad = 0;
            while (cadena[pos_cad] != '/') {
                fracciones[i].numerador *= 10;
                fracciones[i].numerador += (long long int) cadena[pos_cad] - '0';
                pos_cad++;
            }
            pos_cad++;
            fracciones[i].denominador = 0;
            while (pos_cad < cadena.size()) {
                fracciones[i].denominador *= 10;
                fracciones[i].denominador += (long long int) cadena[pos_cad] - '0';
                pos_cad++;
            }
        }

        long long int total = 1;
        for (int i = 0; i < n; ++i) {
            total = lcm(total, fracciones[i].denominador);
        }
        long long int restante = total;
        for (int i = 0; i < n; ++i) {
            restante -= total * fracciones[i].numerador / fracciones[i].denominador;
        }
        cout << restante << '\n';
        cin >> n;
    }

}
