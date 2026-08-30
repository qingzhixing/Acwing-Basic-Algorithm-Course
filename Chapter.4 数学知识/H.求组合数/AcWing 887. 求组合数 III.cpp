#include <iostream>
using namespace std;

int n;
long long a, b;
int p;

int quick_pow(int base, int power, int mod)
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

// 求 C(a,b)
int comb(int a, int b, int mod)
{
	// 不存在
	if (b > a)
	{
		return 0;
	}

	// 计算分子
	int numerator = 1;
	for (int i = a; i >= a - b + 1; i--)
	{
		numerator = 1LL * numerator * i % mod;
	}

	// 计算分母
	int denominator = 1;
	for (int i = 1; i <= b; i++)
	{
		denominator = 1LL * denominator * i % mod;
	}

	return 1LL * numerator * quick_pow(denominator, mod - 2, mod) % mod;
}

int lucas(long long a, long long b, int mod)
{
	if (a < p && b < p)
	{
		return comb(a, b, mod);
	}
	return 1LL * comb(a % mod, b % mod, mod) * lucas(a / mod, b / mod, mod) % mod;
}

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> p;
		cout << lucas(a, b, p) << endl;
	}
	return 0;
}