#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

struct tApariciones {
	int numCara = 0;
	int numCarasMenores = 0;
	tApariciones() {}
	tApariciones(int numCara, int numCarasMenores) {
		this->numCara = numCara;
		this->numCarasMenores = numCarasMenores;
	}
};

map<int, tApariciones> ordenaMapa(unordered_map<int, tApariciones>& mapaAntiguo) {
	map<int, tApariciones> mapaNuevo;
	for (auto elem : mapaAntiguo) {
		mapaNuevo.insert(elem);
	}
	mapaAntiguo.clear();
	return mapaNuevo;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
		unordered_map <int, tApariciones> carasDado1;
		int valor;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			if (!carasDado1.count(valor)) carasDado1[valor] = tApariciones( 1,0 );
			else carasDado1[valor].numCara++;
		}
		unordered_map <int, tApariciones> carasDado2;
		for (int i = 0; i < n; ++i) {
			cin >> valor;
			if (!carasDado2.count(valor)) carasDado2[valor] = tApariciones(1, 0);
			else carasDado2[valor].numCara++;
		}
		map <int, tApariciones> carasDado2Ord = ordenaMapa(carasDado2);
		int suma = 0;
		for (auto it = carasDado2Ord.begin(); it != carasDado2Ord.end(); ++it) {
			it->second.numCarasMenores = suma;
			suma += it->second.numCara;
		}
		long long int casosGana1 = 0, casosEmpata1= 0, casosPierde1 = 0;
		for (auto it = carasDado1.begin(); it != carasDado1.end(); ++it) {
			auto superior = carasDado2Ord.lower_bound(it->first);
			if (superior == carasDado2Ord.end()) {
				casosGana1 += (long long int) it->second.numCara * n;
				continue;
			}
			casosGana1 += (long long int) it->second.numCara * (long long int) superior->second.numCarasMenores;
			if (it->first == superior->first) casosEmpata1 += (long long int) it->second.numCara * (long long int) superior->second.numCara;
		}
		casosPierde1 = (long long int) n * (long long int) n - casosGana1 - casosEmpata1;
		if (casosGana1 > casosPierde1) cout << "PRIMERO\n";
		else if(casosGana1 < casosPierde1) cout << "SEGUNDO\n";
		else cout << "NO HAY DIFERENCIA\n";
		cin >> n;
	}


	return 0;
}