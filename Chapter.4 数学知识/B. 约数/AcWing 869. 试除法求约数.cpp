#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_divisor(int number)
{
	vector<int> divisors;
	for (int i = 1; i <= number / i; i++)
	{
		if (number % i == 0)
		{
			divisors.push_back(i);
			if (i != number / i)
			{
				divisors.push_back(number / i);
			}
		}
	}
	sort(divisors.begin(), divisors.end());
	for (auto divisor : divisors)
	{
		printf("%d ", divisor);
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int number;
		cin >> number;
		print_divisor(number);
	}
	return 0;
}