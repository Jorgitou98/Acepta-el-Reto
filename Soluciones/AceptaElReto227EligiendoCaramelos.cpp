#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;
long long int euclides_extendido(int a, int b){
    int arr1, arr2;
    long long int  x1, x2, y1, y2;
    long long int  q, r;
    x2 = 1; x1 = 0;
    y2 = 0; y1 = 1;
    while (b > 0) {
        q = a / b;
        r = a - q * b;

        arr1 = x2 - q * x1;
        arr2 = y2 - q * y1;

        a = b;
        b = r;

        x2 = x1;
        y2 = y1;

        x1 = arr1;
        y1 = arr2;
    }

    return y2;
}
long long int OperacionZn(long long int a, long long int n){
    int inv;
    inv = euclides_extendido(n, a);
    if (inv < 0) {
        return inv + n;
    }
    else {
        return inv;
    }

}


int main() {
    //cin.sync_with_stdio(false);
    //cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	while (n != 0 || m != 0) {
		vector<long long int> C(m+1, 1);
		C[0] = 1;
		for (int i = 1; i < m + 1; ++i) {
            C[i] = ((C[i - 1] * OperacionZn(i, 1000000007)) % 1000000007) * (n - i + 1);
            C[i] %= 1000000007;
		}
		for (int i = 0; i < m + 1; ++i) {
			cout << C[i];
			if (i < m) cout << " ";
		}
		cout << '\n';
		cin >> n >> m;
	}


	return 0;
}
