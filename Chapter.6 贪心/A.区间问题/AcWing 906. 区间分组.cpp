#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> ranges;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		ranges.push_back({l, r});
	}

	sort(ranges.begin(), ranges.end());

	// 存储各个分组的最右侧区间的右端点
	priority_queue<int, vector<int>, greater<>> q;

	for (auto &[l, r] : ranges)
	{
		// 新开一个区间
		if (q.empty() || q.top() >= l)
		{
			q.push(r);
		}
		else
		{
			// 放到最小那个区间里去
			q.pop();
			q.push(r);
		}
	}

	cout << q.size() << endl;
	return 0;
}