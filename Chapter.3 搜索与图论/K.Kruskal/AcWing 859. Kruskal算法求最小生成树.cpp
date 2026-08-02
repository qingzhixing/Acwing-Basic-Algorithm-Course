#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;
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
		parent[id] = get_ancestor(id);
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
	
	return 0;
}