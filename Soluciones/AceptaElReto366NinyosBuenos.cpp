#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct caracteristicas {
	int portado, peso;
	bool operator <(caracteristicas const& carac2) const {
		if (this->portado > carac2.portado) return true;
		else if (this->portado == carac2.portado) return this->peso < carac2.peso;
		return false;
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_ninyos;
	cin >> num_ninyos;
	while (num_ninyos != 0) {
		vector<caracteristicas> ninyos(num_ninyos);
		for (int i = 0; i < num_ninyos; ++i)
			cin >> ninyos[i].portado >> ninyos[i].peso;

		sort(ninyos.begin(), ninyos.end());

		for (int i = 0; i < num_ninyos; ++i) {
			cout << ninyos[i].portado << ' ' << ninyos[i].peso << '\n';
		}
		cout << '\n';

		cin >> num_ninyos;
	}
}