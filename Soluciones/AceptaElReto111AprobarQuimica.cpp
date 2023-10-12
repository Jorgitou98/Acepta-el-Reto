#include <iostream>
#include <vector>
using namespace std;

int disponibles(string nivel) {
	switch (nivel[1]){
	case 's':
		return 2;
		break;
	case 'p':
		return 6;
		break;
	case 'd':
		return 10;
		break;
	case 'f':
		return 14;
		break;
	default:
		break;
	}
}


int main() {
	vector<string> niveles = { "1s", "2s", "2p", "3s", "3p",
					   "4s", "3d", "4p", "5s", "4d",
					   "5p", "6s", "4f", "5d", "6p",
					   "7s", "5f", "6d", "7p" };
	string elemento;
	cin >> elemento;
	while (elemento != "Exit") {
		int electrones;
		cin >> electrones;
		int i = 0;
		while (electrones > disponibles(niveles[i])) {
			cout << niveles[i] << disponibles(niveles[i]) << ' ';
			electrones -= disponibles(niveles[i]);
			i++;
		}
		cout << niveles[i] << electrones << '\n';


		cin >> elemento;
	}



	return 0;
}