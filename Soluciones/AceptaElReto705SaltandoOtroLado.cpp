#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num_casos;
	cin >> num_casos;
	for (int casos = 0; casos < num_casos; ++casos) {
		int n;
		cin >> n;
		vector<int> piedras(n + 1);
		piedras[0] = 0;
		for (int i = 1; i < n + 1; ++i) {
			cin >> piedras[i];
		}
		int capacidad = 0;
		for (int i = n; i > 0; --i){
			if (piedras[i] - piedras[i-1] > capacidad) {
				capacidad = piedras[i] - piedras[i - 1];
			}
			else if (piedras[i] - piedras[i - 1] == capacidad) capacidad++;
		}
		cout << capacidad << '\n';
	}



	return 0;
}