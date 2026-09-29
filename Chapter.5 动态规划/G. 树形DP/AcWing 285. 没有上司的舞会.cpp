#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 6010;
const int MAX_M = 6010;

int n;
int joy[MAX_N];
bool has_parent[MAX_N];

// 链式前向星存图
int nxt[MAX_M], head[MAX_M], to[MAX_M], cnt = -1;

// dp[i][1 / 0] 表示 以 i 为根节点的子树中,
// 1 - 选择了 i, 0 - 没选 i 的方案的最大 joy 和
int dp[MAX_N][2];

// 链式前向星, 插入一条 u -> v 的边
void add(int u, int v)
{
	// 向 u 边链表头部插入一条新边
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}

// 求以 root 为树根的最大 joy 和
void dfs(int root)
{
	dp[root][1] = joy[root];

	// ~edge = edge != -1
	for (int edge = head[root]; ~edge; edge = nxt[edge])
	{
		auto child = to[edge];
		dfs(child);

		dp[root][0] += max(dp[child][1], dp[child][0]);
		dp[root][1] += dp[child][0];
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> joy[i];
	}

	memset(head, -1, sizeof(head));
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		has_parent[u] = true;
		add(v, u);
	}

	// get root
	int root = 1;
	while (has_parent[root])
	{
		root++;
	}

	dfs(root);

	cout << max(dp[root][0], dp[root][1]) << endl;

	return 0;
}