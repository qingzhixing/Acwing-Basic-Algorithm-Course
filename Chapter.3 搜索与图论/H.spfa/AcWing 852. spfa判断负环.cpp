#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_N = 2010;

int n, m;

// to, weight
vector<pair<int, int>> edges[MAX_N];

// id
queue<int> updated;

int dist[MAX_N];

// 当前路径长度
int length[MAX_N];

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

	// 放置所有点原因: 防止 存在一点 到达不了负环
	for (int i = 1; i <= n; i++)
	{
		updated.push(i);
	}

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
				length[to] = length[from] + 1;
				updated.push(to);

				// 判断负环
				if (length[to] >= n)
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;
	return 0;
}