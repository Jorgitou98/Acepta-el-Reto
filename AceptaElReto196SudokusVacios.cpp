#include <iostream>
#include <cmath>
#include <string>
using namespace std;



const int TAM = 9;
typedef char tMatriz[TAM][TAM];
void leerMatriz(tMatriz matriz, unsigned int &dados);
bool Simetria(tMatriz const matriz);
int main(){
	unsigned int dados, casos;
	tMatriz matriz;
	bool simetria;
	cin >> casos;
	for (int i = 0; i < casos; i++){
		leerMatriz(matriz, dados);
		bool simetria = Simetria(matriz);
		if (dados > 32 || !simetria) cout << "NO" << "\n";
		else cout << "SI" << "\n";
	}

	return 0;
}

void leerMatriz(tMatriz matriz, unsigned int & dados){
	dados = 0;
	for (unsigned int i = 0; i < TAM; ++i)
		for (unsigned int j = 0; j < TAM; ++j){
			cin >> matriz[i][j];
			if (matriz[i][j] != '-') ++dados;
		}
}

bool Simetria(tMatriz const matriz){
	bool simetria = true;
	unsigned int i = 0;
	while (simetria && i < TAM){
		int j = 0;
		while (simetria && j < TAM){
			if (matriz[i][j] != '-' && matriz[8 - i][8 - j] == '-') {
				simetria = false; 
			}
			++j;
		}
		++i;
	}
	return simetria;
}
