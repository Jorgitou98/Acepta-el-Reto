#include <iostream>
#include <string>
using namespace std;

int main() {
	string mensaje;
	while(true) {
		int desp = 'p' - getchar();
		getline(cin, mensaje);
		int vocales = 0;
		for (int i = 0; i < mensaje.size(); ++i) {
			int val_char = mensaje[i];
			if (val_char >= 'a' && val_char <= 'z') {
				val_char += desp;
				if (val_char > 'z') val_char = val_char - 'z' + 'a' - 1;
				if (val_char < 'a') val_char = val_char - 'a' + 'z' + 1;
				if (val_char == 'a' || val_char == 'e' || val_char == 'i' || val_char == 'o' || val_char == 'u')
					vocales++;
			}
			if (val_char >= 'A' && val_char <= 'Z') {
				val_char += desp;
				if (val_char > 'Z') val_char = val_char - 'Z' + 'A' - 1;
				if (val_char < 'A') val_char = val_char - 'A' + 'Z' + 1;
				if (val_char == 'A' || val_char == 'E' || val_char == 'I' || val_char == 'O' || val_char == 'U')
					vocales++;
			}
			mensaje[i] = val_char;
		}
		if (mensaje == "FIN") break;
		cout << vocales << '\n';
	}



	return 0;
}