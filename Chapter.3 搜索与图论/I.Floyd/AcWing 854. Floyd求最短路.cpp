#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 210;

int n, m, k;

// dist[i][j] 表示从 i 走到 j 的最短路径
int dist[MAX_N][MAX_N];

int main()
{
	cin >> n >> m >> k;

	memset(dist, 0x3f, sizeof(dist));
	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}
	while (m--)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		// 去重
		dist[from][to] = min(dist[from][to], weight);
	}

	// Floyd
	// range 表示 只经过 [1, range] 这些点的最短路
	for (int range = 1; range <= n; range++)
	{
		for (int from = 1; from <= n; from++)
		{
			for (int to = 1; to <= n; to++)
			{
				dist[from][to] = min(dist[from][to], dist[from][range] + dist[range][to]);
			}
		}
	}

	while (k--)
	{
		int from, to;
		cin >> from >> to;
		if (dist[from][to] > 1e8)
		{
			cout << "impossible" << endl;
			continue;
		}
		cout << dist[from][to] << endl;
	}
	return 0;
}