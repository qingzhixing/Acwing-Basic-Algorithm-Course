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

string remove_front_zero(string number)
{
	// 删除前导0
	int first_not_zero = 0;
	int ans_len = number.length();
	while (first_not_zero < ans_len && number[first_not_zero] == '0')
	{
		first_not_zero++;
	}

	string result{};

	for (auto index = first_not_zero; index < ans_len; index++)
	{
		result += number[index];
	}

	if (!result.size())
	{
		result = "0";
	}

	return result;
}

/*
 * 需要保证num1 >= num2
 */
string Minus(string num1, string num2)
{

	// 使低位的下标处于低位
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int minus_index = 0;

	int len_num1 = num1.length();
	int len_num2 = num2.length();

	int borrow = 0, current_digit = 0;

	string answer{};

	// 从低位往高位遍历
	// 此时一定有: len_num2 <= len_num1 (因为num1 >= num2)
	while (minus_index < len_num1)
	{
		if (minus_index >= len_num2)
		{
			current_digit = (num1[minus_index] - '0') - borrow;
			// printf("num1[i] = %d, num2[i] = %d, last_borrow = %d\n", num1[minus_index] - '0', 0, borrow);
			minus_index++;
		}
		else
		{
			current_digit = (num1[minus_index] - '0') -
							(num2[minus_index] - '0') -
							borrow;
			// printf("num1[i] = %d, num2[i] = %d, last_borrow = %d\n", num1[minus_index] - '0', num2[minus_index] - '0', borrow);
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

	return remove_front_zero(answer);
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

	cout << (negative ? "-" : "") << Minus(big, small) << endl;
	return 0;
}