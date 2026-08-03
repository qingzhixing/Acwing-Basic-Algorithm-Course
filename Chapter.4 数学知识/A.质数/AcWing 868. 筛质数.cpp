#include <iostream>
using namespace std;

const int MAX_N = 1e6 + 10;

// 被 质数筛 是否筛掉
bool filtered[MAX_N];
int prime_count = 0;

int main()
{
	int n;
	cin >> n;

	// 埃式筛法
	// 枚举 2 ~ n 所有数字
	for (int number = 2; number <= n; number++)
	{
		if (filtered[number])
		{
			continue;
		}
		// 先前没被筛掉，那么number一定是质数
		prime_count++;
		// 用 number 筛选后面的数
		int times = 2;
		while (number * times <= n)
		{
			filtered[number * times] = true;
			times++;
		}
	}

	cout << prime_count << endl;
	return 0;
}