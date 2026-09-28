#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e8 + 10;

// 截取 digits 第 [lower, higher] 位并返回
int get_range(const vector<int> digits, int lower_idx, int higher_idx)
{
	int result = 0;
	for (int i = higher_idx; i >= lower_idx; i--)
	{
		result = result * 10 + digits[i];
	}
	return result;
}

int power10(int power)
{
	int result = 1;
	for (int i = 1; i <= power; i++)
	{
		result *= 10;
	}
	return result;
}

// 统计 [1, number] 中，数字 d 出现的次数
long long count(int number, int d)
{
	if (number <= 0)
	{
		return 0;
	}

	// 将 number 每一位提取出来，低位在上
	vector<int> digits;
	while (number)
	{
		digits.push_back(number % 10);
		number /= 10;
	}

	// 对 number 每一位求 d 的出现次数，然后累加起来
	long long result = 0;
	for (int i = 0, len = digits.size(); i < len; i++)
	{
		// 跳过 d == 0时的最高位
		if (d == 0 && i == len - 1)
		{
			continue;
		}

		// 处理更高位部分
		// 存在更高位部分
		if (i < len - 1)
		{
			// 高位部分取值个数 [0 ~ higher_part - 1]
			auto higher_cnt = get_range(digits, i + 1, len - 1);
			if (d == 0)
			{
				// 高位部分必须非 0
				higher_cnt--;
			}
			result += higher_cnt * power10(i);
		}

		if (digits[i] == d)
		{
			// 本位 d, 低位 [0, lower_part]
			result += get_range(digits, 0, i - 1) + 1;
			continue;
		}
		if (digits[i] > d)
		{
			// 本位 d, 低位任取
			result += power10(i);
		}
	}

	return result;
}

int main()
{
	while (true)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
			return 0;
		}

		// 保证 a >= b
		if (a < b)
		{
			swap(a, b);
		}

		for (int i = 0; i <= 9; i++)
		{
			cout << count(a, i) - count(b - 1, i) << ' ';
		}
		cout << endl;
	}
	return 0;
}