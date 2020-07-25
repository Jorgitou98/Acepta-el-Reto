#include <iostream>
#include <cmath>
#include <string>
using namespace std;

typedef char Fijo[20];

int main(){
	int i;
	char conjugacion;
	Fijo almacen;
	string verbo;
	cin >> verbo;
	cin >> conjugacion;
	while (conjugacion != 'T'){
		for (i = 0; i < verbo.size(); i++){
			almacen[i] = verbo[i];
		}

		if (conjugacion == 'F'){
			cout << "yo ";
			for (i = 0; i < verbo.size(); i++){
				cout << almacen[i];
			}
			cout << "e" << endl;
			cout << "tu ";
			for (i = 0; i < verbo.size(); i++){
				cout << almacen[i];
			}
			cout << "as" << endl;
			cout << "el ";
			for (i = 0; i < verbo.size(); i++){
				cout << almacen[i];
			}
			cout << "a" << endl;
			cout << "nosotros ";
			for (i = 0; i < verbo.size(); i++){
				cout << almacen[i];
			}
			cout << "emos" << endl;
			cout << "vosotros ";
			for (i = 0; i < verbo.size(); i++){
				cout << almacen[i];
			}
			cout << "eis" << endl;
			cout << "ellos ";
			for (i = 0; i < verbo.size(); i++){
				cout << almacen[i];
			}
			cout << "an" << endl;

		}
		if (conjugacion == 'A' && almacen[verbo.size() - 2] != 'i'){
			cout << "yo ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "o" << endl;
			cout << "tu ";
			for (i = 0; i < verbo.size() - 1; i++){
				cout << almacen[i];
			}
			cout << "s" << endl;
			cout << "el ";
			for (i = 0; i < verbo.size() - 1; i++){
				cout << almacen[i];
			}
			cout << endl;
			cout << "nosotros ";
			for (i = 0; i < verbo.size() - 1; i++){
				cout << almacen[i];
			}
			cout << "mos" << endl;
			cout << "vosotros ";
			for (i = 0; i < verbo.size() - 1; i++){
				cout << almacen[i];
			}
			cout << "is" << endl;
			cout << "ellos ";
			for (i = 0; i < verbo.size() - 1; i++){
				cout << almacen[i];
			}
			cout << "n" << endl;
		}
		else if (conjugacion == 'A' && almacen[verbo.size() - 2] == 'i'){
			cout << "yo ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "o" << endl;
			cout << "tu ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "es" << endl;
			cout << "el ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "e" << endl;
			cout << "nosotros ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "imos" << endl;
			cout << "vosotros ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "is" << endl;
			cout << "ellos ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "en" << endl;
		}
		if (conjugacion == 'P' && almacen[verbo.size() - 2] != 'a'){
			cout << "yo ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "i" << endl;
			cout << "tu ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "iste" << endl;
			cout << "el ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "io" << endl;
			cout << "nosotros ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "imos" << endl;
			cout << "vosotros ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "isteis" << endl;
			cout << "ellos ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "ieron" << endl;
		}
		else if (conjugacion == 'P' && almacen[verbo.size() - 2] == 'a'){
			cout << "yo ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "e" << endl;
			cout << "tu ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "aste" << endl;
			cout << "el ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "o" << endl;
			cout << "nosotros ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "amos" << endl;
			cout << "vosotros ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "asteis" << endl;
			cout << "ellos ";
			for (i = 0; i < verbo.size() - 2; i++){
				cout << almacen[i];
			}
			cout << "aron" << endl;
		}
		cin >> verbo;
		cin >> conjugacion;
	}
	return 0;

}
