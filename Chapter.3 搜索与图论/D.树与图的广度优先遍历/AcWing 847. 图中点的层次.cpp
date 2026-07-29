#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 1e5 + 10;

vector<int> edge[MAX_N];
int n, m;

int main()
{
	cin >> n >> m;
	while (m--)
	{
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
	}

	bool traversed[MAX_N] = {};
	// id, step
	queue<pair<int, int>> bfs_queue;

	bfs_queue.push({1, 0});
	traversed[1] = true;

	while (bfs_queue.size())
	{
		auto [id, step] = bfs_queue.front();
		bfs_queue.pop();

		// reach
		if (id == n)
		{
			cout << step << endl;
			return 0;
		}

		for (auto next_id : edge[id])
		{
			if (!traversed[next_id])
			{
				traversed[next_id] = true;
				bfs_queue.push({next_id, step + 1});
			}
		}
	}

	cout << -1 << endl;
	return 0;
}