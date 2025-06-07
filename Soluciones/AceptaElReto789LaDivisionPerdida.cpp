#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct tSolucion {
    int divisor;
    string cociente;
};


vector<tSolucion> divisores_factibles(string const& num_str, int resto) {
    vector<tSolucion> divisores;
    int num = stoi(num_str);
    int num_objetivo = num - resto;
    for (int i = 1; i <= 9; i++) {
        if (num_objetivo % i == 0) {
            int candidato = num_objetivo / i;
            if (candidato > resto) {
                divisores.push_back({ candidato, to_string(i) });
            }
        }
    }
    return divisores;
}

vector<tSolucion> divisores_verificados(vector<tSolucion> const& posibles_soluciones, vector<int> const& restos, string const& num_str) {
    vector<tSolucion> soluciones;
    for (tSolucion const& candidato : posibles_soluciones) {
		int divisor = candidato.divisor;
		string cociente = candidato.cociente;
        bool es_valido = true;
        int i_resto = 0;
        while (es_valido && i_resto < restos.size() - 1) {
            int valor_div = restos[i_resto] * 10 + (num_str[i_resto] - '0');
            if (valor_div % divisor != restos[i_resto + 1]) {
                es_valido = false;
            }
            cociente.push_back(valor_div / divisor + '0');
            i_resto++;
        }
        if (es_valido) {
            soluciones.push_back({ divisor, cociente });
        }
    }
    return soluciones;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string num;
    cin >> num;
    while (num != "0") {
        int num_restos;
        cin >> num_restos;
        vector<int> restos(num_restos);
        for (int i = 0; i < num_restos; i++) {
            cin >> restos[i];
        }
        int long_dividendo_inicial = num.length() - num_restos + 1;
        vector<tSolucion> posibles_divisores = divisores_factibles(num.substr(0, long_dividendo_inicial), restos[0]);
        vector<tSolucion> divisores_sol = divisores_verificados(posibles_divisores, restos, num.substr(long_dividendo_inicial, num.length() - long_dividendo_inicial));

        for (int i = 0; i < divisores_sol.size(); i++) {
            cout << divisores_sol[i].divisor << ' ' << divisores_sol[i].cociente;
            if (i < divisores_sol.size() - 1) {
                cout << " - ";
            }
        }
        cout << '\n';

        cin >> num;
    }



    return 0;
}