#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct NodeTrie {
	NodeTrie* arr[2];
	bool simbolo;
	int num_veces;
	NodeTrie() : arr(), simbolo(false), num_veces(0){};
};

struct direction {
	int dir_i, dir_j;
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
	for (int i = 0; i < 2; ++i) {
		if (root->arr[i] != NULL) {
			remove(root->arr[i]);
			delete root->arr[i];
		}
	}
}

void busca(vector<vector<char>> const& sopa, int fil, int col, int i, int j, NodeTrie* root, int dir_i, int dir_j) {
	if (i < 0 || i >= fil || j < 0 || j >= col) return;
	if (root->arr[sopa[i][j] - '0'] == NULL) return;

	NodeTrie* nextRoot = root->arr[sopa[i][j] - '0'];
	nextRoot->num_veces++;
	busca(sopa, fil, col, i + dir_i, j + dir_j, nextRoot, dir_i, dir_j);
}

void muestra(string palabra, NodeTrie* root) {
	if (root->simbolo && root->num_veces > 0)
		cout << palabra << ' ' << root->num_veces << '\n';
	
	if (root->arr[0] != NULL) {
		palabra.push_back('0');
		muestra(palabra, root->arr[0]);
		palabra.pop_back();
	}
	if (root->arr[1] != NULL) {
		palabra.push_back('1');
		muestra(palabra, root->arr[1]);
		palabra.pop_back();
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int col, fil;
	while (cin >> col >> fil) {
		vector<vector<char>> sopa(fil, vector<char>(col));
		for (int i = 0; i < fil; ++i) {
			for (int j = 0; j < col; ++j) {
				cin >> sopa[i][j];
			}
		}
		int num_palabras;
		cin >> num_palabras;
		string palabra;
		NodeTrie trie;
		for (int i = 0; i < num_palabras; ++i) {
			cin >> palabra;
			insert(palabra, &trie);
		}
		direction dirs[] = { {1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1} };
		for (int i = 0; i < fil; ++i) {
			for (int j = 0; j < col; ++j) {
				if (trie.arr[sopa[i][j] - '0'] == NULL) continue;
				trie.arr[sopa[i][j] - '0']->num_veces++;
				NodeTrie* nextRoot = trie.arr[sopa[i][j] - '0'];
				for (int k = 0; k < 8; ++k) {
					busca(sopa, fil, col, i + dirs[k].dir_i, j + dirs[k].dir_j, nextRoot, dirs[k].dir_i, dirs[k].dir_j);
				}
			}
		}
		string acum_palabra = "";
		muestra(acum_palabra, &trie);
		remove(&trie);
		cout << "---\n";
	}

}