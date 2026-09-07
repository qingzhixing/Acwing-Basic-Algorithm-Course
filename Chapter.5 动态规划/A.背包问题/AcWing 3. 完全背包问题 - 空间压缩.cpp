#include <iostream>
using namespace std;

const int MAX_N = 1010;

int n, c;
int v[MAX_N], w[MAX_N];

// dp[i][j] 表示 所有 只考虑前 i 个物品，总体积 小于等于 j 的所有选法 的最大价值
int dp[MAX_N];

int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = v[i]; j <= c; j++)
		{
			// 从当前层转移过来，也就是说，第i个物品可以选任意次
			// 因为只要 j - v[i] >= v[i], 上一次就有可能选 i
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}

	cout << dp[c] << endl;
	return 0;
}