#include <iostream>
using namespace std;

static const int MAX_N = 1e5 + 10;

int parent[MAX_N];

// 到父节点的距离
int dist[MAX_N];

int GetAncestor(int idx)
{
	int dist_cnt = 0;

	int idx_copy = idx;
	while (parent[idx_copy] != idx_copy)
	{
		dist_cnt = dist[idx_copy];
		idx_copy = parent[idx_copy];
	}

	// 路径压缩
	while (parent[idx] != idx)
	{
		int delta_dist = dist[idx];
		dist[idx] = dist_cnt;
		dist_cnt -= delta_dist;
		idx = parent[idx];
	}

	return idx;
}

int n, m;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		dist[i] = 0;
	}

	int result = 0;
	while (m--)
	{
		int operation, val1, val2;
		cin >> operation >> val1 >> val2;
		if (val1 > n || val2 > n)
		{
			result++;
			continue;
		}

		int ancestor1 = GetAncestor(val1);
		int ancestor2 = GetAncestor(val2);

		if (operation == 1)
		{
			if (ancestor1 == ancestor2)
			{
				if ((dist[val1] - dist[val2]) % 3 != 0)
				{
					result++;
				}
			}
			else
			{
				parent[ancestor1] = ancestor2;
				dist[ancestor1] = dist[val2] - dist[val1] + 0;
			}
			continue;
		}

		if (operation == 2)
		{
			if (ancestor1 == ancestor2)
			{
				if ((dist[val1] - dist[val2] - 1) % 3 != 0)
				{
					result++;
				}
				else
				{
					parent[ancestor1] = ancestor2;
					dist[ancestor1] = dist[val2] - dist[val1] + 1;
				}
			}
		}
	}

	cout << result << endl;
	return 0;
}