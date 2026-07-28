#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e5 + 10;
vector<int> edge[MAX_N];
int n;
int size[MAX_N];

// 标记点是否被遍历过
bool traversed[MAX_N];

int answer = MAX_N + 10;

int calculate_size(int root)
{
	// 标记当前节点
	traversed[root] = true;

	// 当前节点的size
	int size = 1;

	int max_subtree_size = 0;
	for (auto next_node : edge[root])
	{
		if (!traversed[next_node])
		{
			int next_size = calculate_size(next_node);
			size += next_size;
			max_subtree_size = max(max_subtree_size, next_size);
		}
	}

	// 整棵树中删掉此节点的树之后产生的树的size
	int other_size = n - size;

	answer = min(answer, max(other_size, max_subtree_size));

	return size;
}

int main()
{
	cin >> n;
	int idx1, idx2;
	for (int i = 0; i < n; i++)
	{
		cin >> idx1 >> idx2;
		edge[idx1].push_back(idx2);
		edge[idx2].push_back(idx1);
	}
	calculate_size(1);
	cout << answer << endl;
	return 0;
}