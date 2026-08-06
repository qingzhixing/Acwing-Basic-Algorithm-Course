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
		int a, b, x, y;
		cin >> a >> b;
		exgcd(a, b, x, y);
		printf("%d %d\n", x, y);
	}
	return 0;
}