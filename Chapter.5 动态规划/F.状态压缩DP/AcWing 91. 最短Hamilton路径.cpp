#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 21;
const int MAX_M = 1 << MAX_N;

int n;
int g[MAX_N][MAX_N];
// dp[i][j] 表示 从 0 走到 j, 经过的点状态为 i 的代价最小值
int dp[MAX_M][MAX_N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	}

	memset(dp, 0x3f, sizeof(dp));

	// 从 0 走到 0
	dp[1][0] = 0;

	for (int state = 0; state < (1 << n); state++)
	{
		for (int end = 0; end <= n - 1; end++)
		{
			// 当前状态不合法
			if (((state >> end) & 1) == 0)
			{
				continue;
			}

			auto previous_state = state - (1 << end);

			// 枚举前一个点
			for (int previous = 0; previous <= n - 1; previous++)
			{
				// 前一个点合法: i 中包含 previous
				if ((previous_state >> previous) & 1)
				{
					dp[state][end] = min(dp[state][end], dp[previous_state][previous] + g[previous][end]);
				}
			}
		}
	}

	cout << dp[(1 << n) - 1][n - 1] << endl;
	return 0;
}