#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 1.5e5 + 10;

// to, weight
vector<pair<int, int>> map[MAX_N];

// 表示从编号为 1 的点到该点的距离
int dist[MAX_N];

// 当前最优的点
bool best[MAX_N];

int n, m;

// distance, id
typedef pair<int, int> QueueNode;
// 堆优化取点操作
priority_queue<QueueNode, vector<QueueNode>, greater<QueueNode>> dij_heap;

int main()
{
	cin >> n >> m;

	// init
	memset(dist, 0x3f, sizeof(dist));

	while (m--)
	{
		int from, to, value;
		cin >> from >> to >> value;
		// 不需要去重
		map[from].push_back({to, value});
	}

	dist[1] = 0;
	dij_heap.push({0, 1});

	// Dijkstra
	while (dij_heap.size())
	{
		auto [current_dist, current_id] = dij_heap.top();
		dij_heap.pop();

		// 之前就被遍历过，说明已经是最优
		if (best[current_id])
		{
			continue;
		}
		best[current_id] = true;

		// 利用当前节点松弛其他节点
		for (auto &edge : map[current_id])
		{
			auto [to, weight] = edge;
			int new_dist = current_dist + weight;

			// 松弛
			if (dist[to] > new_dist)
			{
				dist[to] = new_dist;
				dij_heap.push({new_dist, to});
			}
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