#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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
 * @return make_pair(quotient, reminder)
 */
pair<string, int> Divide(string devidend, int divisor)
{
	string quotient{};
	int reminder{};
	/*
	 * 从高位往低位读数字,存入reminder
	 */
	int index = 0;
	int len = devidend.length();
	int digit_quotient{};

	while (index < len)
	{
		// 读入一位数字
		reminder = reminder * 10 + (devidend[index++] - '0');
		digit_quotient = reminder / divisor;
		reminder %= divisor;
		quotient += (char)(digit_quotient + '0');
	}
	return make_pair(remove_front_zero(quotient), reminder);
}

int main()
{
	string devidend;
	int divisor;
	cin >> devidend >> divisor;

	auto ans = Divide(devidend, divisor);

	string quotient = ans.first;
	int reminder = ans.second;

	cout << quotient << endl
		 << reminder << endl;
	return 0;
}