#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 510;

// edge[i][j] 表示左边第 i 个节点和右边第 j 个节点连通
bool edge[MAX_N][MAX_N];
// match[i] 表示右侧第 i 个节点匹配的左侧节点的编号
int match[MAX_N];
// pending[i] 表示在一次寻找增广路尝试中 待选的匹配，用于标记右侧节点
bool pending[MAX_N];

int n1, n2, m;

// 匈牙利匹配，返回是否能够完成匹配
bool hungary(int left_id)
{
	// 枚举当前节点能够到达的所有右侧节点
	for (int right_id = 1; right_id <= n2; right_id++)
	{
		// 不可达
		if (!edge[left_id][right_id])
		{
			continue;
		}

		// 当前右侧节点被其他节点待选了
		if (pending[right_id])
		{
			continue;
		}

		// 否则我们待选该节点，尝试匹配
		pending[right_id] = true;

		// 当前右侧节点未被匹配 或者 右侧节点匹配的左侧节点 还有其他选择，
		// 我们就可以匹配当前右侧节点
		if (match[right_id] == 0 || hungary(match[right_id]))
		{
			match[right_id] = left_id;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n1 >> n2 >> m;
	while (m--)
	{
		int from, to;
		cin >> from >> to;
		edge[from][to] = true;
	}

	int success_match = 0;
	// 匈牙利算法
	// 枚举左侧节点尝试匹配
	for (int left_id = 1; left_id <= n1; left_id++)
	{
		// 清除待选
		memset(pending, 0, sizeof(pending));
		success_match += hungary(left_id);
	}

	cout << success_match << endl;

	return 0;
}