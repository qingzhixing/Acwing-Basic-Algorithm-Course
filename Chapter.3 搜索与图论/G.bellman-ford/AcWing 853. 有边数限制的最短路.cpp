#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 510;
const int MAX_M = 1e4 + 10;

struct Edge
{
	int from;
	int to;
	int weight;
};

int n, m, k;

vector<Edge> edges;

int dist[MAX_N];
int previous_dist[MAX_N];

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int from, to, weight;

		cin >> from >> to >> weight;
		edges.push_back({from, to, weight});
	}

	// init
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	// 迭代k次，路径最多进行k次操作，所以最多只能经过 k 条边
	for (int turn = 1; turn <= k; turn++)
	{
		memcpy(previous_dist, dist, sizeof(dist));

		for (auto &edge : edges)
		{
			auto &[from, to, weight] = edge;

			// 为了保证一次迭代最多走一步，我们这里必须使用privious[from]，
			//     因为dist[from]可能已经被这一个turn更改了
			dist[to] = min(dist[to], previous_dist[from] + weight);
		}
	}

	// 判断是否有解
	// Inf + 所有负权边 仍然比 1e8 大
	if (dist[n] > 1e8)
	{
		cout << "impossible" << endl;
		return 0;
	}
	cout << dist[n] << endl;
	return 0;
}