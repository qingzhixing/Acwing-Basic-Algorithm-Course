#include <iostream>
using namespace std;

const int MAX_N = 20;

int n, m;
int p[MAX_N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> p[i];
	}

	// 用二进制表示 p 的组合状态，枚举所有 p 的组合
	int result = 0;
	for (int state = 1; state < (1 << m); state++)
	{
		int acc = 1, popcount = 0;
		for (int digit = 0; digit < m; digit++)
		{
			if ((state >> digit) & 1)
			{
				popcount++;
				if (1LL * acc * p[digit] > n)
				{
					// 当前组合非法，乘起来比 n 大了
					acc = -1;
					break;
				}
				acc *= p[digit];
			}
		}

		if (acc != -1)
		{
			// 奇数为正，偶数为负
			if (popcount % 2)
			{
				result += n / acc;
			}
			else
			{
				result -= n / acc;
			}
		}
	}

	cout << result << endl;
	return 0;
}