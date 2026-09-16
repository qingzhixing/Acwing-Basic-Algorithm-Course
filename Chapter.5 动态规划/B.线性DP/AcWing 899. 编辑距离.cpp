#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 1010;
const int MAX_M = 20;

int n, m;

// 表示把 s[i][1 ~ j] 变成 q[1 ~ k] 的最少方案数
int dp[MAX_M][MAX_M];

int main()
{
	cin >> n >> m;

	vector<string> s(n + 10);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}

	while (m--)
	{
		string q;
		int step;
		cin >> q >> step;

		auto len_q = q.length();

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{

			auto len_s = s[i].length();

			// init
			for (int j = 0; j <= len_s; j++)
			{
				dp[j][0] = j;
			}
			for (int k = 0; k <= len_q; k++)
			{
				dp[0][k] = k;
			}

			for (int j = 1; j <= len_s; j++)
			{
				for (int k = 1; k <= len_q; k++)
				{
					dp[j][k] = min(dp[j - 1][k] + 1, dp[j][k - 1] + 1);
					if (s[i][j - 1] == q[k - 1])
					{
						dp[j][k] = min(dp[j][k], dp[j - 1][k - 1]);
					}
					else
					{
						dp[j][k] = min(dp[j][k], dp[j - 1][k - 1] + 1);
					}
				}
			}

			if (dp[len_s][len_q] <= step)
			{
				ans++;
			}
			// printf("s[%d]: %s -> %s: %d\n", i, s[i].c_str(), q.c_str(), dp[len_s][len_q]);
		}
		cout << ans << endl;
	}
	return 0;
}