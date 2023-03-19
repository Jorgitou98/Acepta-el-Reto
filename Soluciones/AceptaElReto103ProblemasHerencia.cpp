#include <iostream>
#include <vector>
using namespace std;

double f(double x, vector<int> const& coefs) {
	double resul = 0;
	double termino = 1;
	for (int coef : coefs) {
		resul += coef * termino;
		termino *= x;
	}
	return resul;
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int grado;
	cin >> grado;
	while (grado != 20) {
		vector<int> coefs(grado + 1);
		for (int i = 0; i < grado + 1; ++i)
			cin >> coefs[grado - i];
		int n;
		cin >> n;
		double area = 0;
		for (int i = 0; i < n; ++i) {
			double h = ((double) 1 / (double) n);
			double eval = f(i * h, coefs);
			if (eval < 0) continue;
			else if (eval > 1) eval = 1;
			area += h * eval;
		}
		if (area < 0.4995) cout << "ABEL\n";
		else if (area > 0.5005) cout << "CAIN\n";
		else cout << "JUSTO\n";
		cin >> grado;
	}


	return 0;
}