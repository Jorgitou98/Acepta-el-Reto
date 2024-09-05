#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<vector<long long int>> dp_todos_digitos(int cifras) {
    vector<vector<long long int>> posibilidades(cifras + 1, vector<long long int>(9 * cifras + 1, 0));
    posibilidades[0][0] = 1;
    for (int i = 1; i < cifras + 1; i++) {
        for (int j = 0; j < 9 * cifras + 1; j++) {
            for (int digito = 0; digito < 10; digito++) {
                if (j - digito >= 0) {
                    posibilidades[i][j] += posibilidades[i - 1][j - digito];
                }
            }
        }
    }
    return posibilidades;
}

vector<long long int> num_formas_sumar(string const& num, vector<vector<long long int>> const& sum_pos, int pos_mas_sig, int suma_hasta_ahora) {
    vector<long long int> num_sumas(num.size() * 9 + 1, 0);

    // Caso base
    if (pos_mas_sig == num.size()) {
        num_sumas[suma_hasta_ahora] = 1;
        return num_sumas;
    }

    int cifra_mas_sign = num[pos_mas_sig] - '0';

    for (int i = 0; i < cifra_mas_sign; i++) {
        for (int suma = 0; suma < num.size() * 9 + 1; suma++) {
            if (suma - i - suma_hasta_ahora >= 0) {
                num_sumas[suma] += sum_pos[num.size() - pos_mas_sig - 1][suma - i - suma_hasta_ahora];
            }
        }

    }

    vector<long long int> v = num_formas_sumar(num, sum_pos, pos_mas_sig + 1, suma_hasta_ahora + cifra_mas_sign);

    for (int i = 0; i < v.size(); i++) {
        num_sumas[i] += v[i];
    }

    return num_sumas;
}

int main() {
    vector<vector<long long int>> sum_pos = dp_todos_digitos(16);
    long long int a, b;
    cin >> a >> b;
    while (a != 0 || b != 0) {
        vector<long long int> num_sumas_a = num_formas_sumar(to_string(a-1), sum_pos, 0, 0);
        vector<long long int> num_sumas_b = num_formas_sumar(to_string(b), sum_pos, 0, 0);

        long long int coste = 0;
        for (int i = 3; i < num_sumas_b.size(); i += 3) {
			coste += i * num_sumas_b[i];
			if (i < num_sumas_a.size()) {
				coste -= i * num_sumas_a[i];
			}
        }
        cout << coste << '\n';

        cin >> a >> b;
    }


    return 0;
}