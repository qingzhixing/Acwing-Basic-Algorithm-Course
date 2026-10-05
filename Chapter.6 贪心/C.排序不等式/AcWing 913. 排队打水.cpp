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

	long long presum = 0;
	long long result = 0;
	for (const auto &num : a)
	{
		result += presum;
		presum += num;
	}

	cout << result << endl;
	return 0;
}