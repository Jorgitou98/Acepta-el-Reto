#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		int p;
		char o;
		bool ob = false;
		if (s.length() == 3) {
			o = s[s.length() - 1];
			ob = true;
		}
		ss >> p;

		p = (18 + p) % 36;
		if (p == 0) p = 36;

		printf("%02d", p);
		if (ob) {
			if (o == 'L') o = 'R';
			else if (o == 'C') o = 'C';
			else o = 'L';
			cout << o;
		}

		cout << endl;
	}

	return 0;
}
