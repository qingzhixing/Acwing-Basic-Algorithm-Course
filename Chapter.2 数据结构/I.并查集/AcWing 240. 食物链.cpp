#include <iostream>
#include <cmath>
using namespace std;

static const int MAX_N = 1e5 + 10;

// 当前节点的父节点编号
int parent[MAX_N];

// 到父节点的距离
int dist_to_father[MAX_N];

// 获取当前节点的父节点，同时路径压缩
int get_ancestor(int idx)
{
	int dist_cnt = 0;

	int finded_root = idx;
	while (parent[finded_root] != finded_root)
	{
		dist_cnt += dist_to_father[finded_root];
		finded_root = parent[finded_root];
	}

	// 路径压缩
	while (parent[idx] != idx)
	{
		int delta_dist = dist_to_father[idx];
		int backup_idx = idx;

		// 更新dist_to_father
		dist_to_father[idx] = dist_cnt;

		dist_cnt -= delta_dist;
		idx = parent[idx];

		// 更新parent
		parent[backup_idx] = finded_root;
	}

	return idx;
}

int n, m;
int main()
{
	cin >> n >> m;

	// 初始化，每个节点初始指向自己
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		dist_to_father[i] = 0;
	}

	int result = 0;
	while (m--)
	{
		int operation, val1, val2;
		cin >> operation >> val1 >> val2;

		// 判断节点编号合法
		if (val1 > n || val2 > n)
		{
			// puts("Node Id Illegal.");
			result++;
			continue;
		}

		// 获取对应祖先节点并进行路径压缩
		int ancestor1 = get_ancestor(val1);
		int ancestor2 = get_ancestor(val2);
		// printf("ancestor[%d] = %d; ancestor[%d] = %d\n", val1, ancestor1, val2, ancestor2);
		// printf("dist[%d] = %d; dist[%d] = %d\n", val1, dist_to_father[val1], val2, dist_to_father[val2]);

		// val1 和 val2是同类
		if (operation == 1)
		{
			// 在同一颗树上, 则判断是否相等
			if (ancestor1 == ancestor2)
			{
				if ((dist_to_father[val1] - dist_to_father[val2]) % 3 != 0)
				{
					// printf("%d is not same as %d\n", val1, val2);
					result++;
				}
			}
			// 在不同树上, 合并两棵树
			else
			{
				parent[ancestor1] = ancestor2;
				dist_to_father[ancestor1] = dist_to_father[val2] - dist_to_father[val1] + 0;
			}
			continue;
		}

		// val1 吃 val2
		if (operation == 2)
		{
			// 在同一棵树上则检测
			if (ancestor1 == ancestor2)
			{
				if ((dist_to_father[val1] - dist_to_father[val2] - 1) % 3 != 0)
				{
					// printf("%d do not eat %d\n", val1, val2);
					result++;
				}
			}
			// 在不同树上则合并
			else
			{
				parent[ancestor1] = ancestor2;
				dist_to_father[ancestor1] = dist_to_father[val2] - dist_to_father[val1] + 1;
			}
		}
	}

	cout << result << endl;
	return 0;
}