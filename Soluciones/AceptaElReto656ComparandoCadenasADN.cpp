#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int get_idx(char c) {
	switch (c) {
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	case '-': return 4;
	}
	return 4;
}

struct trieNodoInterno {
	trieNodoInterno* children[25];
	int num;
	int term;
	trieNodoInterno() : num(0), term(0) {
		for (int i = 0; i < 25; i++) {
			children[i] = nullptr;
		}
	}
	~trieNodoInterno() {
		for (int i = 0; i < 25; i++) {
			if (children[i] != nullptr) {
				delete children[i];
			}
		}
	}
	void inserta_cadena(string const& cad, int pos) {
		this->num++;
		if (pos < 0) {
			this->term++;
			return;
		}
		char nucleotido1 = cad[pos];
		char nucleotido2 = cad[cad.size() - 1 - pos];
		int index = get_idx(nucleotido1) * 5 + get_idx(nucleotido2);
		if (this->children[index] == nullptr)
			this->children[index] = new trieNodoInterno();
		this->children[index]->inserta_cadena(cad, pos - 1);
	}

	int busca_repetidos(string const& cad, int pos) {
		if (pos < 0) return this->num;
		char nucleotido1 = cad[pos];
		char nucleotido2 = cad[cad.size() - 1 - pos];
		int resultado = this->term;
		for (int hijo = 0; hijo < 25; hijo++) {
			if (this->children[hijo] == nullptr) continue;
			int hijo1 = hijo / 5;
			int hijo2 = hijo % 5;
			if (nucleotido1 != '-' && hijo1 != 4 && hijo1 != get_idx(nucleotido1)) continue;
			if (nucleotido2 != '-' && hijo2 != 4 && hijo2 != get_idx(nucleotido2)) continue;
			resultado += this->children[hijo]->busca_repetidos(cad, pos - 1);
		}
		return resultado;
	}
};


struct trieNodoRaiz {
	trieNodoInterno* children[5];
	int num;
	trieNodoRaiz() : num(0) {
		for (int i = 0; i < 5; i++) {
			children[i] = nullptr;
		}
	}
	~trieNodoRaiz() {
		for (int i = 0; i < 5; i++) {
			if (children[i] != nullptr) {
				delete children[i];
			}
		}
	}

	void inserta_cadena(string const& cad) {
		this->num++;
		int ini = cad.size() / 2 - 1;
		if (cad.size() % 2 == 0) {
			if (this->children[0] == nullptr)
				this->children[0] = new trieNodoInterno();
			this->children[0]->inserta_cadena(cad, ini);
		}
		else {
			char c = cad[ini + 1];
			int pos = get_idx(c);
			if (this->children[pos] == nullptr)
				this->children[pos] = new trieNodoInterno();
			this->children[pos]->inserta_cadena(cad, ini);
		}
	}

	int busca_repetidos(string const& cad) {
		int resultado = 0;
		int ini = cad.size() / 2 - 1;
		if (cad.size() % 2 == 0) {
			if (this->children[0] != nullptr)
				resultado += this->children[0]->busca_repetidos(cad, ini);
		}
		else {
			char c = cad[ini + 1];
			if (c == '-') {
				for (int i = 0; i < 5; i++) {
					if (this->children[i] != nullptr)
						resultado += this->children[i]->busca_repetidos(cad, ini);
				}
			}
			else {
				int pos = get_idx(c);
				if (this->children[pos] != nullptr)
					resultado += this->children[pos]->busca_repetidos(cad, ini);
				// Si es una letra también nos valen guiones
				if (this->children[4] != nullptr)
					resultado += this->children[4]->busca_repetidos(cad, ini);
			}
		}
		return resultado;
	}
};



string eliminina_laterales(const string& cad) {
	int i = 0;
	int l = cad.size();
	while (i < l / 2) {
		if (cad[i] != '-' || cad[l - 1 - i] != '-') break;
		i++;
	}
	return cad.substr(i, l - 2 * i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n) {
		if (n <= 0) continue;
		vector<string> cadenas(n);
		string cad;
		trieNodoRaiz root;
		for (int i = 0; i < n; i++) {
			cin >> cad;
			cadenas[i] = eliminina_laterales(cad);
			root.inserta_cadena(cadenas[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			int resultado = root.busca_repetidos(cadenas[i]) - 1;
			cout << resultado << ' ';
		}
		int resultado = root.busca_repetidos(cadenas[n - 1]) - 1;
		cout << resultado;
		cout << '\n';
	}
}