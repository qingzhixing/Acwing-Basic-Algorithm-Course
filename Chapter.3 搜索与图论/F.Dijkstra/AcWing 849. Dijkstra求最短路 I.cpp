#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 510;

int weight[MAX_N][MAX_N];
// 表示从编号为 1 的点到该点的距离
int dist[MAX_N];
// 当前最优的点
bool best[MAX_N];
int n, m;

int main()
{
	cin >> n >> m;

	// init
	memset(weight, 0x3f, sizeof(weight));
	memset(dist, 0x3f, sizeof(dist));

	while (m--)
	{
		int from, to, value;
		cin >> from >> to >> value;
		// 去重
		weight[from][to] = min(value, weight[from][to]);
	}

	dist[1] = 0;

	// Dijkstra
	// 执行n次，每次更新一个点
	for (int turn = 1; turn <= n; turn++)
	{
		// 找到非最优点中的距离最近的点
		int shortest_id = -1;
		for (int id = 1; id <= n; id++)
		{
			if (best[id])
			{
				continue;
			}
			if (shortest_id != -1 && dist[id] >= dist[shortest_id])
			{
				continue;
			}
			shortest_id = id;
		}

		// printf("shortest: %d\n", shortest);

		// 该点为最优状态，用这个状态去松弛它连接的边
		best[shortest_id] = true;
		for (int next_id = 1; next_id <= n; next_id++)
		{
			// relax
			dist[next_id] = min(dist[next_id], dist[shortest_id] + weight[shortest_id][next_id]);
		}
	}

	// 判断无解
	if (dist[n] == 0x3f3f3f3f)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << dist[n] << endl;
	return 0;
}