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
bool Triangular(tMatriz const& matriz);

int main(){
	tMatriz matriz;

	cin >> matriz.dim;
	while (matriz.dim != 0){
		leerMatriz(matriz);
		bool triangular = Triangular(matriz);
		if (triangular) cout << "SI" << endl;
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

bool Triangular(tMatriz const& matriz){
	bool cumplesup = true, cumpleinf = true, cumple = true;
	int i = 0;
	while (cumplesup && i < matriz.dim){
		int j = i + 1;
		while (cumplesup && j < matriz.dim){
			if (matriz.matriz[i][j] != 0)  cumplesup = false;
			++j;
		}
		++i;
	}
	if (!cumplesup){
		int i = 0;
		while (cumpleinf && i < matriz.dim){
			int j = i + 1;
			while (cumpleinf && j < matriz.dim){
				if (matriz.matriz[j][i] != 0)  cumpleinf = false;
				++j;
			}
			++i;
		}
	}

	cumple = cumpleinf;


	return cumple;
}
