#include <iostream>
#include <string>
using namespace std;

const int MAX_LENGTH = (1e5);

int main()
{
	string num1, num2;
	cin >> num1 >> num2;

	string ans{};

	int num1_index = num1.size() - 1;
	int num2_index = num2.size() - 1;
	int carry = 0, current_digit = 0;

	while (num1_index >= 0 || num2_index >= 0)
	{
		if (num1_index < 0)
		{
			current_digit = num2[num2_index--] - '0' + carry;
		}
		else if (num2_index < 0)
		{
			current_digit = num1[num1_index--] - '0' + carry;
		}
		else
		{
			current_digit = (num1[num1_index--] - '0') +
							carry +
							(num2[num2_index--] - '0');
		}

		carry = current_digit / 10;
		current_digit %= 10;

		ans = (char)(current_digit + '0') + ans;
	}

	if (carry != 0)
		ans = (char)(carry + '0') + ans;

	cout << ans << endl;
	return 0;
}