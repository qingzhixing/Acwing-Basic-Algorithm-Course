#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 1e5 + 10;
vector<int> edge[MAX_N];
int n, m;
int in_degree[MAX_N];
bool traversed[MAX_N];
queue<int> bfs_queue;
vector<int> sorted;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
		in_degree[to]++;
	}

	// 找到入度为0的点加入队列
	for (int i = 1; i <= n; i++)
	{
		if (in_degree[i] == 0)
		{
			bfs_queue.push(i);
			traversed[i] = true;
		}
	}

	while (bfs_queue.size())
	{
		int id = bfs_queue.front();
		bfs_queue.pop();
		sorted.push_back(id);

		// 删除该节点
		for (auto next_id : edge[id])
		{
			if (traversed[next_id])
			{
				continue;
			}
			in_degree[next_id]--;
			if (in_degree[next_id] == 0)
			{
				traversed[next_id] = true;
				bfs_queue.push(next_id);
			}
		}
	}

	// 判断是否有解
	if (sorted.size() != n)
	{
		cout << -1 << endl;
		return 0;
	}

	for (auto id : sorted)
	{
		printf("%d ", id);
	}
	puts("");

	return 0;
}