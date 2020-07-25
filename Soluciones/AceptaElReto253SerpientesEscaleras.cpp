#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


bool resuelveCaso() {
	int n, k, s, e;
	cin >> n >> k >> s >> e;
		if (n == 0 && k == 0 && s == 0 && e == 0)
			return false;
	unordered_map<int, int> serEscaleras;
	int val1, val2;
	int tablero[10000]; 
	for (int i = 0; i < n * n; i++) tablero[i] = n * n;   

	for (int i = 0; i < s + e; i++)
	{
		cin >> val1 >> val2; 
		serEscaleras[val1 - 1] = val2 - 1;
	}

	
	vector<int> dentro, fuera;
	tablero[0] = 0;
	fuera.push_back(0); 
	int ciclo = 0;
	int niSerpNiEscalera;

	while (true){
		ciclo++;
		while (!fuera.empty()){
			int act = fuera.back(); 
			fuera.pop_back(); 
			niSerpNiEscalera = -1;

			for (int j = 0; j < k ; j++)
			{
				int pos = act + 1 + j;
				if (pos == n * n - 1) goto salida;
				else if (tablero[pos] > ciclo)
				{

					if (serEscaleras.count(pos)){
						tablero[serEscaleras[pos]] = ciclo;
						dentro.push_back(serEscaleras[pos]);
					}
					else niSerpNiEscalera = pos;

					tablero[pos] = ciclo;
				}
			}

			if (niSerpNiEscalera != -1) dentro.push_back(niSerpNiEscalera);
		}

			fuera = dentro; 
			while (!dentro.empty()) dentro.pop_back();
	}

	salida: cout << ciclo << '\n';
		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}
