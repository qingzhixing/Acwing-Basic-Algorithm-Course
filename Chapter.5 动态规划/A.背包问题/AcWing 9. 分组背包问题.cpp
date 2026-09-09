#include <iostream>
using namespace std;

const int MAX_N = 110;

int n, m;
int s[MAX_N];
int v[MAX_N][MAX_N];
int w[MAX_N][MAX_N];
int dp[MAX_N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++)
		{
			cin >> v[i][j] >> w[i][j];
		}
	}

	// 枚举组数
	for (int i = 1; i <= n; i++)
	{
		// 枚举体积
		for (int j = m; j >= 0; j--)
		{
			// 枚举组内物品
			for (int k = 1; k <= s[i]; k++)
			{
				if (j < v[i][k])
				{
					continue;
				}
				dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
			}
		}
	}

	cout << dp[m] << endl;
	return 0;
}