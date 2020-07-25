#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const long long int TAM_MAX = 1000000;
typedef char tArray[TAM_MAX];



void casos();

int main(){
	casos();

	return 0;
}


void casos(){
	tArray array;
	char letra, inicial;
	bool resultadosacado;
	int puntosA, i, puntosB;
	i = 1;
	resultadosacado = false;
	array[0] = 'A';
	puntosB = 0;
	puntosA = 0;
	
	cin >> inicial;
	while (inicial != 'F'){
		letra = inicial;
		while (letra != 'F'){
			array[i] = letra;
			if (letra == 'A' && array[i - 1] == 'A'){ puntosA++; }
			if (letra == 'B' && array[i - 1] == 'B'){ puntosB++; }
			if ((puntosA >= 9 && puntosA > puntosB + 1) || (puntosB >= 9 && puntosB > puntosA + 1)){
				cout << puntosA << "-" << puntosB;
				resultadosacado = true;
				puntosA = 0;
				puntosB = 0;
			}
			cin >> letra;
			if (resultadosacado && letra != 'F'){
				cout << " ";
				resultadosacado = false;
			}
			if (!resultadosacado && letra == 'F'){
				cout << puntosA << "-" << puntosB;
				puntosA = 0;
				puntosB = 0;
			}
			i++;
		}
	cout << endl;
		i = 1;
		array[0] = 'A';
		cin >> inicial;
		resultadosacado = false;
	}
}
