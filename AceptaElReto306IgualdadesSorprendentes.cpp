// Jorge Villarrubia Elvira
#include <iostream>
#include <vector>
using namespace std;

const int K = 46337;


vector <vector <long long int>> operator*(vector <vector <long long int>> const& v1, vector <vector <long long int>> const& v2){
	vector <vector <long long int>> u;
	long long int a11 = (v1[0][0] * v2[0][0] + v1[0][1] * v2[1][0]) % K;
	long long int a12 = (v1[0][0] * v2[0][1] + v1[0][1] * v2[1][1]) % K;
	long long int a21 = (v1[1][0] * v2[0][0] + v1[1][1] * v2[1][0]) % K;
	long long int a22 = (v1[1][0] * v2[0][1] + v1[1][1] * v2[1][1]) % K;
	
	u.push_back({ a11, a12 });
	u.push_back({ a21, a22 });
	return u;
};

vector <vector <long long int>> fibonacci(long long int n){
	if (n == 2) return{ { 1, 1 }, { 1, 2 } };
	else if (n == 1) return{ { 0, 1 }, { 1, 1 } };
	else{
		vector <vector <long long int>> mitad = fibonacci(n / 2);
		if (n % 2 == 0) {
			return (mitad * mitad);
		}
		else {
			vector <vector <long long int>> unidad = { { 0, 1 }, { 1, 1 } };
			return (mitad * mitad) * unidad;
		}
	}
}

bool resuelveCaso() {
	long long int n;
	cin >> n;
	if (n == 0)
		return false;
	cout << fibonacci(n)[0][1] << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
