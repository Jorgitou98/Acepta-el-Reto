#include <iostream>
#include <vector>
using namespace std;


bool gana_partida(int puntuacion, int num, int turno, vector<vector<vector<int>>>& gana_dp) {
	if (puntuacion >= 1000 && turno == 1) return false;
	if (puntuacion >= 1000 && turno == 0) return true;
	if (gana_dp[puntuacion][num][turno] == 0) return false;
	else if (gana_dp[puntuacion][num][turno] == 1) return true;

	if (turno == 0) {
		for (int i = 1; i <= 6; ++i) {
			if (i == num || i + num == 7) continue;
			if (gana_partida(puntuacion + i, i, (turno + 1) % 2, gana_dp)) {
				gana_dp[puntuacion][num][turno] = 1;
				return true;
			}
		}
		gana_dp[puntuacion][num][turno] = 0;
		return false;
	}
	else {
		for (int i = 1; i <= 6; ++i) {
			if (i == num || i + num == 7) continue;
			if (!gana_partida(puntuacion + i, i, (turno + 1) % 2, gana_dp)) {
				gana_dp[puntuacion][num][turno] = 0;
				return false;
			}
		}
		gana_dp[puntuacion][num][turno] = 1;
		return true;
	}


}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	vector<vector<vector<int>>> gana_dp(1000, vector<vector<int>>(7, vector<int>(2, -1)));
	for (int caso = 0; caso < num_casos; ++caso) {
		int puntuacion;
		int num;
		cin >> puntuacion >> num;
		if (gana_partida(puntuacion, num, 0, gana_dp)) cout << "GANA\n";
		else cout << "PIERDE\n";
	}
	
	return 0;
}