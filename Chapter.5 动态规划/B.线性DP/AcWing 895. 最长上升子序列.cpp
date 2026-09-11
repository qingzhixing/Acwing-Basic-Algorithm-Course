#include <iostream>
using namespace std;

const int MAX_N = 1010;
const int INF = 1e9 + 10;

int n;
int a[MAX_N];

// dp[i] 表示 以第 i 个数结尾的子序列的长度的最大值
int dp[MAX_N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		// 只以当前数字结尾
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, dp[i]);
	}

	cout << res << endl;
	return 0;
}