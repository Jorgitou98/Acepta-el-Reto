#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int K = 31543;


long long int eleva(long long int x, int n){
	if (n == 0) return 1;
	else{
		long long int var = eleva(x, n / 2);
		if (n % 2 == 0){ 
			return (var * var) % K;
		}
		else {
			return ((x % K) * var * var) % K;
		}
	}
}
bool resuelveCaso() {
	long long int x;
	int n;
	cin >> x >> n;
	if (x == 0 && n == 0)
		return false;
	cout << eleva(x, n) << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
