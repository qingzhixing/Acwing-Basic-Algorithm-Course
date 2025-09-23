#include <iostream>
using namespace std;

static const int MAX_N = (1e3 + 10);

int n, m, q;
int rect_diff[MAX_N][MAX_N]{};

void range_add(int x1, int y1, int x2, int y2, int value)
{
	rect_diff[x1][y1] += value;
	rect_diff[x2 + 1][y1] -= value;
	rect_diff[x1][y2 + 1] -= value;
	rect_diff[x2 + 1][y2 + 1] += value;
}

int main()
{
	cin >> n >> m >> q;

	int current_value;

	for (auto row = 1; row <= n; row++)
	{
		for (auto column = 1; column <= m; column++)
		{
			// 我们可以把原始矩阵的建立当作在1x1的矩阵内加一个值
			cin >> current_value;
			range_add(row, column, row, column, current_value);
		}
	}

	int x1, y1, x2, y2, value;
	while (q--)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> value;
		range_add(x1, y1, x2, y2, value);
	}

	int restored_array[MAX_N][MAX_N]{};

	for (auto row = 1; row <= n; row++)
	{
		for (auto column = 1; column <= m; column++)
		{
			restored_array[row][column] = rect_diff[row][column] +
										  restored_array[row][column - 1] +
										  restored_array[row - 1][column] -
										  restored_array[row - 1][column - 1];

			cout << restored_array[row][column] << ' ';
		}
		cout << endl;
	}

	return 0;
}