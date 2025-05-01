#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int filas, columnas;
	cin >> filas >> columnas;
	while (filas != 0 && columnas != 0) {
		vector<vector<char>> imagen(filas, vector<char>(columnas));
		unordered_map<char, list<char>> originales_sustituidos_por;
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				cin >> imagen[i][j];
				if (!originales_sustituidos_por.count(imagen[i][j])) {
					originales_sustituidos_por[imagen[i][j]] = { imagen[i][j] };
				}
			}
		}
		int copistas;
		cin >> copistas;
		for (int i = 0; i < copistas; i++) {
			char color_antiguo, color_nuevo;
			cin >> color_antiguo >> color_nuevo;
			if (!originales_sustituidos_por.count(color_antiguo)) continue;
			if (!originales_sustituidos_por.count(color_nuevo)) originales_sustituidos_por[color_nuevo] = {};
			auto last_it = originales_sustituidos_por[color_nuevo].end();
			originales_sustituidos_por[color_nuevo].splice(last_it, originales_sustituidos_por[color_antiguo]);
			originales_sustituidos_por.erase(color_antiguo);
		}

		unordered_map<char, char> color_original_a_color_final;
		for (auto par : originales_sustituidos_por) {
			char color_nuevo = par.first;
			for (char color_original : par.second) {
				color_original_a_color_final[color_original] = color_nuevo;
			}
		}

		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				cout << color_original_a_color_final[imagen[i][j]];
			}
			cout << '\n';
		}

		cin >> filas >> columnas;
	}

	return 0;
}