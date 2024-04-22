#include <iostream>
using namespace std;

int main(){
    int A;
    cin >> A;
    for (int i = 0; i < A; i++){
        int N, M;
        cin >> N >> M;
        int suma = N + M;
        int rango = suma * (suma + 1) / 2 + 1;
        rango += N;
        cout << rango << '\n';
    }
    return 0;
}