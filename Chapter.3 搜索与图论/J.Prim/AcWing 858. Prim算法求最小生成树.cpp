#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 510;

int map[MAX_N][MAX_N];

// dist[i] 表示 i 点到集合的距离
int dist[MAX_N];

// in_set[i] 表示 i 点是否已经在集合中
bool in_set[MAX_N];

int n, m;

int main()
{
	cin >> n >> m;

	memset(dist, 0x3f, sizeof(dist));
	memset(map, 0x3f, sizeof(map));

	while (m--)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		// 去重边
		map[to][from] = map[from][to] = min(map[from][to], weight);
	}

	int answer = 0;

	// Prim
	for (int turn = 1; turn <= n; turn++)
	{
		// 找到一个不在集合中距离最近的点
		int shortest_id = -1;
		for (int id = 1; id <= n; id++)
		{
			if (in_set[id])
			{
				continue;
			}
			if (shortest_id == -1 || dist[id] < dist[shortest_id])
			{
				shortest_id = id;
			}
		}

		// 判断是否有解
		// 集合中有点并且没有点能连接到集合
		if (turn != 1 && dist[shortest_id] == 0x3f3f3f3f)
		{
			cout << "impossible" << endl;
			return 0;
		}

		if (turn != 1)
		{
			answer += dist[shortest_id];
		}

		// 加入集合
		in_set[shortest_id] = true;

		// 用该点更新其他点的距离
		for (int to = 1; to <= n; to++)
		{
			dist[to] = min(dist[to], map[shortest_id][to]);
		}
	}

	cout << answer << endl;

	return 0;
}