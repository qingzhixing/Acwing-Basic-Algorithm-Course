#include <iostream>
using namespace std;

const int MAX_N = 2010;
const int MOD = 1e9 + 7;

// c[i][j] 表示从 i 个里面选 j 个
int c[MAX_N][MAX_N];

int n;

int main()
{
	// 预处理 c 数组
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				c[i][j] = 1;
				continue;
			}
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}

	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << c[a][b] << endl;
	}
	return 0;
}