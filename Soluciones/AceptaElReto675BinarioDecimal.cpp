#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

bool todo_uno_ceros(string const& num) {
	for (char c : num)
		if (c != '0' && c != '1') return false;

	return true;
}

int main() {
	unordered_map<int, int> min_ops;
	unordered_map<int, vector<int>> nums;
	nums[0] = vector<int>();
	for (int i = 0; i <= 10000; ++i) {
		if (todo_uno_ceros(to_string(i))) {
			min_ops[i] = 0;
			nums[0].push_back(i);
		}
	}
	int num_ops = 1;
	while (min_ops.size() < 10001) {
		nums[num_ops] = vector<int>();
		for (int i = 0; i < num_ops; ++i) {
			for (int j = i; j < num_ops; ++j) {
				if (i + j + 1 > num_ops) break;
				if (i + j + 1 < num_ops) continue;
				for (int elem1 : nums[i]) {
					for (int elem2 : nums[j]) {
						if (elem1 + elem2 <= 10000 && !min_ops.count(elem1 + elem2)) {
							min_ops[elem1 + elem2] = num_ops;
							nums[num_ops].push_back(elem1 + elem2);
						}
						if (elem1 * elem2 <= 10000 && !min_ops.count(elem1 * elem2)) {
							min_ops[elem1 * elem2] = num_ops;
							nums[num_ops].push_back(elem1 * elem2);
						}
					}
				}
			}
		}
		num_ops++;
	}
	int n;
	cin >> n;
	while (n != 0) {
		cout << min_ops[n] << '\n';
		cin >> n;
	}
}