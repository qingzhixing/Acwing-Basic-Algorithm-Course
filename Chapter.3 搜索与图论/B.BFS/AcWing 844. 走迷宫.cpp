#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

static const int MAX_N = 110;
bool map[MAX_N][MAX_N];
int n, m;

// 分别保存 row, column, step
deque<tuple<int, int, int>> bfs_queue;

static const int d_row[4] = {-1, 1, 0, 0};
static const int d_col[4] = {0, 0, -1, 1};

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	bfs_queue.push_back({0, 0, 0});
	// 防止回头
	map[0][0] = 1;

	while (bfs_queue.size())
	{
		auto [row, column, step] = bfs_queue.front();
		bfs_queue.pop_front();

		if (row == n - 1 && column == m - 1)
		{
			cout << step << endl;
			return 0;
		}

		for (int direction = 0; direction < 4; direction++)
		{
			int next_row = row + d_row[direction];
			int next_column = column + d_col[direction];

			if (next_column < m && next_column >= 0 &&
				next_row >= 0 && next_row < n &&
				map[next_row][next_column] == 0)
			{
				bfs_queue.push_back({next_row, next_column, step + 1});
				// 防止回头
				map[next_row][next_column] = 1;
			}
		}
	}
	return 0;
}