#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
bool resuelveCaso() {
	int ejercicios;
	cin >> ejercicios;
	if (ejercicios == 0)
		return false;
	map <string, int> mapaNotaAlumnos;
	string nombre, calificacion;
	int puntos;
	char aux;
	aux = getchar();
	for (int i = 0; i < ejercicios; ++i){
		getline(cin, nombre);
		getline(cin, calificacion);

		if (calificacion == "CORRECTO") puntos = 1;
		else puntos = -1;

		if (!mapaNotaAlumnos.count(nombre)){
			mapaNotaAlumnos.insert({ nombre, puntos });
		}
		else{
			mapaNotaAlumnos.at(nombre) += puntos;
		}
	}
	for (auto alumno : mapaNotaAlumnos){
		if (alumno.second != 0) cout << alumno.first << ", " << alumno.second << '\n';
	}
	cout << "---\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
