#include <stdio.h>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	long long int sabor, grosor;
	while (scanf("%lld %lld", &sabor, &grosor) == 2) {
		long long int max_sabor = 0;
		long long int min_grosor = LLONG_MAX;
		bool existe = false;
		while (sabor != 0 && grosor != 0) {
			if (sabor >= max_sabor && grosor <= min_grosor) {
				existe = true;
			}
			else if (sabor > max_sabor || grosor < min_grosor) existe = false;
			max_sabor = max(max_sabor, sabor);
			min_grosor = min(min_grosor, grosor);
			scanf("%lld %lld", &sabor, &grosor);
		}
		if (existe) printf("%lld %lld\n", max_sabor, min_grosor);
		else printf("NO HAY MEJOR\n");
	}

	return 0;
}
