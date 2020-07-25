#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool resuelveCaso() {


	string categoria;
	cin >> categoria;


	if (categoria == "FIN")
		return false;


	unordered_map<string, pair<int, int>> mapa; // El segundo int del par son los partidos jugados
	string equipoLocal, equipoVisitante;
	int setsLocal, setsVisitante, puntosLocal, puntosVisitante;
	cin >> equipoLocal;


	while (equipoLocal != "FIN"){
		cin >> setsLocal >> equipoVisitante >> setsVisitante;
		if (setsLocal > setsVisitante) {
			puntosLocal = 2;
			puntosVisitante = 1;
		}
		else{
			puntosLocal = 1;
			puntosVisitante = 2;
		}

		if (mapa.count(equipoLocal) == 0){
			mapa.insert({ equipoLocal, { puntosLocal, 1 } });
		}
		else{
			mapa.at(equipoLocal).first += puntosLocal;
			mapa.at(equipoLocal).second++;
		}

		if (mapa.count(equipoVisitante) == 0){
			mapa.insert({ equipoVisitante, { puntosVisitante, 1 } });
		}
		else{
			mapa.at(equipoVisitante).first += puntosVisitante;
			mapa.at(equipoVisitante).second++;
		}
		cin >> equipoLocal;
	}
	bool empate = false;
	pair <string, pair<int, int>> max;
	int partidosTotalesCadaEquipo = (mapa.size() - 1) * 2;
	int doblePartidosSinJugar = 0; // Cada partido sin jugar lo cuento 2 veces. Una por cada equipo que lo tendría que disputar
	for (auto par : mapa){ 
		if (par.second.first == max.second.first) empate = true;
		else if (par.second.first > max.second.first) {
			max = par;
			empate = false;
		}
		doblePartidosSinJugar += partidosTotalesCadaEquipo - par.second.second;
	}
	if (empate) cout << "EMPATE ";
	else cout << max.first << " ";
	cout << doblePartidosSinJugar / 2 << '\n';

		return true;
}
int main() {
  	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
