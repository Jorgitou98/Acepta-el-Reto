#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
bool resuelveCaso() {
	int N;
	cin >> N;
	if (!std::cin)
		return false;
	int K;
	cin >> K;
	unordered_map<int, int> mapaExamenesEncontrados;
	unordered_map<int, int> mapaKRecordados;
	int examen;
	int copiones = 0, copionesPillados = 0;
	vector <int> vExamenes;
	for (int i = 0; i < N; ++i){
		cin >> examen;
		vExamenes.push_back(examen);
	}

	int valoresEnMapaK = 0;
	for (int i = 0; i < N; ++i){
		examen = vExamenes[i];
		if (!mapaExamenesEncontrados.count(examen)){
			mapaExamenesEncontrados.insert({ examen, 1 });
		}
		else copiones++;

		if (mapaKRecordados.count(examen)) copionesPillados++;
		
		if (valoresEnMapaK < K){
			valoresEnMapaK++;
		}
		else{ // Al menos K recorridos
			mapaKRecordados.at(vExamenes[i - K])--;
			if (mapaKRecordados.at(vExamenes[i - K]) == 0) mapaKRecordados.erase(vExamenes[i - K]);
		}
		if (!mapaKRecordados.count(examen)){
			mapaKRecordados.insert({ examen, 1 });
		}
		else{
			mapaKRecordados.at(examen)++;
		}
	}

	cout << copiones << " " << copionesPillados << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
