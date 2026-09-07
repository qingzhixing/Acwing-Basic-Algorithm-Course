#include <iostream>
using namespace std;

const int MAX_N = 1010;

int n, c;
int v[MAX_N], w[MAX_N];

// dp[i][j] 表示 所有 只考虑前 i 个物品，总体积 小于等于 j 的所有选法 的最大价值
// 优化成一维 dp[j]
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
		for (int j = c; j >= v[i]; j--)
		{
			// 第 i 个物品选择的数量
			for (int k = 0; k * v[i] <= j; k++)
			{
				dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
			}
		}
	}

	cout << dp[c] << endl;
	return 0;
}