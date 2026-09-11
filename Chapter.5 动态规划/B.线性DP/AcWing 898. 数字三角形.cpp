#include <iostream>
#include <climits>
using namespace std;

const int MAX_N = 510;
const int INF = 1e9;

int n;
int a[MAX_N][MAX_N];

// dp[i][j] 表示 从起点走到 [i, j] 的所有路径的权值的最大值
int dp[MAX_N][MAX_N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i + 1; j++)
		{
			dp[i][j] = -INF;
		}
	}

	int result = -INF;

	dp[1][1] = a[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);

			dp[i][j] += a[i][j];

			if (i == n)
			{
				result = max(result, dp[i][j]);
			}
		}
	}

	cout << result << endl;
	return 0;
}