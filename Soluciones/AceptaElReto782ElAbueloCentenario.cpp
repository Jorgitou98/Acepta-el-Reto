#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

struct ventana {
	int x1, x2, h;
};

struct gargola {
	int x, h;
};

struct intervalo {
	int x_i, x_d;
	int h;
};

struct infoCoord {
	int x, h;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int ancho, alto, num_obstaculos;
	cin >> ancho >> alto >> num_obstaculos;

	while (ancho != 0 || alto != 0 || num_obstaculos != 0) {
		map<int, int> separaciones;
		separaciones[0] = alto;
		vector<ventana> ventanas;
		unordered_map<int, int> x_gargolas;
		//unordered_set<int>

		char tipo_obstaculo;
		int x, y, ancho_v, alto_v;
		for (int i = 0; i < num_obstaculos; i++) {
			cin >> tipo_obstaculo;
			cin >> x >> y;
			separaciones[x] = alto;
			if (tipo_obstaculo == 'G') {
				if (x_gargolas.count(x))
					x_gargolas[x] = min(x_gargolas[x], alto - y);
				else
					x_gargolas[x] = alto - y;
			}
			else if (tipo_obstaculo == 'V') {
				cin >> ancho_v >> alto_v;
				int x2 = x + ancho_v;
				separaciones[x2] = alto;
				ventanas.push_back({ x, x2, alto - y });
			}
		}

		for (ventana const& v : ventanas) {
			auto it = separaciones.find(v.x1);
			while (it != separaciones.end() && it->first < v.x2) {
				it->second = min(it->second, v.h);
				it++;
			}
		}
		vector<intervalo> intervalos;
		auto it = separaciones.begin();
		while (it != separaciones.end()) {

			int x_i = it->first;
			int h = it->second;
			it++;
			int x_d;
			if (x_gargolas.count(x_i)) {
				int h_gargola = x_gargolas[x_i];
				intervalos.push_back({ x_i, x_i, h_gargola });// intervalo puntual
			}
			if (it == separaciones.end())
				x_d = ancho;
			else
				x_d = it->first;
			intervalos.push_back({ x_i, x_d, h });
		}

		vector<int> x_menor_left(intervalos.size(), 0);
		vector<int> x_menor_right(intervalos.size(), ancho);
		stack<infoCoord> x_left_pila, x_right_pila;

		for (int i = 0; i < intervalos.size(); i++) {
			while (!x_left_pila.empty() && x_left_pila.top().h >= intervalos[i].h)
				x_left_pila.pop();

			if (!x_left_pila.empty()) {
				x_menor_left[i] = x_left_pila.top().x;
			}
			x_left_pila.push({ intervalos[i].x_d, intervalos[i].h });
		}

		for (int i = intervalos.size() - 1; i >= 0; i--) {
			while (!x_right_pila.empty() && x_right_pila.top().h >= intervalos[i].h)
				x_right_pila.pop();

			if (!x_right_pila.empty()) {
				x_menor_right[i] = x_right_pila.top().x;
			}
			x_right_pila.push({ intervalos[i].x_i, intervalos[i].h });
		}

		long long int area_max = 0;

		for (int i = 0; i < intervalos.size(); i++) {
			long long int area = (long long int) (x_menor_right[i] - x_menor_left[i]) * (long long int) intervalos[i].h;
			area_max = max(area_max, area);
		}

		cout << area_max << '\n';

		cin >> ancho >> alto >> num_obstaculos;
	}

	return 0;
}