#include <iostream>
using std::cin;
using std::cout;
using std::swap;

static const int MAX_N = (1e5 + 10);

/*
 * 进行一次MergeSort我们有如下性质：
 *	array [range_left, range_right] 都是有序的.
 */
void MergeSort(int array[], int range_left, int range_right)
{
	if (range_left >= range_right)
		return;

	int mid_index = (range_left + range_right) / 2;

	MergeSort(array, range_left, mid_index);
	MergeSort(array, mid_index + 1, range_right);

	/*
	 * 现在我们有如下性质:
	 * 	array[range_left, mid_index],array[mid_index + 1, range_right] 均有序.
	 */
	int temp[range_right - range_left + 10]{};
	int pointer_temp = 0, pointer_left = range_left, pointer_right = mid_index + 1;

	// 合并两段
	while (pointer_left <= mid_index || pointer_right <= range_right)
	{
		while (pointer_left <= mid_index && (array[pointer_left] <= array[pointer_right] || pointer_right > range_right))
		{
			pointer_temp++;
			temp[pointer_temp] = array[pointer_left];
			pointer_left++;
		}

		while (pointer_right <= range_right && (array[pointer_right] <= array[pointer_left] || pointer_left > mid_index))
		{
			pointer_temp++;
			temp[pointer_temp] = array[pointer_right];
			pointer_right++;
		}
	}

	// 写入数组
	for (auto i = 1; i <= pointer_temp; i++)
	{
		array[range_left + i - 1] = temp[i];
	}
}

int main()
{
	int n{}, array[MAX_N];
	cin >> n;
	for (auto i = 1; i <= n; i++)
	{
		cin >> array[i];
	}

	MergeSort(array, 1, n);

	for (auto i = 1; i <= n; i++)
	{
		cout << array[i] << ' ';
	}
	return 0;
}