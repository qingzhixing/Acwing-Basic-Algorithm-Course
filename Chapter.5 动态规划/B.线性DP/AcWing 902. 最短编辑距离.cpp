#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 1010;

int n, m;
string a, b;
// dp[i][j] 表示将 a[1 ~ i] 变成 b[1 ~ j] 的操作方式的最小值
int dp[MAX_N][MAX_N];

int main()
{
	cin >> n >> a;
	cin >> m >> b;

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = i;
	}
	for (int i = 0; i <= m; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			}
			else
			{

				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}

	cout << dp[n][m] << endl;
	return 0;
}