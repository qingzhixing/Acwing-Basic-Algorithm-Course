#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int MAX_N = 110;

int sg_val[MAX_N];
int n;

int sg(int number)
{
	if (sg_val[number] != -1)
	{
		return sg_val[number];
	}

	unordered_set<int> next_state;
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			next_state.insert(sg(i) ^ sg(j));
		}
	}

	for (int i = 0;; i++)
	{
		if (!next_state.count(i))
		{
			return sg_val[number] = i;
		}
	}
}

int main()
{
	memset(sg_val, -1, sizeof(sg_val));

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