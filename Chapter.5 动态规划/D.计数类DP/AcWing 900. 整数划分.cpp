#include <iostream>
using namespace std;

const int MAX_N = 1010;
const int MOD = 1e9 + 7;

int n;
// dp[i][j] 表示 仅考虑前 1 ~ i 个数字，其总和恰好等于 j 的方案数
int dp[MAX_N];

int main()
{
	cin >> n;

	// 一个数都不选，总和为 0, 是一种方案, dp[1 ~ n][0] = 1;
	dp[0] = 1;

	for (int num = 1; num <= n; num++)
	{
		for (int sum = num; sum <= n; sum++)
		{
			dp[sum] = (dp[sum] + dp[sum - num]) % MOD;
		}
	}

	cout << dp[n] << endl;
	return 0;
}