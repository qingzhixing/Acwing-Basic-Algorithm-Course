#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 1e5 + 10;

int parent[MAX_N];
/*
 * cnt[i] = 以i为树根的节点数量
 */
int cnt[MAX_N];
int n, m;

int GetAncestor(int node_index)
{
	int ancestor = 0;
	int index_copy = node_index;
	while (parent[index_copy] != index_copy)
	{
		index_copy = parent[index_copy];
	}
	ancestor = index_copy;

	// 进行查询优化，避免二次查询重复花费时间
	while (node_index != parent[node_index])
	{
		int next_index = parent[node_index];

		if (next_index != ancestor)
		{
			cnt[next_index] -= cnt[node_index];
		}

		parent[node_index] = ancestor;
		node_index = next_index;
	}

	return ancestor;
}

int QueryCnt(int node_index)
{
	return cnt[GetAncestor(node_index)];
}

void Merge(int index1, int index2)
{
	int ancestor1 = GetAncestor(index1);
	int ancestor2 = GetAncestor(index2);
	if (ancestor1 == ancestor2)
		return;
	parent[ancestor1] = ancestor2;
	cnt[ancestor2] += cnt[ancestor1];
}

int main()
{
	cin >> n >> m;

	// 初始化节点
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		cnt[i] = 1;
	}

	while (m--)
	{
		string operation;
		cin >> operation;

		if (operation == "C")
		{
			int val1, val2;
			cin >> val1 >> val2;
			Merge(val1, val2);
			continue;
		}
		if (operation == "Q1")
		{
			int val1, val2;
			cin >> val1 >> val2;
			cout << (GetAncestor(val1) == GetAncestor(val2)
						 ? "Yes"
						 : "No")
				 << endl;
			continue;
		}
		if (operation == "Q2")
		{
			int val;
			cin >> val;
			cout << QueryCnt(val) << endl;
			continue;
		}
	}

	return 0;
}