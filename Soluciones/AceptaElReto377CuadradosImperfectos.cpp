#include <iostream>
#include <string>
using namespace std;

int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	string num;
	while (cin >> num) {
		int n;
		if (num.length() <= 4) {
			n = stoi(num);
		}
		else {
			n = stoi(num.substr(num.size()-4, 4));
		}
		if (n % 16 == 0 || n % 16 == 1 || n % 16 == 4 || n % 16 == 9) cout << "NO SE\n";
		else cout << "IMPERFECTO\n";
	}
	return 0;
}