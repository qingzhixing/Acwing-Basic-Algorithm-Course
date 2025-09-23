#include <iostream>
using namespace std;

static const int MAX_N = (1e5 + 10);

int main()
{
	int n;
	int array[MAX_N]{};
	int exist[MAX_N]{};
	int ans = 0;

	cin >> n;
	for (auto index = 1; index <= n; index++)
	{
		cin >> array[index];
	}

	int p_head = 1, p_tail = 1;
	while (p_tail <= n)
	{
		exist[array[p_tail]]++;

		// 移动p_head一直到没有重复元素
		while (p_head <= p_tail && exist[array[p_tail]] > 1)
		{
			exist[array[p_head]]--;
			p_head++;
		}

		// 更新答案
		ans = max(ans, p_tail - p_head + 1);

		p_tail++;
	}

	cout << ans << endl;
	return 0;
}