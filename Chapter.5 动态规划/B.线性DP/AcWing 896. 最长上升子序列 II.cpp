#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 1e5 + 10;
int n;
int a[MAX_N];

// q[i] 表示长度为 i 的子序列中最小的那个结尾数字
int q[MAX_N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	q[0] = -2e9;
	// 当前 q 的有效长度
	int len = 0;

	for (int i = 1; i <= n; i++)
	{
		int l = 0, r = len;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (q[mid] < a[i])
			{
				l = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
		len = max(len, r + 1);
		q[r + 1] = a[i];
	}

	cout << len << endl;

	return 0;
}