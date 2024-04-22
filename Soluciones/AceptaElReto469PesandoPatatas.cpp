#include <iostream>
#include <vector>
using namespace std;

vector<int> base3(int num){
    vector<int> rep;
    while(num >= 3){
        rep.push_back(num % 3);
        num /= 3;
    }
    rep.push_back(num);
    return rep;
}

int main(){
    int num;
    while (cin >> num){
        vector<int> rep = base3(num);
        rep.push_back(0);
        for (int i = 0; i < rep.size() - 1; i++){
            if (rep[i] == 2) {
                rep[i] = -1;
                rep[i+1] += 1;
            }
            else if (rep[i] == 3){
                rep[i] = 0;
                rep[i+1] += 1;
            }
        }
        int pot = 1;
        for (int i = 0; i < rep.size(); i++){
            if (rep[i] == 1) cout << pot << ' ';
            pot *= 3;
        }
        cout << "==X== ";
        pot = 1;
        for (int i = 0; i < rep.size(); i++){
            if (rep[i] == -1) cout << pot << ' ';
            pot *= 3;
        }
        cout << "patatas\n";
    }
    return 0;
}
