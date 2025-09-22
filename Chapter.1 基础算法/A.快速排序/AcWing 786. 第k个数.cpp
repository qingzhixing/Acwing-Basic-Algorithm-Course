#include <iostream>
using std::cin;
using std::cout;
using std::swap;

void QuickSort(int array[], int range_left, int range_right)
{
	if (range_left >= range_right)
		return;

	// Tips: 要向上取整，否则会导致写 pointerLeft 递归时产生边界问题
	int pivot_number = array[(range_left + range_right + 1) / 2];

	int pointer_left = range_left - 1, pointer_right = range_right + 1;

	/*
	 * 我们希望赋予数组以下性质:
	 *	array [range_left,pointer_left] <= pivot_number
	 *	array (pointer_left,range_right] > pivot_number
	 */
	while (pointer_left < pointer_right)
	{
		// 右移左指针到第一个大于pivot_number的数字上
		do
		{
			pointer_left++;
		} while (array[pointer_left] < pivot_number);

		// 左移右指针到第一个小于等于pivot_number的数字上
		do
		{
			pointer_right--;
		} while (array[pointer_right] > pivot_number);

		// Tips:这里两个地方都不加等号，防止指针跨越参考点

		// 如果左右指针依然合法则交换
		if (pointer_left < pointer_right)
		{
			swap(array[pointer_left], array[pointer_right]);
		}
	}

	QuickSort(array, range_left, pointer_left - 1);
	QuickSort(array, pointer_left, range_right);
}

int main()
{
	int n, k;
	const int MAX_N = 1e5 + 10;
	int array[MAX_N]{};

	cin >> n >> k;
	for (auto i = 1; i <= n; i++)
	{
		cin >> array[i];
	}

	QuickSort(array, 1, n);

	cout << array[k] << std::endl;

	return 0;
}