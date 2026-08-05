#include <iostream>
using namespace std;

long long quick_pow(long long base, long long power, long long mod)
{
	long long result = 1;
	base %= mod;
	while (power)
	{
		if (power & 1)
		{
			result = (result * base) % mod;
		}
		power >>= 1;
		base = (base * base) % mod;
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int base, power, mod;
		cin >> base >> power >> mod;
		cout << quick_pow(base, power, mod) << endl;
	}
	return 0;
}