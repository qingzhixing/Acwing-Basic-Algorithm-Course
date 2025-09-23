#include <iostream>
using namespace std;

int main()
{
	int n, number;
	cin >> n;

	while (n--)
	{
		cin >> number;
		int sum = 0;
		while (number)
		{
			sum += number & 1;
			number >>= 1;
		}
		cout << sum << ' ';
	}
	return 0;
}