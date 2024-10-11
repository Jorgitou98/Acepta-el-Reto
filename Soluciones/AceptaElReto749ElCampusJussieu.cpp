#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int c, f;
    int h;
    cin >> c >> f >> h;
    while (c != 0 || f != 0 || h != 0){
        vector<pair<int, int>> ausentes;
        for(int i = 0; i < h; i++){
            int a, b;

            cin >> a >> b;
            ausentes.push_back({a, b});
        }
        long long int num_edificios = (c-1) * f + (f-1) * c;
        unordered_set<string> retirados;
        for (auto par: ausentes){
            int i = par.first;
            int j = par.second;
            vector<pair<int, int>> vecinos = {
                make_pair(i-1, j), make_pair(i+1, j), 
                make_pair(i, j-1), make_pair(i, j+1)
            };

            string actual = to_string(i) + "|" + to_string(j);
            retirados.insert(actual);
            for (auto vecino : vecinos){
                if (vecino.first >= 1 && vecino.first <= c && vecino.second >= 1 && vecino.second <= f){
                    if(retirados.find(to_string(vecino.first) + "|" + to_string(vecino.second)) == retirados.end()){
                        num_edificios--;
                    }
                }
            }
        }

        cout << num_edificios << endl;
        cin >> c >> f >> h;
    }



    return 0;
}