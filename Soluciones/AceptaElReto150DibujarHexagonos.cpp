#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void Hexagono1(int n, char car);

int main(){
	int n;
	char car;
	cin >> n >> car;
	while (n != 0 || car != '0'){
		Hexagono1(n, car);
		cin >> n >> car;
	}

	return 0;
}


void Hexagono1(int n, char car){
	int i, m, aux, esp, f, aux2;
	aux = 0;
	esp = 1;
	m = 0;
	for (i = 0; i < n; i++){
		aux = 0;
		for (f = 0; f < (n- esp); f++){
			cout << " ";
		}

		while (aux < n + m){
			cout << car;
			aux++;
		}
		cout << endl;
		m = m + 2;
		esp++;
		}
	aux2 = 0;
	esp = 1;
	m = 2;
	for (i = 0; i < (n-1); i++){

		for (f = 0; f < esp; f++){
			cout << " ";
		}

		while (aux2 < aux - m){
			cout << car;
			aux2++;
		}
		cout << endl;
		aux2 = 0;
		m = m + 2;
		esp++;
	}


}
