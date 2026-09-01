#include <iostream>
using namespace std;

const int MAX_N = 1e5 + 10;
const int MOD = 1e9 + 7;

int quick_power(int base, int power, int mod)
{
	int result = 1;
	while (power)
	{
		if (power & 1)
		{
			result = 1LL * result * base % mod;
		}
		power >>= 1;
		base = 1LL * base * base % mod;
	}
	return result;
}

int main()
{
	int n;
	cin >> n;

	// 总方案数为 C(2n,n)/(n+1)
	int result = 1;
	int a = 2 * n;
	int b = n;
	for (int i = a; i > a - b; i--)
	{
		result = 1LL * result * i % MOD;
	}
	for (int i = 1; i <= b; i++)
	{
		result = 1LL * result * quick_power(i, MOD - 2, MOD) % MOD;
	}
	result = 1LL * result * quick_power(n + 1, MOD - 2, MOD) % MOD;

	cout << result << endl;

	return 0;
}