#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
	int n;
	cin >> n;
	while (n != 0) {
		unordered_map<string, int> votos;
		string candidatura;
		for (int i = 0; i < n; i++) {
			cin >> candidatura;
			if (votos.count(candidatura)) votos[candidatura] += 1;
			else votos[candidatura] = 1;
		}
		string mas_votada;
		int max_votos = 0;
		for (auto votos_cand : votos) {
			if (votos_cand.second > max_votos) {
				max_votos = votos_cand.second;
				mas_votada = votos_cand.first;
			}
			else if (votos_cand.second == max_votos) {
				mas_votada = "EMPATE";
			}
		}
		if (mas_votada == "EMPATE") cout << "EMPATE\n";
		else cout << mas_votada << '\n';



		cin >> n;
	}




	return 0;
}