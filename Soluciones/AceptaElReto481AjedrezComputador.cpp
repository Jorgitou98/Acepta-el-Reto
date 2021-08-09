#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int fila, columna;
	cin >> fila >> columna;
	while (fila != 0 || columna != 0) {
		char filaLetra = 'i' - fila;
		cout << filaLetra << columna << '\n';
		cin >> fila >> columna;
	}

	return 0;
}