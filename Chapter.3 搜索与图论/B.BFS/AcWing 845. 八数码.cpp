#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

const string final_state = "12345678x";
const int d_column[4] = {0, 0, -1, 1};
const int d_row[4] = {-1, 1, 0, 0};

string start_state;
// state, step
queue<pair<string, int>> bfs_queue;
// 用于表示一个状态是否存在过
unordered_map<string, bool> state_exist;

int main()
{
	char ch;
	for (int i = 0; i < 9; i++)
	{
		cin >> ch;
		start_state += ch;
	}

	bfs_queue.push({start_state, 0});
	state_exist[start_state] = true;

	while (bfs_queue.size())
	{
		auto [current_state, step] = bfs_queue.front();
		bfs_queue.pop();

		// 已到达最终状态
		if (current_state == final_state)
		{
			cout << step << endl;
			return 0;
		}

		// 状态转移
		int index = current_state.find('x');
		int row = index / 3;
		int column = index % 3;
		for (int direction = 0; direction < 4; direction++)
		{
			int next_row = row + d_row[direction];
			int next_column = column + d_column[direction];

			// 判断坐标是否合法
			if (next_row < 0 || next_row >= 3 || next_column < 0 || next_column >= 3)
			{
				continue;
			}

			// 计算下一个状态
			auto next_state = current_state;
			swap(next_state[row * 3 + column], next_state[next_row * 3 + next_column]);

			// 以前到达过此状态，那么说明此状态一定不是最优，直接忽略
			if (state_exist[next_state])
			{
				continue;
			}

			// 将此状态加入队列
			bfs_queue.push({next_state, step + 1});
			state_exist[next_state] = true;
		}
	}
	// No Answer
	cout << -1 << endl;
	return 0;
}