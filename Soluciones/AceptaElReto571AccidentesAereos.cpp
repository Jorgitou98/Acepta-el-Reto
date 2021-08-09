#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct tAccidente {
	int pos;
	string fecha;
	int muertos;
	string fechaAntMasMuertos = "NO HAY";
};


class comparador{
public:
	comparador() {}
	bool operator() (tAccidente const& accidente1, tAccidente const& accidente2) const{
		return accidente1.muertos > accidente2.muertos;
	}
};

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	while (cin >> n) {
		vector<tAccidente> accidentes(n);
		for (int i = 0; i < n; ++i) {
			cin >> accidentes[i].fecha >> accidentes[i].muertos;
			accidentes[i].pos = i;
		}
		priority_queue<tAccidente,vector<tAccidente>, comparador> cola;
		for (int i = n - 1; i >= 0; --i) {
			while (!cola.empty() && cola.top().muertos < accidentes[i].muertos) {
				accidentes[cola.top().pos].fechaAntMasMuertos = accidentes[i].fecha;
				cola.pop();
			}
			cola.push(accidentes[i]);
		}
		for (tAccidente accidente : accidentes) cout << accidente.fechaAntMasMuertos << '\n';
		cout << "---\n";
	}
}