#include <iostream>
using namespace std;

// 欧几里得 辗转相除法
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	}
	return 0;
}