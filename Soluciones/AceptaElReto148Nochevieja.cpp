#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int Medianoche = 00;

int main(){
	int horas, min, minrest, minh, mint;
	char puntos;
	cin >> horas >> puntos >> min;
	while (horas != Medianoche || min != Medianoche){
		minrest = 60 - min;
		minh = (23 - horas) * 60;
		mint = minrest + minh;
		cout << mint<< endl;
		cin >> horas >> puntos >> min;
	}



	return 0;
}
