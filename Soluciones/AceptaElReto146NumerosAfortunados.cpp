#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int main() {
	//cin.sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {
        vector<int> nums(n);
		for (int i = 0; i < n; ++i) nums[i] = i + 1;
		int paso = 2;
		while (paso <= nums.size()) {
            vector<int> aux;
            for (int i = 0; i < nums.size(); ++i) {
                if (i % paso != 0) aux.push_back(nums[i]);
            }
            nums.clear();
            nums = move(aux);
			paso++;
		}
		cout << n << ": ";
		for (int i = nums.size() - 1; i >= 0; --i) {
			cout << nums[i];
			if (i > 0) cout << " ";
		}
		cout << '\n';
		cin >> n;
	}

	return 0;
}
