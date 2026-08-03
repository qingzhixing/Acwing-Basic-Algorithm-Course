#include <iostream>
using namespace std;

const int MAX_N = 1e6 + 10;

// 被 质数筛 是否筛掉
bool filtered[MAX_N];
int primes[MAX_N];
int prime_count = 0;

int main()
{
	int n;
	cin >> n;

	// 线性筛法
	// 枚举 2 ~ n 所有数字
	for (int number = 2; number <= n; number++)
	{
		if (!filtered[number])
		{
			// 先前没被筛掉，那么number一定是质数
			primes[prime_count] = number;
			prime_count++;
		}

		// 枚举当前所有质数进行筛选
		for (int prime_idx = 0; primes[prime_idx] <= n / number; prime_idx++)
		{
			// 只用最小质因子筛选
			// 此时 primes[prime_idx] <= number 的最小质因子
			// 故 primes[prime_idx] * number 的最小质因子一定是 primes[prime_idx]
			filtered[primes[prime_idx] * number] = true;
			if (number % primes[prime_idx] == 0)
			{
				// 此时 primes[prime_idx] 一定是 number 的最小质因子
				break;
			}
		}
	}

	cout << prime_count << endl;
	return 0;
}