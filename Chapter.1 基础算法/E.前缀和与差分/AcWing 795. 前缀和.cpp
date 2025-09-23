#include <iostream>
using namespace std;

static const int MAX_N = (1e5 + 10);

int main()
{
	int n, m;
	int array[MAX_N]{};
	/*
	 * @brief prefix_sum[i] = Sum(array)[i] -> (从 array[1]累加至array[i])
	 */
	int prefix_sum[MAX_N]{};

	cin >> n >> m;

	for (auto index = 1; index <= n; index++)
	{
		cin >> array[index];
		// 建立前缀和数组
		prefix_sum[index] = prefix_sum[index - 1] + array[index];
	}

	int l, r;
	while (m--)
	{
		cin >> l >> r;
		cout << prefix_sum[r] - prefix_sum[l - 1] << endl;
	}

	return 0;
}