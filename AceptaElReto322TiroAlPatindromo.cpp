#include <iostream>
#include <string>
#include <algorithm>
#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>

template <typename Object>
class Matriz {
public:
	// crea una matriz con fils filas y cols columnas,
	// con todas sus celdas inicializadas al valor e
	Matriz(int fils, int cols, Object e = Object()) : datos(fils, std::vector<Object>(cols, e)) {}

	// operadores para poder utilizar notación M[i][j]
	std::vector<Object> const& operator[](int f) const {
		return datos[f];
	}
	std::vector<Object> & operator[](int f) {
		return datos[f];
	}

	// métodos que lanzan una excepción si la posición no existe
	Object const& at(int f, int c) const {
		return datos.at(f).at(c);
	}
	Object & at(int f, int c) { // este método da problemas cuando Object == bool
		return datos.at(f).at(c);
	}

	int numfils() const { return datos.size(); }
	int numcols() const { return numfils() > 0 ? datos[0].size() : 0; }

	bool posCorrecta(int f, int c) const {
		return 0 <= f && f < numfils() && 0 <= c && c < numcols();
	}

private:
	std::vector<std::vector<Object>> datos;
};

#endif
#include <vector>
using namespace std;

string patindromo(string letras) {
	size_t n = letras.size() - 1;

	Matriz<int> pat(n + 1, n + 1, 0);

	for (int i = 1; i <= n - 1; i++)
	{
		pat[i][i] = 1;
	}

	for (size_t d = 1; d <= n - 1; d++)
	{
		for (size_t i = 1; i <= n - d; i++)
		{
			size_t j = i + d; // Comparaciones cada 1, cada 2, cada 3 etc..
			if (letras[i] == letras[j]) { // Coiniden las letras e la comparacion, ensadwicho entre ella el palindromo de dentro
				pat[i][j] = 2 + pat[i + 1][j - 1]; // Lo he rellenado anteriormente
			}
			else {
				pat[i][j] = max(pat[i + 1][j], pat[i][j - 1]); // 
			}
		}
	}

	int longPatindromo = pat[1][n];
	string patindromo(longPatindromo + 1, ' ');
	int p = 1;
	int q = n;
	int v = 1;
	int w = longPatindromo;
	while (longPatindromo > 0) {
		if (letras[p] == letras[q]) {
			patindromo[v] = letras[p];
			patindromo[w] = letras[q];
			longPatindromo -= 2;
			v++;
			w--;
			p++;
			q--;
		}
		else if (longPatindromo == 1) {
			patindromo[v] = letras[q];
			longPatindromo--;
		}
		else {
			if (pat[p][q - 1] > pat[p + 1][q]) {
				q--;
			}
			else {
				p++;
			}
		}
	}
	patindromo = patindromo.substr(1, patindromo.size() - 1);
	return patindromo;
}

bool resuelveCaso() {

	string palabra;
	cin >> palabra;

	if (!cin)
		return false;

	string sol = "";
	if (palabra.size() == 1) {
		cout << palabra << endl;
	}
	else {
		string letras = " " + palabra;
		size_t n = letras.size() - 1;

		Matriz<int> pat(n + 1, n + 1, 0);

		for (int i = 1; i <= n - 1; i++)
		{
			pat[i][i] = 1;
		}

		for (size_t d = 1; d <= n - 1; d++)
		{
			for (size_t i = 1; i <= n - d; i++)
			{
				size_t j = i + d; // Comparaciones cada 1, cada 2, cada 3 etc..
				if (letras[i] == letras[j]) { // Coiniden las letras e la comparacion, ensadwicho entre ella el palindromo de dentro
					pat[i][j] = 2 + pat[i + 1][j - 1]; // Lo he rellenado anteriormente
				}
				else {
					pat[i][j] = max(pat[i + 1][j], pat[i][j - 1]); // 
				}
			}
		}

		int longPatindromo = pat[1][n];
		string patindromo(longPatindromo + 1, ' ');
		int p = 1;
		int q = n;
		int v = 1;
		int w = longPatindromo;
		while (longPatindromo > 0) {
			if (letras[p] == letras[q]) {
				patindromo[v] = letras[p];
				patindromo[w] = letras[q];
				longPatindromo -= 2;
				v++;
				w--;
				p++;
				q--;
			}
			else if (longPatindromo == 1) {
				patindromo[v] = letras[q];
				longPatindromo--;
			}
			else {
				if (pat[p][q - 1] > pat[p + 1][q]) {
					q--;
				}
				else {
					p++;
				}
			}
		}
		patindromo = patindromo.substr(1, patindromo.size() - 1);
		cout << patindromo << endl;
	}

	return true;
}


int main() {
  	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
