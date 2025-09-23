#include <iostream>
using namespace std;

static const int MAX_N = (1e5 + 10);

int main()
{
	int n, m;
	int array1[MAX_N]{}, array2[MAX_N]{};

	cin >> n >> m;
	for (auto index = 1; index <= n; index++)
	{
		cin >> array1[index];
	}
	for (auto index = 1; index <= m; index++)
	{
		cin >> array2[index];
	}

	if (n > m)
	{
		cout << "No" << endl;
		return 0;
	}

	int pointer1 = 1, pointer2 = 1;
	while (pointer1 <= n)
	{
		while (pointer2 <= m && array1[pointer1] != array2[pointer2])
		{
			pointer2++;
		}
		// 找完了还没找到对应的元素则不是子串
		if (pointer2 > m)
		{
			cout << "No" << endl;
			return 0;
		}
		else
		{
			pointer1++;
			pointer2++;
		}
	}
	cout << "Yes" << endl;
	return 0;
}