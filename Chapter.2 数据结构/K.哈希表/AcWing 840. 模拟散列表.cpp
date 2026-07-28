#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static const int MAX_N = 1e5 + 10;

vector<int> hash_table[MAX_N];

// 将 -1e9 ~ 1e9 范围的数字映射到 0 ~ 1e5 中
int hash_mapping(int value)
{
	return (value % MAX_N + MAX_N) % MAX_N;
}

void insert(int value)
{
	hash_table[hash_mapping(value)].push_back(value);
}

bool find(int value)
{
	const auto &list = hash_table[hash_mapping(value)];
	for (const auto &item : list)
	{
		if (item == value)
			return true;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char operation;
		int number;
		cin >> operation >> number;

		if (operation == 'I')
		{
			insert(number);
			continue;
		}

		if (operation == 'Q')
		{
			cout << (find(number) ? "Yes" : "No") << endl;
			continue;
		}

		puts("Invalid operation!!!");
	}
	return 0;
}