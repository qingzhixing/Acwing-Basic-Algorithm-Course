#include <iostream>
using namespace std;

static const int MAX_N = 20;
// queen_col[i] 的值 用于记录 第 i 行 的皇后放在 第几列
int queen_col[MAX_N];

int n;

void print_map()
{
	for (int row = 0; row < n; row++)
	{
		// column
		for (int col = 0; col < n; col++)
		{
			cout << ((col == queen_col[row]) ? "Q" : ".");
		}
		puts("");
	}
	puts("");
}

void place_queen(int current_row)
{
	if (current_row >= n)
	{
		print_map();
		return;
	}

	for (int col = 0; col < n; col++)
	{
		bool place_ok = true;
		for (int row = 0; row < current_row; row++)
		{
			if (queen_col[row] == col ||
				abs(queen_col[row] - col) == abs(row - current_row))
			{
				place_ok = false;
				break;
			}
		}

		if (!place_ok)
		{
			continue;
		}

		queen_col[current_row] = col;
		place_queen(current_row + 1);
	}
}

int main()
{
	cin >> n;
	place_queen(0);
	return 0;
}