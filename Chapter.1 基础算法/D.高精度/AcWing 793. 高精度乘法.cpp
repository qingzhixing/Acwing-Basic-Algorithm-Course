#include <iostream>
#include <string>
using namespace std;

string Multiple(string number, int multiplicator)
{
	if (multiplicator == 0)
		return "0";

	string ans{};

	int num_len = number.length();
	int index = num_len - 1, carry = 0, current_digit = 0;

	while (index >= 0)
	{
		current_digit = number[index--] - '0';
		current_digit = current_digit * multiplicator + carry;
		carry = current_digit / 10;
		current_digit %= 10;
		ans = (char)(current_digit + '0') + ans;
	}
	while (carry)
	{
		current_digit = carry % 10;
		carry /= 10;
		ans = (char)(current_digit + '0') + ans;
	}

	return ans;
}

int main()
{
	string number;
	int multiplicator;
	cin >> number >> multiplicator;

	cout << Multiple(number, multiplicator) << endl;

	return 0;
}