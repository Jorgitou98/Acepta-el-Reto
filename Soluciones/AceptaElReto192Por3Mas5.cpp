#include <iostream>
#include <set>
using namespace std;

void posibles(set<int>& nums, int num) {
	if (num > 20000 || nums.count(num)) return;
	nums.insert(num);
	posibles(nums, num * 3);
	posibles(nums, num + 5);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	set<int>nums;
	posibles(nums, 1);
	int n;
	cin >> n;
	while (n != 0) {
		if (nums.count(n)) cout << "SI\n";
		else cout << "NO\n";

		cin >> n;
	}
	return 0;
}