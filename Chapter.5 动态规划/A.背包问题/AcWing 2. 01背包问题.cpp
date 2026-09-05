#include <iostream>
using namespace std;

const int MAX_N = 1010;

int n, m;
int v[MAX_N], w[MAX_N];
// f[i][j] 对应 所有选法中 只选前 i 个物品 且总重量 <= j 的选法，他们的总价值的最大值
int f[MAX_N][MAX_N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			// 包含 i
			f[i][j] = f[i - 1][j];
			if (j >= v[i])
			{
				// 不包含 i
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
			}
		}
	}

	cout << f[n][m] << endl;
	return 0;
}