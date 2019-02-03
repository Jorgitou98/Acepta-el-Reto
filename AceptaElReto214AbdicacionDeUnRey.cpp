#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool resuelveCaso() {
	int reyesDinastia;
	cin >> reyesDinastia;
	if (reyesDinastia == 0)
		return false;
	string nombreRey;
	unordered_map <string, int> mapaReyes;
	for (int i = 0; i < reyesDinastia; ++i){
		cin >> nombreRey;
		if (mapaReyes.count(nombreRey) == 0) mapaReyes.insert({ nombreRey, 1 });
		else mapaReyes.at(nombreRey)++;
	}
	int sucesores;
	cin >> sucesores;
	string sucesor;
	for (int i = 0; i < sucesores; ++i){
		cin >> sucesor;
		if (mapaReyes.count(sucesor) == 0) {
			mapaReyes.insert({ sucesor, 1 });
			cout << 1;
		}
		else{
			mapaReyes.at(sucesor)++;
			cout << mapaReyes.at(sucesor);
		}
		cout << '\n';
	}
	cout << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
