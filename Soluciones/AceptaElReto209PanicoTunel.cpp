#include <iostream>
#include <vector>
using namespace std;

int main() {
	string descripcion;
	while (cin >> descripcion) {
		int n = descripcion.size();

		vector<int> info_pos(n);
		int tel = -1;
		for (int i = 0; i < n; ++i) {
			if (descripcion[i] == 'T') tel = i;
			info_pos[i] = tel;
		}
		tel = n;
		for (int i = descripcion.size()-1; i >= 0; --i) {
			// -2 significa que la salida es "AQUI"
			if (descripcion[i] == 'T') {
				info_pos[i] = -2;
				tel = i;
			}
			else if (i - info_pos[i] == tel - i) {
				// -3 significa "PENINSULA" y -4 significa "ISLAS"
				if (n % 2 == 1 && i == n / 2)
					info_pos[i] = -3;
				else if (i < n / 2)
					info_pos[i] = -3;
				else info_pos[i] = -4;
			}
			else if (i - info_pos[i] < tel - i) info_pos[i] = -3;
			else info_pos[i] = -4;
			
		}
		int consultas;
		cin >> consultas;
		int pos;
		for (int i = 0; i < consultas; ++i) {
			cin >> pos;
			pos--;
			if (info_pos[pos] == -2) cout << "AQUI\n";
			else if (info_pos[pos] == -3) cout << "PENINSULA\n";
			else if (info_pos[pos] == -4) cout << "ISLAS\n";
		}

	}


	return 0;
}