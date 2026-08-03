#include <iostream>
using namespace std;

bool is_prime(int number)
{
	if (number < 2)
	{
		return false;
	}

	for (int i = 2; i <= number / i; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int number;
		cin >> number;
		cout << (is_prime(number) ? "Yes" : "No") << endl;
	}
	return 0;
}