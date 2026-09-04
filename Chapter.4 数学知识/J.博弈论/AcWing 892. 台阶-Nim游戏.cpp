#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (i & 1)
		{
			res ^= a;
		}
	}
	if (res)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}