#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int MAX_N = 110;
const int MAX_M = 10010;

int n, k;
int s[MAX_N], sg_value[MAX_M];

int sg(int number)
{
	if (sg_value[number] != -1)
	{
		return sg_value[number];
	}

	// 计算 sg 的值
	unordered_set<int> next_state;
	for (int i = 0; i < k; i++)
	{
		if (number >= s[i])
		{
			next_state.insert(sg(number - s[i]));
		}
	}

	for (int i = 0;; i++)
	{
		if (!next_state.count(i))
		{
			return sg_value[number] = i;
		}
	}
}

int main()
{
	memset(sg_value, -1, sizeof(sg_value));

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> s[i];
	}

	cin >> n;
	int result = 0;
	while (n--)
	{
		int number;
		cin >> number;
		result ^= sg(number);
	}

	if (result)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}