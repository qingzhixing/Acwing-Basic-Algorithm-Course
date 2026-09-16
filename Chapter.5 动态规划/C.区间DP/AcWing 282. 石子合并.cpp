#include <iostream>
using namespace std;

const int MAX_N = 310;

int n;
int s[MAX_N];
int pre_sum[MAX_N];
// dp[i][j] 表示 合并区间 [i, j] 的石子的代价最小值
int dp[MAX_N][MAX_N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}

	// 求前缀和
	for (int i = 1; i <= n; i++)
	{
		pre_sum[i] = pre_sum[i - 1] + s[i];
	}

	// 区间DP
	// 枚举长度
	for (int len = 2; len <= n; len++)
	{
		// 枚举起点
		for (int start = 1; start + len - 1 <= n; start++)
		{
			auto end = start + len - 1;
			dp[start][end] = 1e9;
			// 枚举分割点
			for (int k = start; k < end; k++)
			{
				dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end] + (pre_sum[end] - pre_sum[start - 1]));
			}
		}
	}

	cout << dp[1][n] << endl;
	return 0;
}