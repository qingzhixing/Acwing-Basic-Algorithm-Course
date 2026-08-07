#include <iostream>
using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int result = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return result;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b, m;
		int x, y;
		cin >> a >> b >> m;
		int gcd = exgcd(a, m, x, y);
		if (b % gcd != 0)
		{
			cout << "impossible" << endl;
			continue;
		}
		cout << (long long)x * (b / gcd) % m << endl;
	}
	return 0;
}