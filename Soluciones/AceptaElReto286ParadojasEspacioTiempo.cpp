#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int number_rep(string const& fecha) {
	int rep = 0;
	rep += (fecha[0] - '0') * 10 + fecha[1] - '0';
	rep += 32 * ((fecha[3] - '0') * 10 + fecha[4] - '0');
	rep += 416 * ((fecha[6] - '0') * 1000 + (fecha[7] - '0') * 100 + (fecha[8] - '0') * 10 + fecha[9] - '0');
	return rep;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_viajes;
	cin >> num_viajes;
	while (num_viajes != 0) {
		string fecha;
		vector<int> ini_v(num_viajes + 1);
		vector<int> fin_v(num_viajes + 1);
		ini_v[0] = number_rep("12/06/1968");
		for (int i = 0; i < num_viajes; ++i) {
			cin >> fecha;
			fin_v[i] = number_rep(fecha);
			cin >> fecha;
			ini_v[i + 1] = number_rep(fecha);
		}
		fin_v[num_viajes] = INT_MAX;

		sort(ini_v.begin(), ini_v.end());
		sort(fin_v.begin(), fin_v.end());

		int num_consultas;
		cin >> num_consultas;
		for (int i = 0; i < num_consultas; ++i) {
			cin >> fecha;
			int fecha_int = number_rep(fecha);
			auto up = upper_bound(ini_v.begin(), ini_v.end(), fecha_int);
			auto low = lower_bound(fin_v.begin(), fin_v.end(), fecha_int);
			int versiones_simultaneas = (up - ini_v.begin()) - (low - fin_v.begin());
			cout << versiones_simultaneas << '\n';
		}
		cout << "----\n";
		cin >> num_viajes;
	}

	return 0;
}