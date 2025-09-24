#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> Range;

static const int MAX_N = (1e5 + 10);

int main()
{
	int n;
	vector<Range> range_array{};

	cin >> n;
	for (auto index = 1; index <= n; index++)
	{
		int l, r;
		cin >> l >> r;
		range_array.push_back({l, r});
	}

	// 按左端点排序
	sort(range_array.begin(), range_array.end(),
		 [](Range val1, Range val2) -> bool
		 { return val1.first < val2.first; });

	// 维护一段区间
	Range current_range = range_array[0];
	int ans = 1;

	// 重复考虑第一个区间不会导致结果变化
	for (const auto range : range_array)
	{
		// 若新区间左端点在当前区间内则可以合并
		if (range.first <= current_range.second)
		{
			current_range.second = max(range.second, current_range.second);
		}
		else
		{
			ans++;
			current_range = range;
		}
	}

	cout << ans << endl;
	return 0;
}