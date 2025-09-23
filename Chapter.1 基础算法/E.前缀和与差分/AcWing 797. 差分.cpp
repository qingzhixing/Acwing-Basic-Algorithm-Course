#include <iostream>
using namespace std;

static const int MAX_N = (1e5 + 10);

int main()
{
	int n, m;
	int array[MAX_N]{};
	/*
	 * @brief ∑(i=1 to index)(difference[i]) = array[i];
	 */
	int difference[MAX_N]{};

	cin >> n >> m;

	for (auto index = 1; index <= n; index++)
	{
		cin >> array[index];
		// 建立差分数组
		difference[index] = array[index] - array[index - 1];
	}

	int l, r, c;
	while (m--)
	{
		cin >> l >> r >> c;
		difference[l] += c;
		difference[r + 1] -= c;
	}

	// 恢复array
	for (auto index = 1; index <= n; index++)
	{
		array[index] = array[index - 1] + difference[index];
		cout << array[index] << ' ';
	}
	return 0;
}