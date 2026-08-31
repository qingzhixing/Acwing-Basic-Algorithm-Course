#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 5010;

int a, b;
bool not_prime[MAX_N];
vector<int> primes;
vector<int> prime_cnt;

void get_primes()
{
	for (int i = 2; i < MAX_N; i++)
	{
		if (!not_prime[i])
		{
			primes.push_back(i);
		}

		for (auto prime : primes)
		{
			if (i * prime >= MAX_N)
			{
				break;
			}
			// 最小质因子筛
			not_prime[i * prime] = true;
			if (i % prime == 0)
			{
				break;
			}
		}
	}
}

// 勒让德公式 计算 n! 中 质因子 p 的个数
int legendre(int n, int p)
{
	int result = 0;
	while (n)
	{
		result += n / p;
		n /= p;
	}
	return result;
}

// 高精度整数存储时低位在前
vector<int> multiply(const vector<int> &a, int b)
{
	vector<int> result;
	int temp = 0;
	for (auto digit : a)
	{
		temp += digit * b;
		result.push_back(temp % 10);
		temp /= 10;
	}
	while (temp)
	{
		result.push_back(temp % 10);
		temp /= 10;
	}
	return result;
}

int main()
{
	get_primes();
	int a, b;
	cin >> a >> b;

	// 对每一个质因子求其在(a,b)中的次数
	for (auto prime : primes)
	{
		int freq = legendre(a, prime) - legendre(b, prime) - legendre(a - b, prime);
		prime_cnt.push_back(freq);
	}

	// 累乘求答案
	vector<int> result = {1};
	for (auto i = 0; i < primes.size(); i++)
	{
		auto prime = primes[i];
		for (auto times = 1; times <= prime_cnt[i]; times++)
		{
			result = multiply(result, prime);
		}
	}

	// 输出
	reverse(result.begin(), result.end());
	for (auto digit : result)
	{
		cout << digit;
	}
	cout << endl;

	return 0;
}