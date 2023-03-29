#include <iostream>
#include <vector>
#include <string>
using namespace std;

void posibleSigCapicua(string & posible_num) {
    for (int i = 0; i < posible_num.length()/2; ++i) {
        posible_num[posible_num.length() - 1 - i] = posible_num[i];
    }
}

bool todos_9(string const& num) {
    for (char c : num)
        if (c != '9') return false;
    return true;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num_casos;
    cin >> num_casos;
    for (int i = 0; i < num_casos; ++i) {
        int n;
        cin >> n;
        string posible_num = to_string(n);
        if(todos_9(posible_num)) posible_num = to_string(n+1);
        posibleSigCapicua(posible_num);
        if (stoi(posible_num) <= n) {
            for (int i = (posible_num.length() - 1) / 2; i >= 0; --i) {
                char num_i = posible_num[i];
                if (num_i < '9') {
                    posible_num[i] = num_i + 1;
                    posible_num[posible_num.length() - 1 - i] = num_i + 1;
                    break;
                }
                else {
                    posible_num[i] = '0';
                    posible_num[posible_num.length() - 1 - i] = '0';
                }
            }
        }
        cout << stoi(posible_num) - n << '\n';      
    }
    return 0;
}