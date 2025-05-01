#include <iostream>
#include <vector>
using namespace std;

int simula_copas_llenas(int num_botellas, int contenido_botella, int niveles, int capacidad_par, int capacidad_impar) {
	vector<vector<long long int>> copas(niveles, vector<long long int>(niveles, 0));
	int copas_llenas = 0;
	long long int scale = 1LL << niveles; // escala para evitar problemas de precisión
	copas[0][0] += num_botellas * contenido_botella * scale;
	for (int i = 0; i < niveles; i++) {
		bool continuar = false;
		for (int j = 0; j < (i + 1); j++) {
			long long int capacidad = ((i + 1) % 2 == 0 ? (long long int)capacidad_par : (long long int)capacidad_impar) * scale;
			if (copas[i][j] >= capacidad) {
				copas_llenas++;
				long long int recibe_hijos = copas[i][j] - capacidad;
				copas[i][j] = capacidad;
				if ((i + 1) < niveles) {
					continuar = true;
					copas[i + 1][j] += recibe_hijos / 2;
					copas[i + 1][j + 1] += recibe_hijos / 2;
				}
			}
		}
		if (!continuar) {
			break; // Si no hay más copas que llenar, salimos del bucle
		}
	}
	return copas_llenas;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int niveles, capacidad_impar, capacidad_par, contenido_botella, invitados;
	while (cin >> niveles >> capacidad_impar >> capacidad_par >> contenido_botella >> invitados) {

		// Búsqueda binaria en el espacio de botellas vertidas
		int botellas_left = 0, botellas_right = 16;
		for (int i = 0; i < niveles; i++) {
			botellas_right *= 2;
		}


		int botellas_sol = botellas_right;
		while (botellas_left <= botellas_right) {
			int num_botellas = (botellas_left + botellas_right) / 2;
			int copas_llenas = simula_copas_llenas(num_botellas, contenido_botella, niveles, capacidad_par, capacidad_impar);
			if (copas_llenas >= invitados) {
				botellas_right = num_botellas - 1;
				botellas_sol = num_botellas;
			}
			else botellas_left = num_botellas + 1;
		}
		cout << botellas_sol << '\n';
	}
	return 0;
}