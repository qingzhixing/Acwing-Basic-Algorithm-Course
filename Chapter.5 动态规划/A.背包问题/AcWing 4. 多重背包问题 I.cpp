#include <iostream>
using namespace std;

const int MAX_N = 110;

int n, m;
int v[MAX_N], w[MAX_N], s[MAX_N];
int dp[MAX_N][MAX_N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i] >> s[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= s[i]; k++)
			{
				if (j < k * v[i])
				{
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
			}
		}
	}

	cout << dp[n][m] << endl;
	return 0;
}