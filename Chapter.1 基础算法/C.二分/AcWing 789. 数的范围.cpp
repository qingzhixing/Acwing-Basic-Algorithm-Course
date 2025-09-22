#include <iostream>
using namespace std;

static const int MAX_N = (1e5 + 10);

static int n, q, k;
static int array[MAX_N];

/*
 * @return 第一个小于等于(Less or Equal, LE) value的数字的下标
 */
int QueryLE(int value)
{
	int p_left = 1, p_right = n;
	while (p_left < p_right)
	{
		// 对左边界处理都需要向上取整保证不会死循环
		int p_mid = (p_left + p_right + 1) >> 1;
		if (array[p_mid] > value)
		{
			p_right = p_mid - 1;
		}
		else
		{
			p_left = p_mid;
		}
	}
	return p_left;
}

/*
 * @return 第一个大于等于(Greater or Equal, GE) value的数字的下标
 */
int QueryGE(int value)
{
	int p_left = 1, p_right = n;
	while (p_left < p_right)
	{
		// 对右边界处理都需要向下取整
		int p_mid = (p_left + p_right) >> 1;
		if (array[p_mid] < value)
		{
			p_left = p_mid + 1;
		}
		else
		{
			p_right = p_mid;
		}
	}
	return p_left;
}

int main()
{
	cin >> n >> q;

	for (auto i = 1; i <= n; i++)
	{
		cin >> array[i];
	}

	while (q--)
	{
		cin >> k;
		int left_index = QueryGE(k);
		int right_index = QueryLE(k);
		if (array[left_index] != k || array[right_index] != k)
		{
			printf("-1 -1\n");
			continue;
		}
		// 数组下标从 0 开始所以要对 索引-1
		printf("%d %d\n", left_index - 1, right_index - 1);
	}
	return 0;
}