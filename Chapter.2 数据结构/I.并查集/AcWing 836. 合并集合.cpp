#include <iostream>
using namespace std;

const int MAX_N = 1e5 + 10;

int parent[MAX_N];
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
		parent[node_index] = ancestor;
		node_index = next_index;
	}

	return ancestor;
}

void Merge(int index1, int index2)
{
	parent[GetAncestor(index2)] = GetAncestor(index1);
}

int main()
{
	cin >> n >> m;

	// 初始化节点
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	while (m--)
	{
		char operation;
		int val1, val2;
		cin >> operation >> val1 >> val2;

		switch (operation)
		{
		case 'M':
		{
			Merge(val1, val2);
			break;
		}
		case 'Q':
		{
			if (GetAncestor(val1) == GetAncestor(val2))
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
			break;
		}
		}
	}

	return 0;
}