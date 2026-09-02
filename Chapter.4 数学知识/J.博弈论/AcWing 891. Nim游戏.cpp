#include <iostream>
using namespace std;

int main()
{
	int temp = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		temp ^= a;
	}
	cout << (temp == 0 ? "No" : "Yes") << endl;
	return 0;
}