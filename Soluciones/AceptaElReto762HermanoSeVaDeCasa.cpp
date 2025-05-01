#include <iostream>
#include <cmath>
using namespace std;


double polinomio(double a, double b, double w, double m) {
    double a_cuad = a * a;
    double b_cuad = b * b;
    double w_cuad = w * w;
    double m_cuad = m * m;
    double m_cubo = m_cuad * m;
    double m_cuarta = m_cubo * m;
    double m_sexta = m_cuarta * m_cuad;
    return (b_cuad - w_cuad) * m_sexta + w_cuad * m_cuarta - 2 * a * b * m_cubo + w_cuad * m_cuad + (a_cuad - w_cuad);
}

double bisec_cero(double a, double b, double w) {
    if (a == b) return 1;
    double left = 0, right = pow(a / b, 1 / 3.);
    double mid;
    for (int i = 0; i < 100; ++i) { // Suficientes iteraciones para precisión
        mid = (left + right) / 2;
        double eval = polinomio(a, b, w, mid);
        if (eval < 0) right = mid;
        else left = mid;
    }
    return mid;
}

double longitud_max(double a, double b, double w, double m) {
    double term_1 = (1 + 1 / (m * m));
    double term_2 = m * b + a - w * pow(m * m + 1, 1 / 2.);
    term_2 = term_2 * term_2;
    return pow(term_1 * term_2, 1 / 2.);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double w, l, a, b;
    while (cin >> w >> l >> a >> b) {
        // Swap
        if (w > l) swap(l, w);

        if (w > a || w > b) {
            cout << "NO\n";
            continue;
        }

        // Swap
        if (a > b) swap(a, b);

        double m = bisec_cero(a, b, w);
        double l_max = longitud_max(a, b, w, m);
        if (l <= l_max) cout << "SI\n";
        else cout << "NO\n";
    }
    return 0;
}