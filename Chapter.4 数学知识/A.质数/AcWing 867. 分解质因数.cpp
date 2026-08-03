#include <iostream>
using namespace std;

void prime_factorization(int number)
{
	for (int i = 2; i <= number / i; i++)
	{
		int times = 0;
		while (number % i == 0)
		{
			number /= i;
			times++;
		}
		if (times != 0)
		{
			printf("%d %d\n", i, times);
		}
	}
	if (number > 1)
	{
		printf("%d %d\n", number, 1);
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
		prime_factorization(number);
	}
	return 0;
}