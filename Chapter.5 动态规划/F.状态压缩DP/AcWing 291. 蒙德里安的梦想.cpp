#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 12;
const int MAX_M = 1 << MAX_N;

int n, m;
long long dp[MAX_N][MAX_M];

// 记录状态是否满足连续 0 都为偶数个
bool valid[MAX_M];

// 记录当前状态可以由前面哪些状态转移过来
vector<int> previous_state[MAX_M];

int main()
{
	while (cin >> n >> m, n || m)
	{
		// 初始化 valid
		for (int state = 0; state < (1 << n); state++)
		{
			valid[state] = true;

			// 连续 0 的数量
			int cnt = 0;
			for (int digit = 0; digit < n; digit++)
			{
				if ((state >> digit) & 1)
				{
					if (cnt % 2)
					{
						valid[state] = false;
						break;
					}
					cnt = 0;
				}
				else
				{
					cnt++;
				}
			}
			if (cnt % 2)
			{
				// 检查最后一段连续 0
				valid[state] = false;
			}
		}

		// 初始化 previous_state
		for (int current = 0; current < (1 << n); current++)
		{
			previous_state[current].clear();
			for (int previous = 0; previous < (1 << n); previous++)
			{
				if ((current & previous) == 0 && valid[current | previous])
				{
					previous_state[current].push_back(previous);
				}
			}
		}

		memset(dp, 0, sizeof(dp));
		// i = 0 时，仅有 j = 0 合法, 方案数为 1
		dp[0][0] = 1;
		// 枚举列求状态递推
		for (int i = 1; i <= m; i++)
		{
			for (int state = 0; state < (1 << n); state++)
			{
				for (auto previous : previous_state[state])
				{
					dp[i][state] += dp[i - 1][previous];
				}
			}
		}

		// 最后一列一定什么都不能放
		cout << dp[m][0] << endl;
	}
	return 0;
}