#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct valorPrioridad {
	int valor;
	int prioridad;

};

bool operator >(valorPrioridad const& vp1, valorPrioridad const& vp2) {
	return (vp1.prioridad > vp2.prioridad || (vp1.prioridad == vp2.prioridad) && vp1.valor >= vp2.valor);
}

bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
		valorPrioridad vp;
		priority_queue<valorPrioridad, vector<valorPrioridad>, greater<valorPrioridad>> colaP;
		unordered_map<int, int> prioridadOriginal;

		for (int i = 0; i < n; ++i) {
			cin >> vp.valor >> vp.prioridad;
			colaP.push(vp);
			prioridadOriginal.insert({ vp.valor , vp.prioridad });
	}
		valorPrioridad nuevoElem;
		int k, valor, nuevaPrioridad;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			valor = colaP.top().valor;
			cout << valor << '\n';
			int nuevaPrioridad = colaP.top().prioridad + prioridadOriginal.at(valor);
			colaP.pop();
			colaP.push({ valor, nuevaPrioridad });
		}
		cout << "----\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
