#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct equipo {
	int num_equipo;
	int puntos;
	int goles_favor;
	int goles_contra;

	bool operator >(equipo const& equipo2) const {
		return this->puntos > equipo2.puntos ||
			this->puntos == equipo2.puntos &&
			(this->goles_favor - this->goles_contra) > (equipo2.goles_favor - equipo2.goles_contra) ||
			this->puntos == equipo2.puntos &&
			(this->goles_favor - this->goles_contra) == (equipo2.goles_favor - equipo2.goles_contra) &&
			this->goles_favor > equipo2.goles_favor;
	}

	bool operator ==(equipo const& equipo2) const {
		return this->puntos == equipo2.puntos &&
			this->goles_favor == equipo2.goles_favor &&
			this->goles_contra == equipo2.goles_contra;
	}
};

int main() {
	int n, q;
	while (cin >> n >> q) {
		vector<equipo> equipos(n);
		for (int i = 0; i < n; i++) equipos[i] = { i + 1, 0, 0, 0 };
		int equipo1, equipo2;
		int goles1, goles2;
		for (int i = 0; i < n * (n - 1) / 2; i++) {
			cin >> equipo1 >> equipo2 >> goles1 >> goles2;
			equipos[equipo1 - 1].goles_favor += goles1;
			equipos[equipo1 - 1].goles_contra += goles2;
			equipos[equipo2 - 1].goles_favor += goles2;
			equipos[equipo2 - 1].goles_contra += goles1;
			if (goles1 > goles2) equipos[equipo1 - 1].puntos += 3;
			else if (goles1 == goles2) {
				equipos[equipo1 - 1].puntos += 1;
				equipos[equipo2 - 1].puntos += 1;
			}
			else equipos[equipo2 - 1].puntos += 3;
		}
		sort(equipos.begin(), equipos.end(), greater<equipo>());

		int i = 0;
		bool empate = false;
		while (!empate && i < q) {
			if (i + 1 < n && equipos[i] == equipos[i + 1]) empate = true;
			i++;
		}
		if (empate) cout << "EMPATE\n";
		else {
			for (int i = 0; i < q-1; i++) cout << equipos[i].num_equipo << ' ';
			cout << equipos[q-1].num_equipo << '\n';
		}
	}

	return 0;
}