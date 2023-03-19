#include <iostream>
#include <vector>
using namespace std;


bool filas_diabolico(int n, vector<vector<int>> const& mat, int constante_magica) {
	bool diabolico = true;

	int sum_fila = 0;
	for (int i = 0; i < n; ++i) {
		sum_fila = 0;
		for (int j = 0; j < n; ++j) {
			sum_fila += mat[i][j];
		}
		if (sum_fila != constante_magica) {
			diabolico = false;
			break;
		}
	}
	return diabolico;
}

bool columnas_diabolico(int n, vector<vector<int>> const& mat, int constante_magica) {
	bool diabolico = true;

	int sum_col = 0;
	for (int j = 0; j < n; ++j) {
		sum_col = 0;
		for (int i = 0; i < n; ++i) {
			sum_col += mat[i][j];
		}
		if (sum_col != constante_magica) {
			diabolico = false;
			break;
		}
	}
	return diabolico;
}

bool diagonales_diabolico(int n, vector<vector<int>> const& mat, int constante_magica) {
	int diag = 0;

	for (int i = 0; i < n; ++i) diag += mat[i][i];
	if (diag != constante_magica) return false;

	diag = 0;
	for (int i = 0; i < n; ++i) diag += mat[n-1-i][i];

	return (diag == constante_magica);
}


bool mis_cifras(int n, vector<vector<int>> const& mat) {
	vector<bool> cifra(n * n, false);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (mat[i][j] < 1 || mat[i][j] > n * n || cifra[mat[i][j] - 1])
				return false;
			cifra[mat[i][j] - 1] = true;
		}
	return true;
}


bool esoterico(int n, vector<vector<int>> const& mat, int constante_magica) {
	if (!mis_cifras(n, mat)) return false;
	int constante_magica_2 = 4 * constante_magica / n;
	if ((mat[0][0] + mat[0][n - 1] + mat[n - 1][0] + mat[n - 1][n - 1]) != constante_magica_2)
		return false;
	int mitad = n / 2;
	if (n % 2 == 1) {
		if ((mat[0][mitad] + mat[mitad][0] + mat[mitad][n - 1] + mat[n - 1][mitad]) != constante_magica_2)
			return false;
		if (4 * mat[mitad][mitad] != constante_magica_2)
			return false;
	}
	else {
		int laterales = 0;
		laterales += (mat[0][mitad -1] + mat[0][mitad]);
		laterales += (mat[mitad-1][0] + mat[mitad][0]);
		laterales += (mat[mitad - 1][n-1] + mat[mitad][n-1]);
		laterales += (mat[n-1][mitad - 1] + mat[n-1][mitad]);
		if (laterales != 2 * constante_magica_2) return false;
		if ((mat[mitad - 1][mitad - 1] + mat[mitad][mitad - 1] + mat[mitad - 1][mitad] + mat[mitad][mitad]) != constante_magica_2)
			return false;
	}

	return true;
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		vector<vector<int>> mat(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> mat[i][j];

		int constante_magica = 0;
		for (int i = 0; i < n; ++i) constante_magica += mat[i][0];
		if (!filas_diabolico(n, mat, constante_magica) || !columnas_diabolico(n, mat, constante_magica) || !diagonales_diabolico(n, mat, constante_magica)) {
			cout << "NO\n";
			goto sig_entrada;
		}

		if (esoterico(n, mat, constante_magica)) {
			cout << "ESOTERICO\n";
		}
		else cout << "DIABOLICO\n";

	sig_entrada:
		cin >> n;
	}


	return 0;
}