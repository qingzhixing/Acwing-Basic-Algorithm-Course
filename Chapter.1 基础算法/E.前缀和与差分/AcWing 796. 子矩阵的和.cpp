#include <iostream>
using namespace std;

static const int MAX_N = (1e3 + 10);

int main()
{
	int n, m, q;
	int array[MAX_N][MAX_N]{};
	/*
	 *	@brief rect_sum[row][column] 为子矩阵 [1,1]~[row,column] 的和
	 */
	int rect_sum[MAX_N][MAX_N]{};

	cin >> n >> m >> q;
	for (auto row = 1; row <= n; row++)
	{
		for (auto column = 1; column <= m; column++)
		{
			cin >> array[row][column];
			// 建立子矩阵和数组
			rect_sum[row][column] = array[row][column] +
									rect_sum[row][column - 1] +
									rect_sum[row - 1][column] -
									rect_sum[row - 1][column - 1];
		}
	}

	int x1, y1, x2, y2;
	while (q--)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		cout << rect_sum[x2][y2] -
					rect_sum[x1 - 1][y2] -
					rect_sum[x2][y1 - 1] +
					rect_sum[x1 - 1][y1 - 1]
			 << endl;
	}
	return 0;
}