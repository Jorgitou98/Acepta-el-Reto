#include <iostream>
#include <cmath>
using namespace std;

long long int ini, fin;
int cifraIni;

void count_corrects(int& num, int disp, long long int act, int num_bit) {
	if (act > fin || disp == 0 || num_bit < 0 || (num_bit < cifraIni && act == 0)) return;
	count_corrects(num, disp, act, num_bit - 1);
	act |= (1LL << num_bit);
	if (ini <= act && act <= fin) num++;
	count_corrects(num, disp - 1, act, num_bit - 1);
}

int main() {
	int n;
	cin >> n >> ini >> fin;
	while (n != 0 || ini != 0 || fin != 0) {
		int num = 0;
		cifraIni = (int)log2(ini);
		count_corrects(num, n, 0, (int)log2(fin));
		if (ini == 0) num++;
		cout << num << '\n';
		cin >> n >> ini >> fin;
	}

	return 0;
}