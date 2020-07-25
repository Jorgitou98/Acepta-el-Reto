#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Interval
{
	int start;
	int end;
};

static bool comp(const Interval& a, const Interval& b)
{
	return a.start < b.start;
}

vector<Interval> merge_using_sort_method(vector<Interval> &intervals)
{
	vector<Interval> result_set;
	if (intervals.empty())
	{
		return result_set;
	}

	sort(intervals.begin(), intervals.end(), comp);

	result_set.push_back(intervals[0]);


	for (int i = 1; i < intervals.size(); i++)
	{
		if (result_set.back().end < intervals[i].start)
			result_set.push_back(intervals[i]);
		else
			result_set.back().end = max(result_set.back().end, intervals[i].end);
	}
	return result_set;
}



bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
	vector<Interval> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].start >> arr[i].end;
	}
	vector<Interval> sol = 	merge_using_sort_method(arr);
	int suma = 0;
	for (auto elem : sol) {
		suma += elem.end - elem.start + 1;
	}
	cout << suma << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
