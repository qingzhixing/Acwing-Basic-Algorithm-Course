#include <iostream>
using namespace std;

const int MAX_N = 1e5 + 10;
const int MOD = 1e9 + 7;

int n;
// infact[i] 是 fact[i] 的逆元
long long fact[MAX_N], infact[MAX_N];

long long quick_pow(long long base, long long pow)
{
	long long result = 1;
	while (pow)
	{
		if (pow & 1)
		{
			result = result * base % MOD;
		}
		pow >>= 1;
		base = base * base % MOD;
	}
	return result;
}

int main()
{
	// 预处理 fact 与 infact
	fact[0] = infact[0] = 1;
	for (int i = 1; i < MAX_N; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
		infact[i] = infact[i - 1] * quick_pow(i, MOD - 2) % MOD;
	}

	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << fact[a] * infact[a - b] % MOD * infact[b] % MOD << endl;
	}
	return 0;
}