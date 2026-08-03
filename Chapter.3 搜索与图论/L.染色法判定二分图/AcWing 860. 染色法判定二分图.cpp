#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1e5 + 10;

int n, m;
vector<int> edges[MAX_N];

const int EMPTY = 0;
const int WHITE = 1;
const int BLACK = 2;
// 0-empty 1-white 2-black
int color[MAX_N];

// bfs 染色, 返回染色是否成功
bool bfs_color(int id)
{
	queue<int> bfs_queue;
	bfs_queue.push(id);

	// 未染色默认染成白色
	color[id] = WHITE;

	while (bfs_queue.size())
	{
		auto current_id = bfs_queue.front();
		bfs_queue.pop();
		auto current_color = color[current_id];
		auto next_color = (current_color == WHITE) ? BLACK : WHITE;

		for (auto next_id : edges[current_id])
		{
			// 未染色则进行染色
			if (color[next_id] == EMPTY)
			{
				color[next_id] = next_color;
				bfs_queue.push(next_id);
			}
			// 否则进行冲突检查
			else if (color[next_id] != next_color)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	// 匈牙利染色
	for (int id = 1; id <= n; id++)
	{
		// 未染色才进行染色
		if (color[id] == EMPTY)
		{
			if (!bfs_color(id))
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;
	return 0;
}