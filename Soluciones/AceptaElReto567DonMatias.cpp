#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

struct Arista {
	int destino;
	int valor;
};

struct infoRecorrido {
	int suma;
	int color;
	int num_componente;
};

void resuelve_componente(const int num_componente, const int nodo, vector<bool>& marcado, unordered_map<int, infoRecorrido>& componente_suma, vector<vector<int>> const& adj, unordered_map<int, unordered_map<int, int>> const& nota_conjunta, vector<int>& nota_aporta) {
	const int V = adj.size();
	queue<int> cola;
	vector<int> color(V, -1); // -1: no visitado, 0: color 0, 1: color 1
	vector<int> suma(V, 0);
	vector<int> parent(V, -1);
	color[nodo] = 0;
	componente_suma[nodo] = { 0, color[nodo], num_componente };
	cola.push(nodo);

	while (!cola.empty()) {
		int u = cola.front(); cola.pop();
		marcado[u] = true;
		for (auto const& v : adj[u]) {
			if (color[v] == -1) { // Si no ha sido visitado
				color[v] = 1 - color[u]; // Asignar el color opuesto
				suma[v] = nota_conjunta.at(u).at(v) - suma[u];
				componente_suma[v] = { suma[v], color[v], num_componente };
				parent[v] = u;
				cola.push(v);
			}
			else if (v != parent[u] && color[v] == color[u]) {
				// Se ha encontrado un ciclo impar (podemos resolver uno, y por ende toda la componente conexa después)
				int suma_ciclo = (suma[v] + nota_conjunta.at(u).at(v) - suma[u]) / 2LL;
				nota_aporta[v] = suma_ciclo;
			}
		}
	}
}


void resuelve_sistemas(unordered_map<int, infoRecorrido>& componente_suma, vector<vector<int>> const& adj, unordered_map<int, unordered_map<int, int>> const& nota_conjunta, vector<int>& nota_aporta) {
	const int V = adj.size();
	int num_componente = 0;
	vector<bool> marcado(V, false);
	for (int i = 0; i < V; i++) {
		if (!marcado[i]) {
			resuelve_componente(num_componente, i, marcado, componente_suma, adj, nota_conjunta, nota_aporta);
			num_componente++;
		}
	}
}

void propaga_nota(const int nodo, vector<int>& nota_aporta, vector<vector<int>> const& adj, unordered_map<int, unordered_map<int, int>> const& nota_conjunta) {
	for (int vecino : adj[nodo]) {
		if (nota_aporta[vecino] == INT_MIN) {
			// Propagamos la nota al vecino
			nota_aporta[vecino] = nota_conjunta.at(nodo).at(vecino) - nota_aporta[nodo];
			propaga_nota(vecino, nota_aporta, adj, nota_conjunta);
		}
	}
}

void calcula_resto_notas(vector<int>& nota_aporta, vector<vector<int>> const& adj, unordered_map<int, unordered_map<int, int>> const& nota_conjunta) {
	vector<int> notas_individuales = vector<int>(nota_aporta.begin(), nota_aporta.end());
	for (int estudiante = 0; estudiante < notas_individuales.size(); estudiante++) {
		if (notas_individuales[estudiante] != INT_MIN)
			propaga_nota(estudiante, nota_aporta, adj, nota_conjunta);
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int estudiantes, corregidos, entregados;
	cin >> estudiantes >> corregidos >> entregados;
	while (estudiantes != 0 || corregidos != 0 || entregados != 0) {
		vector<int> nota_aporta(estudiantes, INT_MIN);
		vector<vector<int>> adj(estudiantes);
		unordered_map<int, unordered_map<int, int>> nota_conjunta;

		for (int i = 0; i < corregidos; i++) {
			int tipo, estudiante1, estudiante2, calificacion;
			cin >> tipo;
			if (tipo == 1) {
				cin >> estudiante1 >> calificacion;
				nota_aporta[estudiante1 - 1] = calificacion;
			}
			else if (tipo == 2) {
				cin >> estudiante1 >> estudiante2 >> calificacion;
				// Añadir la relación entre los estudiantes
				adj[estudiante1 - 1].push_back(estudiante2 - 1);
				adj[estudiante2 - 1].push_back(estudiante1 - 1);
				nota_conjunta[estudiante1 - 1][estudiante2 - 1] = calificacion;
				nota_conjunta[estudiante2 - 1][estudiante1 - 1] = calificacion;
			}
		}
		unordered_map<int, infoRecorrido> componente_suma;
		resuelve_sistemas(componente_suma, adj, nota_conjunta, nota_aporta);
		calcula_resto_notas(nota_aporta, adj, nota_conjunta);

		for (int i = 0; i < entregados; i++) {
			int tipo, estudiante1, estudiante2;
			cin >> tipo;
			if (tipo == 1) {
				cin >> estudiante1;
				if (nota_aporta[estudiante1 - 1] != INT_MIN)
					cout << nota_aporta[estudiante1 - 1] << '\n';
				else
					cout << "CUIDADO\n";
			}
			else if (tipo == 2) {
				cin >> estudiante1 >> estudiante2;
				if (nota_aporta[estudiante1 - 1] != INT_MIN && nota_aporta[estudiante2 - 1] != INT_MIN) {
					cout << nota_aporta[estudiante1 - 1] + nota_aporta[estudiante2 - 1] << '\n';
				}
				else if (componente_suma.count(estudiante1 - 1) && componente_suma.count(estudiante2 - 1)
					&& componente_suma[estudiante1 - 1].num_componente == componente_suma[estudiante2 - 1].num_componente
					&& componente_suma[estudiante1 - 1].color != componente_suma[estudiante2 - 1].color) {
					cout << componente_suma[estudiante1 - 1].suma + componente_suma[estudiante2 - 1].suma << '\n';
				}
				else {
					cout << "CUIDADO\n";
				}
			}
		}

		cout << "---\n";

		cin >> estudiantes >> corregidos >> entregados;
	}
	return 0;
}