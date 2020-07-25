#include <iostream>
#include <cmath>
#include <string>
using namespace std;



const int TAM_MAX = 50;
struct tMatriz{
	int dim;
	int matriz[TAM_MAX][TAM_MAX];
};
void leerMatriz(tMatriz & matriz);
bool diagonalPconUnos(tMatriz const & matriz);
bool restoCeros(tMatriz const & matriz);

int main(){
	tMatriz matriz;

	cin >> matriz.dim;
	while (matriz.dim != 0){
		leerMatriz(matriz);
		bool unos = diagonalPconUnos(matriz);
		bool ceros = restoCeros(matriz);
		if (unos && ceros)  cout << "SI" << endl; 
		else cout << "NO" << endl;
		cin >> matriz.dim;
	}


	return 0;
}

void leerMatriz(tMatriz & matriz){

	for (int i = 0; i < matriz.dim; ++i)
		for (int j = 0; j < matriz.dim; ++j)
			cin >> matriz.matriz[i][j];

}

bool diagonalPconUnos(tMatriz const & matriz){
	bool cumple = true;
	int i = 0;
	while (i < matriz.dim && cumple){
		if (matriz.matriz[i][i] != 1){ cumple = false; }
		++i;
	}
	return cumple;
}

bool restoCeros(tMatriz const & matriz){
	bool cumple = true;
	int i = 0;
	while (i < matriz.dim - 1 && cumple){
		int j = matriz.dim - 1;
		while (j > i && cumple){
			if (matriz.matriz[i][j] != 0 || matriz.matriz[j][i] != 0){ cumple = false; }
			--j;
		}
		++i;
	}


	return cumple;
}
