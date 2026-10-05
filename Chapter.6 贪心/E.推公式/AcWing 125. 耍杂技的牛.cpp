#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	int n;
	cin >> n;

	// weight, strength
	vector<pair<int, long long>> cows;
	for (int i = 0; i < n; i++)
	{
		long long w, s;
		cin >> w >> s;
		cows.emplace_back(w, s);
	}

	// 按照 w + s 排序
	sort(cows.begin(), cows.end(), [](const auto &a, const auto &b)
		 { return (a.first + a.second) < (b.first + b.second); });

	// 计算最大的风险值
	long long max_risk = LLONG_MIN;
	long long presum = 0;
	for (const auto &[weight, strength] : cows)
	{
		max_risk = max(max_risk, presum - strength);
		presum += weight;
	}

	cout << max_risk << endl;
	return 0;
}