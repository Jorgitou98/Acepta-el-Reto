#include <iostream>
using namespace std;


int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    long long int pot_30[] = { 1, 30, 900, 27000, 810000, 24300000,
                            729000000, 21870000000, 656100000000,
                            19683000000000, 590490000000000, 17714700000000000,
                            531441000000000000 };
    long long int pot_500[] = { 1, 500, 250000, 125000000, 62500000000, 31250000000000,
                                15625000000000000, 7812500000000000000 };
    long long int n;
    cin >> n;
    while (n != 0) {
        int mod_4 = n % 4;
        if (mod_4 == 0 || mod_4 == 2)
            cout << 20 * pot_30[n / 2 - 1] << '\n';
        else if (mod_4 == 1)
            cout << "0\n";
        else
            cout << 100 * pot_500[n / 4] << '\n';

        cin >> n;
    }
    return 0;
}