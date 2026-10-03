#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 10;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> intervals;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		intervals.push_back({l, r});
	}

	// 按右端点从小到大排序
	sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
		 { return a.second < b.second; });

	int cnt = 0;
	int last_position = -1e9 - 10;
	for (auto &[l, r] : intervals)
	{
		if (l > last_position)
		{
			last_position = r;
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}