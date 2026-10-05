#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int result = 0;

	for (int i = 0; i < (n / 2); i++)
	{
		result += a[n - i - 1] - a[i];
	}

	cout << result;
	return 0;
}