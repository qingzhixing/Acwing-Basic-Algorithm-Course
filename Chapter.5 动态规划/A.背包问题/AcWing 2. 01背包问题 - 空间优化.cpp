#include <iostream>
using namespace std;

const int MAX_N = 1010;

int n, m;
int v[MAX_N], w[MAX_N];
// 滚动数组 空间优化
int f[MAX_N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= v[i]; j--)
		{

			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}

	cout << f[m] << endl;
	return 0;
}