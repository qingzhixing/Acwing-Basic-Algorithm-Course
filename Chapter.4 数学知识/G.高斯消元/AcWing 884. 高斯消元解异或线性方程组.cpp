#include <iostream>
using namespace std;

const int MAX_N = 110;

bool a[MAX_N][MAX_N];
int n;

int main()
{
	cin >> n;
	for (auto row = 1; row <= n; row++)
	{
		for (auto col = 1; col <= n + 1; col++)
		{
			cin >> a[row][col];
		}
	}

	// 从第一行第一列开始消元
	int curr_row = 1;
	for (auto curr_col = 1; curr_col <= n; curr_col++)
	{
		// 1.找主元
		auto main_row = curr_row;
		bool find_none_zero = false;
		for (auto row = curr_row; row <= n; row++)
		{
			if (a[row][curr_col] == 1)
			{
				main_row = row;
				find_none_zero = true;
				break;
			}
		}
		// 没找到主元则进入下一列
		if (!find_none_zero)
		{
			continue;
		}

		// 交换当前行与主行
		for (auto col = 1; col <= n + 1; col++)
		{
			swap(a[curr_row][col], a[main_row][col]);
		}

		// 2.其他行消去该元
		for (auto row = 1; row <= n; row++)
		{
			if (row == curr_row)
			{
				continue;
			}
			if (a[row][curr_col] != 1)
			{
				continue;
			}
			for (auto col = 1; col <= n + 1; col++)
			{
				a[row][col] ^= a[curr_row][col];
			}
		}

		// 进入下一行，下一列
		curr_row++;
	}

	// 判断有解性
	bool no_single_solution = false;
	for (auto row = 1; row <= n; row++)
	{
		bool all_zero = true;
		for (auto col = 1; col <= n; col++)
		{
			if (a[row][col] != 0)
			{
				all_zero = false;
				break;
			}
		}
		if (all_zero)
		{
			no_single_solution = true;
			if (a[row][n + 1] == 1)
			{
				// 0 = !0
				cout << "No solution" << endl;
				return 0;
			}
		}
	}
	if (no_single_solution)
	{
		// 0 = 0
		cout << "Multiple sets of solutions" << endl;
		return 0;
	}

	// 输出解
	for (auto row = 1; row <= n; row++)
	{
		cout << a[row][n + 1] << endl;
	}
	return 0;
}