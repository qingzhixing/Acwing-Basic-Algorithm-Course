#include <iostream>
using namespace std;

// 质因数分解求欧拉函数
int phi(int number)
{
	int result = number;
	for (int i = 2; i <= number / i; i++)
	{
		if (number % i == 0)
		{
			// result *= (1 - 1 / i);
			result = result / i * (i - 1);
			while (number % i == 0)
			{
				number /= i;
			}
		}
	}
	if (number > 1)
	{
		// result *= (1 - 1 / number);
		result = result / number * (number - 1);
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int number;
		cin >> number;
		cout << phi(number) << endl;
	}
	return 0;
}