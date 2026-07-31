#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_N = 1e5 + 10;

int n, m;

// to, weight
vector<pair<int, int>> edges[MAX_N];

// id
queue<int> updated;

int dist[MAX_N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, weight;

		cin >> from >> to >> weight;
		edges[from].push_back({to, weight});
	}

	// init
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	updated.push(1);

	// spfa
	while (updated.size())
	{
		int from = updated.front();
		updated.pop();

		for (auto &edge : edges[from])
		{
			auto &[to, weight] = edge;

			if (dist[to] > dist[from] + weight)
			{
				dist[to] = dist[from] + weight;
				updated.push(to);
			}
		}
	}

	// 判断是否有解
	// spfa只更新可达的点，所以无解dist不变
	if (dist[n] == 0x3f3f3f3f)
	{
		cout << "impossible" << endl;
		return 0;
	}
	cout << dist[n] << endl;
	return 0;
}