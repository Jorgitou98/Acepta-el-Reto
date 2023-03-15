#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct posiciones {
	bool f, c, d;
};

bool posibleReparto(int f_act, int c_act, int d_act, int f, int c, int d, int n_jug, vector<posiciones>const& jugadores) {
	if (f_act >= f && c_act >= c && d_act >= d) return true;
	int jug_rest = jugadores.size() - n_jug;
	if (jug_rest == 0 || (f - f_act) > jug_rest || (c - c_act) > jug_rest || (d - d_act) > jug_rest) return false;
	bool f_rep, c_rep, d_rep;
	bool pos_f = f_act < f && jugadores[n_jug].f;
	bool pos_c = c_act < c && jugadores[n_jug].c;
	bool pos_d = d_act < d && jugadores[n_jug].d;
	if (pos_f && posibleReparto(f_act + 1, c_act, d_act, f, c, d, n_jug + 1, jugadores)) return true;
	if (pos_c && posibleReparto(f_act, c_act + 1, d_act, f, c, d, n_jug + 1, jugadores)) return true;
	if (pos_d && posibleReparto(f_act, c_act, d_act + 1, f, c, d, n_jug + 1, jugadores)) return true;
	if(!pos_f && !pos_c && !pos_d) return posibleReparto(f_act, c_act, d_act, f, c, d, n_jug + 1, jugadores);
	return false;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int f, c, d;
	cin >> f >> c >> d;
	while (f != 0 || c != 0 || d != 0) {
		int n;
		cin >> n;
		vector<posiciones> jugadores(n, { false, false, false });
		string pos;
		for (int i = 0; i < n; ++i) {
			cin >> pos;
			if (pos.find('F') != std::string::npos) jugadores[i].f = true;
			if (pos.find('C') != std::string::npos) jugadores[i].c = true;
			if (pos.find('D') != std::string::npos) jugadores[i].d = true;
		}
		if (posibleReparto(0, 0, 0, f, c, d, 0, jugadores)) cout << "SI\n";
		else cout << "NO\n";
		cin >> f >> c >> d;
	}
	return 0;
}