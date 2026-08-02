#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;
	bool operator<(const Edge &other) const
	{
		return weight < other.weight;
	}
};

const int MAX_N = 1e5 + 10;

int n, m;
vector<Edge> edges;

int parent[MAX_N];

// 连接的边的数量，用于判断无解
int edge_count;

int weight_sum;

int get_ancestor(int id)
{
	if (parent[id] != id)
	{
		parent[id] = get_ancestor(parent[id]);
	}
	return parent[id];
}

int main()
{
	cin >> n >> m;
	while (m--)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		edges.push_back({from, to, weight});
	}

	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	// Kruskal
	for (auto edge : edges)
	{
		auto [from, to, weight] = edge;
		int ancestor_from = get_ancestor(from);
		int ancestor_to = get_ancestor(to);

		if (ancestor_from != ancestor_to)
		{
			parent[ancestor_from] = ancestor_to;
			edge_count++;
			weight_sum += weight;
		}
	}

	// 判断无解
	// 如果加入边数 < n-1 说明不是连通图
	if (edge_count < n - 1)
	{
		cout << "impossible" << endl;
		return 0;
	}
	cout << weight_sum << endl;

	return 0;
}