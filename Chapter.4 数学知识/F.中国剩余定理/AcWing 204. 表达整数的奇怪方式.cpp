#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 30;

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long result = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return result;
}

// modulus, remainder
queue<pair<long long, long long>> equations;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int modulus, remainder;
		cin >> modulus >> remainder;
		equations.push({modulus, remainder});
	}

	// 执行合并操作
	while (equations.size() >= 2)
	{
		auto [m1, a1] = equations.front();
		equations.pop();
		auto [m2, a2] = equations.front();
		equations.pop();

		// remainder: a1, a2
		// modulus: m1, m2

		// 求解 (k1, k2) 使得 k1 * m1 - k2 * m2 = a2 - a1;

		// 求 (x, y) 使得 m1 * x + m2 * y = gcd(m1, m2);
		long long x, y;
		auto d = exgcd(m1, m2, x, y);

		// 判断无解
		if ((a2 - a1) % d != 0)
		{
			cout << -1 << endl;
			return 0;
		}

		// 得到特解 (k1, k2)
		auto k1 = (a2 - a1) / d * x;
		auto k2 = -(a2 - a1) / d * y;

		// 求 k1 的最小非负整数解
		auto t = m2 / d;
		auto ex_k1 = ((k1 % t) + t) % t;

		// 构造新的方程
		auto modulus = m1 / d * m2; // lcd (m1, m2);
		auto remainder = m1 * ex_k1 + a1;

		equations.push({modulus, remainder});
	}

	// 只剩下一个方程，即可用 exgcd 求解
	auto [modulus, remainder] = equations.front();
	equations.pop();

	// 求解 1*x + modulus * (-y) = remainder;
	long long x, y;
	auto d = exgcd(1, modulus, x, y);

	// 判断是否有解
	if (remainder % d != 0)
	{
		cout << -1 << endl;
		return 0;
	}

	auto result = remainder / d * x;

	// 化为最小非负数
	result = ((result % modulus) + modulus) % modulus;

	cout << result << endl;
	return 0;
}