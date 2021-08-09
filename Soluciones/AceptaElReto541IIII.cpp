#include <iostream>
using namespace std;


int mcd(int a, int b) {
	if (a == 0) return b;
	else return mcd(b % a, a);
}

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n1, n2,n3;
	cin >> n1 >> n2 >> n3;
	while (n1 != 0 || n2 != 0 || n3 != 0) {
		int usosPlantilla = mcd(n1, n2);
		usosPlantilla = mcd(usosPlantilla, n3);
		int letrasNecesarias = n1 / usosPlantilla + n2 / usosPlantilla + n3 / usosPlantilla;
		cout << letrasNecesarias << '\n';
		cin >> n1 >> n2 >> n3;
	}
	return 0;
}