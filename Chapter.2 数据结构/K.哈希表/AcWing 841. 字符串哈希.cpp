#include <iostream>
using namespace std;

// 字符串哈希进制
static const int P = 131;

static const int MAX_N = 1e5 + 10;

int n, m;
char str[MAX_N];

// 对应字符串前缀的哈希值
unsigned long long hash_value[MAX_N];

// 保存下来的P的幂，避免重复计算
unsigned long long pow_P[MAX_N];

unsigned long long range_hash(int l, int r)
{
	return hash_value[r] - (hash_value[l - 1] * pow_P[r - l + 1]);
}

int main()
{
	cin >> n >> m;
	scanf("%s", str + 1);

	// 计算前缀哈希值
	pow_P[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		hash_value[i] = hash_value[i - 1] * P + str[i];
		pow_P[i] = P * pow_P[i - 1];
	}

	while (m--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (range_hash(l1, r1) != range_hash(l2, r2))
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}