#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int MAX_N = 3 * (1e5 + 10);

typedef pair<int, int> OperationData;

int n, m;
/*
 * @brief 操作中使用到的下标都会放到这个数组里，之后进行整数离散化处理。
 */
vector<int> used_position;
vector<OperationData> add_operations, query_operations;

/*
 * @brief 坐标经过映射后，需要查找值就访问position_data.
 *
 *  原始坐标 -> 求得映射的下标 i -> position_data[i]
 */
int position_data[MAX_N];
int prefix_sum[MAX_N];

/*
 * @brief 返回used_position中第一个 >= value 的元素的下标
 */
int FindFirstGE(int value)
{
	int l = 0, r = used_position.size() - 1;

	// l == r 时停止查询
	while (l < r)
	{
		// 从右边收缩需要向下取整
		int mid = (l + r) >> 1;
		if (used_position[mid] >= value)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}

	// 映射坐标需要从1开始，used_position是从0开始的
	return r + 1;
}

int main()
{
	cin >> n >> m;
	// add
	for (auto i = 1; i <= n; i++)
	{
		int x, c;
		cin >> x >> c;
		// 储存操作
		add_operations.push_back({x, c});

		// 将涉及到的坐标加入离散化队列
		used_position.push_back(x);
	}
	// query
	for (auto i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;

		// 储存操作
		query_operations.push_back({l, r});

		// 将涉及到的坐标加入离散化队列
		used_position.push_back(l);
		used_position.push_back(r);
	}

	/*
	 * 排序并去重,数组拥有单调性之后我们就可以对其进行二分查找
	 */
	sort(used_position.begin(), used_position.end());
	used_position.erase(
		unique(used_position.begin(), used_position.end()),
		used_position.end());

	// 进行加操作
	for (const auto [position, value] : add_operations)
	{
		auto target_index = FindFirstGE(position);
		position_data[target_index] += value;
	}

	// 求前缀和
	for (int index = 1, position_len = used_position.size(); index <= position_len; index++)
	{
		prefix_sum[index] = prefix_sum[index - 1] + position_data[index];
	}

	// 进行查询操作
	for (const auto [left, right] : query_operations)
	{
		auto left_index = FindFirstGE(left);
		auto right_index = FindFirstGE(right);

		cout << prefix_sum[right_index] - prefix_sum[left_index - 1] << endl;
	}

	return 0;
}