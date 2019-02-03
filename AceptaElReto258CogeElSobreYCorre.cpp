#include <iostream>
#include <deque>
using namespace std;


struct tElem{
	int elem, pos;
};
bool resuelveCaso() {
	int n, k;
	cin >> n >> k;
	if (n == 0 && k == 0)
		return false;
	deque <tElem> colaK, candidatosMax;
	tElem max = { 0, -1 };
	int valor;
	for (int i = 0; i < k; ++i){ //Cojo el maximo
		cin >> valor;
		if (valor > max.elem){
			max = { valor, i };
		}
		colaK.push_back({ valor, i });
	}
	deque <tElem> aux = colaK;
	int maxCand = 0;
	while (!aux.empty()){
		if (aux.back().elem > maxCand && aux.back().pos != max.pos){
			maxCand = aux.back().elem;
			candidatosMax.push_back(aux.back());
		}
		aux.pop_back();
	}
	cout << max.elem;
	 if (k < n) cout << " ";
	for (int i = k; i < n; ++i){
		cin >> valor;
		if (!candidatosMax.empty() && candidatosMax.back().pos == colaK.front().pos) candidatosMax.pop_back();
		if (colaK.front().elem == max.elem){
			if (!candidatosMax.empty()) {
				max = candidatosMax.back();
				candidatosMax.pop_back();
			}
			else {
				max = { valor, i };
			}
		}
		colaK.pop_front();
		if (valor > max.elem){
			max = { valor, i };
			if (!candidatosMax.empty()) candidatosMax.clear();
		}
		else {
			if (candidatosMax.empty()) candidatosMax.push_back({ valor, i });
			else{
				if (valor >= candidatosMax.front().elem){
					while (!candidatosMax.empty() && valor >= candidatosMax.front().elem) candidatosMax.pop_front();
				}
				candidatosMax.push_front({ valor, i });
			}
		}
		colaK.push_back({ valor, i }); 
		cout << max.elem;
		if(i < n - 1) cout << " ";
	}
	cout << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
