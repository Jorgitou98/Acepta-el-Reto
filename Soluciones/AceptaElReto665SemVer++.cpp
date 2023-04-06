#include <iostream>
#include <stdio.h>
using namespace std;

struct version {
	int major, minor, patch;
};

int main() {
	int num_casos;
	cin >> num_casos;
	int val;
	for (int i = 0; i < num_casos; ++i) {
		version version1, version2;
		cin >> version1.major;
		getchar();
		cin >> version1.minor;
		getchar();
		cin >> version1.patch;

		cin >> version2.major;
		getchar();
		cin >> version2.minor;
		getchar();
		cin >> version2.patch;

		if (version2.major < version1.major || version2.major > version1.major + 1) {
			cout << "NO\n";
			continue;
		}
		if (version2.major == version1.major + 1) {
			if (version2.minor == 0 && version2.patch == 0) cout << "SI\n";
			else cout << "NO\n";
			continue;
		}
		if (version2.minor < version1.minor || version2.minor > version1.minor + 1) {
			cout << "NO\n";
			continue;
		}
		if (version2.minor == version1.minor + 1) {
			if (version2.patch == 0) cout << "SI\n";
			else cout << "NO\n";
			continue;
		}
		if (version2.patch == version1.patch + 1) cout << "SI\n";
		else cout << "NO\n";
	}



	return 0;
}