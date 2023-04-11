#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

string op1, op2, res;
char op;

void muestra_sol(unordered_map<char, int> const& sol) {
	for (char c : op1) cout << sol.at(c);
	cout << ' ' << op << ' ';
	for (char c : op2) cout << sol.at(c);
	cout << " = ";
	for (char c : res) cout << sol.at(c);
	cout << '\n';
}

int res_multiplica(int acarreo, unordered_map<char, int> const& asig, int i) {
	int val_pos = acarreo;
	for (int k = i; k >= 0; k--) {
		int num1 = 0;
		int num2 = 0;
		if (k < op1.length()) num1 = asig.at(op1[op1.length() - 1 - k]);
		int opuesto = i - k;
		if (opuesto < op2.length()) num2 = asig.at(op2[op2.length() - 1 - opuesto]);
		val_pos += num1 * num2;
	}
	return val_pos;
}

void asignacion(unordered_map<char, int>& asig, bool libres[], int i, int n, int acarreo, bool & solucion) {
	if (solucion) return;
	if (i == n && acarreo == 0) {
		if (asig[op1[0]] == 0 && op1.length() > 1 ||
			asig[op2[0]] == 0 && op2.length() > 1 ||
			asig[res[0]] == 0 && res.length() > 1)
			return;
		muestra_sol(asig);
		solucion = true;
		return;
	}

	if (i < op1.length() && asig[op1[op1.length() - 1 - i]] == -1) {
		for (int j = 0; j < 10; ++j) {
			if (libres[j]) {
				asig[op1[op1.length() - 1 - i]] = j;
				libres[j] = false;
				asignacion(asig, libres, i, n, acarreo, solucion);
				asig[op1[op1.length() - 1 - i]] = -1;
				libres[j] = true;
			}
		}
		return;
	}

	if (i < op2.length() && asig[op2[op2.length() - 1 - i]] == -1) {
		for (int j = 0; j < 10; ++j) {
			if (libres[j]) {
				asig[op2[op2.length() - 1 - i]] = j;
				libres[j] = false;
				asignacion(asig, libres, i, n, acarreo, solucion);
				asig[op2[op2.length() - 1 - i]] = -1;
				libres[j] = true;
			}
		}
		return;
	}


	if (i >= res.length() || asig[res[res.length() - 1 - i]] != -1) {
		int num_res, num1, num2;

		if (i >= op1.length()) num1 = 0;
		else num1 = asig[op1[op1.length() - 1 - i]];

		if (i >= op2.length()) num2 = 0;
		else num2 = asig[op2[op2.length() - 1 - i]];

		if (i >= res.length()) num_res = 0;
		else num_res = asig[res[res.length() - 1 - i]];

		if (op == '+' && (num1 + num2 + acarreo) % 10 == num_res) {
			asignacion(asig, libres, i + 1, n, (num1 + num2 + acarreo) / 10, solucion);
		}
		else if (op == '*') {
			int val_pos = res_multiplica(acarreo, asig, i);
			if (val_pos % 10 == num_res) asignacion(asig, libres, i + 1, n, val_pos / 10, solucion);
		}
		else return;
	}
	else {
		int num_res;
		int nuevo_acarreo;
		if (op == '+') {
			int num1, num2;
			if (i >= op1.length()) num1 = 0;
			else num1 = asig[op1[op1.length() - 1 - i]];

			if (i >= op2.length()) num2 = 0;
			else num2 = asig[op2[op2.length() - 1 - i]];

			num_res = (num1 + num2 + acarreo) % 10;
			nuevo_acarreo = (num1 + num2 + acarreo) / 10;
		}
		else {
			int val_pos = res_multiplica(acarreo, asig, i);
			num_res = val_pos % 10;
			nuevo_acarreo = val_pos / 10;
		}
		if (!libres[num_res]) return;
		libres[num_res] = false;
		asig[res[res.length() - 1 - i]] = num_res;
		asignacion(asig, libres, i + 1, n, nuevo_acarreo, solucion);
		libres[num_res] = true;
		asig[res[res.length() - 1 - i]] = -1;
	}
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	char igual;
	while (cin >> op1 >> op >> op2 >> igual >> res) {
		unordered_map<char, int> asig;
		for (char c : op1) asig[c] = -1;
		for (char c : op2) asig[c] = -1;
		for (char c : res) asig[c] = -1;

		bool libres[10] = {true, true, true, true, true, true, true, true, true, true};
		bool solucion = false;
		asignacion(asig, libres, 0, max(op1.length(), max(op2.length(), res.length())), 0, solucion);	
	}


	return 0;
}