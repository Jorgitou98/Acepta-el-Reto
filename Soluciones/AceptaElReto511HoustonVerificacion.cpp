#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct componente {
	int repeticiones, valor;
};

int main() {
	int grupos1, grupos2;
	while (cin >> grupos1 >> grupos2) {
		vector<componente> vec1(grupos1);
		vector<componente> vec2(grupos2);
		for (int i = 0; i < grupos1; i++) cin >> vec1[i].repeticiones >> vec1[i].valor;
		for (int i = 0; i < grupos2; i++) cin >> vec2[i].repeticiones >> vec2[i].valor;

		long long int resultado = 0;
		int ind1 = 0, ind2 = 0;
		while (ind1 < grupos1 && ind2 < grupos2) {
			int min_rep = min(vec1[ind1].repeticiones, vec2[ind2].repeticiones);
			resultado += (long long int) min_rep * (long long int) vec1[ind1].valor * (long long int) vec2[ind2].valor;
			vec1[ind1].repeticiones -= min_rep;
			vec2[ind2].repeticiones -= min_rep;
			if (vec1[ind1].repeticiones == 0) ind1++;
			if (vec2[ind2].repeticiones == 0) ind2++;
		}
		cout << resultado << '\n';
	}



	return 0;
}