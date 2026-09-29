#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 310;

int n, m;
int h[MAX_N][MAX_N];
int f[MAX_N][MAX_N];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// 计算从 (x, y) 开始走的所有方案中的距离最长值
int dp(int x, int y)
{
	// 这个点的值已经被求过了
	if (f[x][y] != -1)
	{
		return f[x][y];
	}

	f[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		auto nx = x + dx[i];
		auto ny = y + dy[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && h[nx][ny] < h[x][y])
		{
			f[x][y] = max(f[x][y], dp(nx, ny) + 1);
		}
	}

	return f[x][y];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> h[i][j];
		}
	}

	memset(f, -1, sizeof(f));

	auto result = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			result = max(result, dp(i, j));
		}
	}

	cout << result << endl;
	return 0;
}