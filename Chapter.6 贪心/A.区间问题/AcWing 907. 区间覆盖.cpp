#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int s, t;
	cin >> s >> t;
	cin >> n;

	// l, r
	vector<pair<int, int>> ranges;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		ranges.emplace_back(l, r);
	}

	sort(ranges.begin(), ranges.end());

	int result = 0;
	int start_idx = 0;

	bool success = false;

	for (int start_idx = 0; start_idx < n; start_idx++)
	{
		// 双指针扫描
		int idx = start_idx;
		int next_s = -2e9;
		while (idx < n && ranges[idx].first <= s)
		{
			next_s = max(next_s, ranges[idx].second);
			idx++;
		}

		// 若没有满足条件的区间则无解
		if (next_s == -2e9)
		{
			break;
		}

		s = next_s;
		result++;
		start_idx = idx - 1;

		if (s >= t)
		{
			success = true;
			break;
		}
	}

	if (!success)
	{
		result = -1;
	}
	cout << result << endl;
	return 0;
}