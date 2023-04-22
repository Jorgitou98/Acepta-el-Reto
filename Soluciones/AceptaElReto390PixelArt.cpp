#include <iostream>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; ++i) {
		int magenta, amarillo, cian;
		cin >> magenta >> amarillo >> cian;
		string pixeles;
		cin >> pixeles;
		for (char pixel : pixeles) {
			if (pixel == 'M') {
				magenta--;
				if (magenta < 0) break;
			}
			else if (pixel == 'A') {
				amarillo--;
				if (amarillo < 0) break;
			}
			else if (pixel == 'C') {
				cian--;
				if (cian < 0) break;
			}
			else if (pixel == 'R') {
				magenta--;
				amarillo--;
				if (magenta < 0 || amarillo < 0) break;
			}
			else if (pixel == 'N') {
				magenta--;
				amarillo--;
				cian--;
				if (magenta < 0 || amarillo < 0 || cian < 0) break;
			}
			else if (pixel == 'V') {
				amarillo--;
				cian--;
				if (amarillo < 0 || cian < 0) break;
			}
			else if (pixel == 'L') {
				magenta--;
				cian--;
				if (magenta < 0 || cian < 0) break;
			}
		}
		if (magenta >= 0 && amarillo >= 0 && cian >= 0) cout << "SI " << magenta << ' ' << amarillo << ' ' << cian << '\n';
		else cout << "NO\n";

	}

	return 0;
}