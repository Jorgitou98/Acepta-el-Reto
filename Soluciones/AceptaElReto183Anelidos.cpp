#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

string calc_reverse(string chain){
    stringstream stream;
    for(int i=0; i< chain.size(); i++){
        stream << chain.at(i);
        if(chain.at(i)=='A'){
            stream << "N";
        }else{
            stream << "A";
        }
    }
    return stream.str();
}

string solution(stringstream & stream_chain, int limit, int & counter){
    if(limit==counter){
        return stream_chain.str();
    }
    string aux1 = stream_chain.str();
    stream_chain.str("");
    stream_chain << calc_reverse(aux1);
    counter++;
    return solution(stream_chain, limit, counter);
}

bool solutionLauncher(){
    stringstream stream;
    int limit, counter;
    string chain;
    cin >> limit >> chain;
    while(chain.size()>1){
        stream.str("");
        counter=0;
        chain.erase(chain.size()-1,1);
        stream << chain;
        cout << solution(stream, limit, counter) << "C" << endl;
        cin >> limit >> chain;
    }
    return false;
}

int main(){
    while(solutionLauncher());
}
