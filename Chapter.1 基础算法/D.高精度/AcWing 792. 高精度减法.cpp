#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * @return num1 < num2 ? true : false
 */
bool less_than(string num1, string num2)
{
	int len1 = num1.length(), len2 = num2.length();
	if (len1 < len2)
	{
		return true;
	}
	if (len1 > len2)
	{
		return false;
	}

	for (auto minus_index = 0; minus_index < len1; minus_index++)
	{
		if (num1[minus_index] > num2[minus_index])
			return false;
		if (num1[minus_index] < num2[minus_index])
			return true;
	}

	return false;
}

int main()
{
	string num1, num2;
	cin >> num1 >> num2;

	bool negative = false;

	string big{}, small{};

	// num1 < num2
	if (less_than(num1, num2))
	{
		negative = true;
		big = num2;
		small = num1;
	}
	else
	// num1 >= num2
	{
		negative = false;
		big = num1;
		small = num2;
	}

	// 使低位的下标处于低位
	reverse(big.begin(), big.end());
	reverse(small.begin(), small.end());

	int minus_index = 0;

	int len_big = big.length();
	int len_small = small.length();

	int borrow = 0, current_digit = 0;

	string answer{};

	// 从低位往高位遍历
	// len_small <= len_big
	while (minus_index < len_big)
	{
		if (minus_index >= len_small)
		{
			current_digit = (big[minus_index] - '0') - borrow;
			// printf("big[i] = %d, small[i] = %d, last_borrow = %d\n", big[minus_index] - '0', 0, borrow);
			minus_index++;
		}
		else
		{
			current_digit = (big[minus_index] - '0') -
							(small[minus_index] - '0') -
							borrow;
			// printf("big[i] = %d, small[i] = %d, last_borrow = %d\n", big[minus_index] - '0', small[minus_index] - '0', borrow);
			minus_index++;
		}
		borrow = 0;
		if (current_digit < 0)
		{
			borrow = 1;
			current_digit += 10;
		}

		// printf("Current Digit: %d, Borrow: %d\n", current_digit, borrow);

		answer = (char)(current_digit + '0') + answer;
	}

	// 删除前导0
	int first_not_zero = 0;
	int ans_len = answer.length();
	while (first_not_zero < ans_len && answer[first_not_zero] == '0')
	{
		first_not_zero++;
	}

	string extend_answer{};

	for (auto index = first_not_zero; index < ans_len; index++)
	{
		extend_answer += answer[index];
	}

	if (!extend_answer.size())
	{
		extend_answer = "0";
	}

	cout << (negative ? "-" : "") << extend_answer << endl;
	return 0;
}