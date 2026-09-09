#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 25000;

int n, m;
// v, w
vector<pair<int, int>> items;
int dp[MAX_N];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int v, w, s;
		cin >> v >> w >> s;

		// 二进制优化拆分物品
		int k = 1;
		while (k <= s)
		{
			items.push_back({v * k, w * k});
			s -= k;
			k *= 2;
		}
		if (s > 0)
		{
			items.push_back({v * s, w * s});
		}
	}

	auto item_cnt = items.size();
	for (int i = 0; i < item_cnt; i++)
	{
		auto [v, w] = items.at(i);
		for (int j = m; j >= v; j--)
		{
			dp[j] = max(dp[j], dp[j - v] + w);
		}
	}

	cout << dp[m] << endl;
	return 0;
}