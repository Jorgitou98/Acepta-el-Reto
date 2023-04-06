#include <iostream>
#include <vector>
using namespace std;


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int varillas;
	cin >> varillas;
	while (varillas != 0) {
		vector<int> longs (101, 0);
		int longitud;
		int muls4 = 0, muls2 = 0;
		for (int i = 0; i < varillas; ++i) {
			cin >> longitud;
			longs[longitud]++;
			if (longs[longitud] % 4 == 0) muls4++;
			if (longs[longitud] % 2 == 0) muls2++;
		}
		int lamparas = muls2 / 3;
		if (muls4 < lamparas) lamparas = muls4;
		cout << lamparas << '\n';

		cin >> varillas;
	}


	return 0;
}