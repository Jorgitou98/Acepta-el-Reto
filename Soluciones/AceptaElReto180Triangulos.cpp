#include <stdio.h>
using namespace std;

int main() {
	int num_casos;
	scanf("%d", &num_casos);
	for (int i = 0; i < num_casos; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if ((a + b) <= c || (a + c) <= b || (b + c) <= a) {
			printf("IMPOSIBLE\n");
			continue;
		}
		double a_2 = a * a;
		double b_2 = b * b;
		double cos_a = (double) (b_2 + c * c - a * a) / (double) (2 * b * c);
		double cos_b = (double) (a_2 + c * c - b * b) / (double) (2 * a * c);
		double cos_c = (double) (a * a + b * b - c * c) / (double) (2 * a * b);
		if (cos_a == 0 || cos_b == 0 || cos_c == 0) printf("RECTANGULO\n");
		else if (cos_a < 0 || cos_b < 0 || cos_c < 0) printf("OBTUSANGULO\n");
		else printf("ACUTANGULO\n");
	}
	return 0;
}