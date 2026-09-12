#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 1010;
int n, m;
string a, b;

// dp[i][j] 表示 仅考虑 a 前 i 个字母和
//  b 前 j 个字母的公共子序列 的 最大长度
int dp[MAX_N][MAX_N];

int main()
{
	cin >> n >> m;
	cin >> a >> b;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}