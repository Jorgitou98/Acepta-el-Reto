#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n; 
	while (cin >> n) {
		vector<int> montones;
		int valor;
		cin >> valor;
		montones.push_back(valor);
		for (int i = 1; i < n; ++i) {
			cin >> valor;
			if (montones[montones.size()-1] <= valor) montones.push_back(valor);
			else {
				vector<int>::iterator up = upper_bound(montones.begin(), montones.end(), valor);
				*up = valor;
			}
		}
		cout << montones.size() << '\n';
	}
	return 0;
}