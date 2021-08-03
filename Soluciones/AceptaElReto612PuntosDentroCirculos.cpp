#include <iostream>
#include <cmath>
using namespace std;


struct tPunto {
	int x, y;
};

double distEuclidea(tPunto punto1, tPunto punto2) {
	return sqrt(pow(punto1.x - punto2.x, 2) + pow(punto1.y - punto2.y, 2));
}

bool perteneceCirculo(tPunto centro, tPunto punto, int radio) {
	return distEuclidea(centro, punto) <= radio;
}


int main(){
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int radio;
	tPunto punto;
	while (cin >> radio >> punto.x >> punto.y) {
		int circulos = 0;
		tPunto centro = { 0,0 };
		while(true){
			if (perteneceCirculo(centro, punto, radio)) circulos++;
			if (radio == 1) break;
			if ((punto.y - centro.y == punto.x - centro.x) || (punto.y - centro.y == -punto.x + centro.x)) break;
			else if ((punto.y - centro.y > punto.x - centro.x) && (punto.y - centro.y > -punto.x + centro.x)) centro.y += radio;
			else if ((punto.y - centro.y < punto.x - centro.x) && (punto.y - centro.y > -punto.x + centro.x)) centro.x += radio;
			else if ((punto.y - centro.y < punto.x - centro.x) && (punto.y - centro.y < -punto.x + centro.x)) centro.y -= radio;
			else centro.x -= radio;
			radio /= 2;
		}
		cout << circulos << '\n';
	}
	return 0;
}