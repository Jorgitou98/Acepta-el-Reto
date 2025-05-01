#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Semaforo {
	int distancia;
	int p_cerrado, p_abierto;
};


bool simula_semaforos(float velocidad, vector<Semaforo> const& semaforos) {
	for (int i = 0; i < semaforos.size(); i++) {
		float tiempo = (float)semaforos[i].distancia / velocidad;
		float mod_cerrado = fmod(tiempo, (float)(semaforos[i].p_cerrado + semaforos[i].p_abierto));
		if (mod_cerrado < ((float)semaforos[i].p_cerrado - 0.01) && mod_cerrado > 0.01) {
			return false;
		}
	}
	return true;
}

vector<int> posibles_tiempos(int v_max, int distancia, vector<Semaforo> const& semaforos) {
	vector<int> t_posibles;
	float v_min = 0.1;
	int abierto_ult = semaforos.back().p_abierto;
	int cerrado_ult = semaforos.back().p_cerrado;
	int m = 0;
	while (true) {
		int tiempo_abre = cerrado_ult + m * (cerrado_ult + abierto_ult);
		int tiempo_cierra = (m + 1) * (cerrado_ult + abierto_ult);
		float v_abre = (float)distancia / (float)tiempo_abre;
		float v_cierra = (float)distancia / (float)tiempo_cierra;
		if (v_abre < v_min) break;
		if (v_abre <= v_max) t_posibles.push_back(tiempo_abre);
		if (v_cierra < v_min) break;
		if (v_cierra <= v_max) t_posibles.push_back(tiempo_cierra);
		m++;
	}
	return t_posibles;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int num_sem, v_max;
	cin >> num_sem >> v_max;
	while (num_sem != 0 || v_max != 0) {
		vector<Semaforo> semaforos(num_sem);
		int distancia = 0;
		bool siempre_cerrado = false;
		for (int i = 0; i < num_sem; i++) {
			int my_distancia;
			cin >> my_distancia;
			distancia += my_distancia;
			semaforos[i].distancia = distancia;
			cin >> semaforos[i].p_cerrado >> semaforos[i].p_abierto;
			if (semaforos[i].p_abierto == 0) siempre_cerrado = true;
		}
		if (siempre_cerrado) {
			cout << "IMPOSIBLE\n";
			cin >> num_sem >> v_max;
			continue;
		}

		vector<int> t_posibles = posibles_tiempos(v_max, distancia, semaforos);

		bool encontrado = false;
		int i = 0;
		while (i < t_posibles.size() && !encontrado) {
			float velocidad = (float)distancia / (float)t_posibles[i];
			if (simula_semaforos(velocidad, semaforos)) {
				encontrado = true;
				cout << t_posibles[i] << '\n';
			}
			i++;
		}
		if (!encontrado) {
			cout << "IMPOSIBLE\n";
		}

		cin >> num_sem >> v_max;
	}

	return 0;
}