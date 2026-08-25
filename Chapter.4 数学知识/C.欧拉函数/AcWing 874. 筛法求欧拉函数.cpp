#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e6 + 10;

// 当前已找出的质数
vector<int> primes;

// 已被筛掉的不是质数的数
bool filtered[MAX_N];

// phi[i] 表示 i 的 欧拉函数值
int phi[MAX_N];

long long eular_sum(int n)
{
	long long result = 0;

	// 线性筛 求 欧拉函数
	phi[1] = 1;
	for (int number = 2; number <= n; number++)
	{
		// 未被筛掉，则说明是质数
		if (!filtered[number])
		{
			primes.push_back(number);
			// 根据欧拉函数性质，质数的 phi 为 它减去一
			phi[number] = number - 1;
		}

		// 根据 number 筛后面的数
		for (auto prime : primes)
		{
			// 越界，不需要继续筛了
			if (prime * number > n)
			{
				break;
			}

			// prime 此时为 prime * number 的最小质因子
			filtered[prime * number] = true;

			// prime 为 number 最小质因子
			if (number % prime == 0)
			{
				// number * prime 和 number 质因子相同，求 phi 公式中只有 N 扩大了 prime 倍
				phi[number * prime] = phi[number] * prime;
				break;
			}
			// number * prime 和 number 质因子不同，多了一个当前的 prime
			// 求 phi 公式中 N 扩大了 prime 倍, 还需要额外乘上一个 (1 - 1 / prime)
			phi[number * prime] = phi[number] * (prime - 1);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		result += phi[i];
	}

	return result;
}

int main()
{
	int n;
	cin >> n;
	cout << eular_sum(n) << endl;
	return 0;
}