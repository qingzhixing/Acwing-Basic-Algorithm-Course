#include <iostream>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
	int n;
	cin >> n;

	unordered_map<int, int> primes;

	while (n--)
	{
		int number;
		cin >> number;

		// 将 number 进行质因数分解

		for (int i = 2; i <= number / i; i++)
		{
			int times = 0;
			while (number % i == 0)
			{
				times++;
				number /= i;

				// 累加加入全局质因数分解表
				primes[i]++;
			}
		}

		if (number > 1)
		{
			primes[number]++;
		}
	}

	long long result = 1;
	for (auto [prime, times] : primes)
	{
		result = result * ((times + 1) % MOD) % MOD;
	}
	cout << result << endl;
	return 0;
}