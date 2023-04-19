#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	getchar();
	string linea, apellido, apellidoAnt;
	for (int i = 0; i < num_casos; ++i) {
		getline(cin, linea);
		if (linea == "====") {
			cout << "0 0\n";
			continue;
		}
		int participantes = 1;
		bool es_repetido = false;
		int repetidos = 0;
		stringstream ss_linea(linea);
		getline(ss_linea, apellidoAnt, ',');
		transform(apellidoAnt.begin(), apellidoAnt.end(), apellidoAnt.begin(),
			[](unsigned char c) { return std::tolower(c); });

		getline(cin, linea);
		while (linea != "====") {
			participantes++;
			stringstream ss_linea(linea);
			getline(ss_linea, apellido, ',');
			transform(apellido.begin(), apellido.end(), apellido.begin(),
				[](unsigned char c) { return std::tolower(c); });
			if (apellido == apellidoAnt) {
				if(es_repetido) repetidos++;
				else repetidos +=2;
				es_repetido = true;
			}
			else es_repetido = false;
			apellidoAnt = apellido;
			getline(cin, linea);
		}
		cout << participantes << ' ' << repetidos << '\n';
	}

	return 0;
}