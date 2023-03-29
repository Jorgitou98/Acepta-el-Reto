#include <iostream>
#include <string>
#include <cctype>
using namespace std;


bool esPalindroma(string const& frase) {
	int i = 0;
	int j = frase.length() - 1;
	while (i < j) {
		if (frase[i] == ' ') {
			i++;
			continue;
		}
		if (frase[j] == ' ') {
			j--;
			continue;
		}
		if (tolower(frase[i]) != tolower(frase[j])) return false;
		i++;
		j--;
	}
	return true;
}

int main() {
	string frase;
	getline(cin, frase);
	while (frase != "XXX") {
		if (esPalindroma(frase)) cout << "SI\n";
		else cout << "NO\n";
		getline(cin, frase);
	}
	return 0;
}