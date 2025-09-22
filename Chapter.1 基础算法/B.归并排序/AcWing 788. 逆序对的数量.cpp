#include <iostream>
using std::cin;
using std::cout;
using std::swap;

static const int MAX_N = (1e5 + 10);

/*
 * 进行一次MergeSort我们有如下性质：
 *	array [range_left, range_right] 都是有序的.
 * @return 逆序对的数量
 */
long long MergeSort(int array[], int range_left, int range_right)
{
	long long inverse_pair = 0;
	if (range_left >= range_right)
		return inverse_pair;

	int mid_index = (range_left + range_right) >> 1;

	inverse_pair += MergeSort(array, range_left, mid_index);
	inverse_pair += MergeSort(array, mid_index + 1, range_right);

	/*
	 * 现在我们有如下性质:
	 * 	array[range_left, mid_index],array[mid_index + 1, range_right] 均有序.
	 */
	int temp[range_right - range_left + 10]{};
	int pointer_temp = 0, pointer_left = range_left, pointer_right = mid_index + 1;

	// 合并两段
	while (pointer_temp < range_right - range_left + 1)
	{
		// 左侧放完了
		if (pointer_left > mid_index && pointer_right <= range_right)
		{
			temp[++pointer_temp] = array[pointer_right++];
			continue;
		}

		// 右侧放完了
		if (pointer_right > range_right && pointer_left <= mid_index)
		{
			temp[++pointer_temp] = array[pointer_left++];
			continue;
		}

		// 谁小先放谁
		if (array[pointer_left] <= array[pointer_right])
		{
			temp[++pointer_temp] = array[pointer_left++];
		}
		else
		{
			temp[++pointer_temp] = array[pointer_right++];
			inverse_pair += mid_index - pointer_left + 1;
		}
	}

	// 写入数组
	for (auto i = 1; i <= pointer_temp; i++)
	{
		array[range_left + i - 1] = temp[i];
	}
	return inverse_pair;
}

int main()
{
	int n{}, array[MAX_N];
	cin >> n;
	for (auto i = 1; i <= n; i++)
	{
		cin >> array[i];
	}

	auto inverse_pair = MergeSort(array, 1, n);
	cout << inverse_pair << std::endl;
	return 0;
}