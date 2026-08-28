#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 110;

const double eps = 1e-8;

double a[MAX_N][MAX_N];
int n;

int main()
{
	cin >> n;
	for (int row = 1; row <= n; row++)
	{
		for (int column = 1; column <= n + 1; column++)
		{
			// a[i][n+1] = b[i];
			cin >> a[row][column];
		}
	}

	// 从第一行，第一列开始，进行 高斯-约旦 消元法
	int current_row = 1;
	for (int current_column = 1; current_column <= n; current_column++)
	{
		auto main_row = current_row;
		auto max_val = fabs(a[current_row][current_column]);

		// 1.选择主元
		for (int row = current_row; row <= n; row++)
		{
			if (fabs(a[row][current_column]) > fabs(max_val))
			{
				max_val = a[row][current_column];
				main_row = row;
			}
		}
		// 如果当前列全 0, 则进入下一列
		if (fabs(max_val) - 0 < eps)
		{
			continue;
		}

		// 将主行换至当前行
		for (int column = 1; column <= n + 1; column++)
		{
			swap(a[current_row][column], a[main_row][column]);
		}

		// 2.主元归一
		auto pivot = a[current_row][current_column];
		for (int column = 1; column <= n + 1; column++)
		{
			a[current_row][column] /= pivot;
		}

		// 3.消去其他行该列的元素
		for (int row = 1; row <= n; row++)
		{
			if (row == current_row)
			{
				continue;
			}
			auto rate = a[row][current_column];
			for (int column = 1; column <= n + 1; column++)
			{
				a[row][column] -= rate * a[current_row][column];
			}
		}

		// 4.进入下一行，下一列
		current_row++;
	}

	// 判断解的个数
	bool no_only_solution = false;
	for (int row = 1; row <= n; row++)
	{
		bool left_zero = true;
		for (int column = 1; column <= n; column++)
		{
			if (fabs(a[row][column]) - 0 > eps)
			{
				left_zero = false;
				break;
			}
		}
		if (left_zero)
		{
			no_only_solution = true;
			if (fabs(a[row][n + 1]) - 0 > eps)
			{
				// 存在 0 = 非零
				cout << "No solution" << endl;
				return 0;
			}
		}
	}

	if (no_only_solution)
	{
		// 存在 0 = 0
		cout << "Infinite group solutions" << endl;
		return 0;
	}

	// 输出解
	for (int row = 1; row <= n; row++)
	{
		printf("%.2f\n", a[row][n + 1]);
	}
	return 0;
}