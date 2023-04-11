#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000007

struct NodeTrie {
	NodeTrie* arr[10];
	bool simbolo = false;
	NodeTrie() : arr() {};
};

void insert(string const& s, NodeTrie* root) {
	int in;
	NodeTrie* cur = root;
	for (int i = 0; i < s.length(); i++) {
		in = s[i] - '0';
		if (cur->arr[in] == NULL)
			cur->arr[in] = new NodeTrie();
		cur = cur->arr[in];
	}
	cur->simbolo = true;
}

void remove(NodeTrie* root) {
	for (int i = 0; i < 10; ++i) {
		if (root->arr[i] != NULL) {
			remove(root->arr[i]);
			delete root->arr[i];
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int posibilidades[1001];
	int n;
	cin >> n;
	while (n != 0) {
		string simbolo;
		NodeTrie trie;
		for (int i = 0; i < n; ++i) {
			cin >> simbolo;
			insert(simbolo, &trie);
		}
		string mensaje;
		cin >> mensaje;
		for (int i = 1; i < mensaje.length() + 1; ++i) posibilidades[i] = 0;
		posibilidades[0] = 1;
		for (int i = 0; i < mensaje.length(); ++i) {
			if (mensaje[i] == '0') {
				posibilidades[i + 1] = posibilidades[i];
				continue;
			}
			int longitud = 0;
			NodeTrie* cur = &trie;
			for (int j = i; j < mensaje.length(); ++j) {
				int pos = mensaje[j] - '0';
				if (cur->arr[pos] == NULL) break;
				longitud++;
				if (cur->arr[pos]->simbolo) {
					posibilidades[i + longitud] += posibilidades[i];
					posibilidades[i + longitud] %= MOD;
				}
				cur = cur->arr[pos];
			}
		}
		remove(&trie);

		cout << posibilidades[mensaje.length()] << '\n';

		cin >> n;
	}

}