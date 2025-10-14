#include <iostream>
using namespace std;

const int MAX_N = 1e5 + 10;
const int MAX_M = 1e6 + 10;

int n, m;
char str[MAX_M], pattern[MAX_N];
/*
 * nxt数组表示:
 * 	nxt[j] = i 时，pattern[1 ~ i] = pattern[(j-i+1) ~ j];
 */
int nxt[MAX_N];

int main()
{
	cin >> n;
	cin >> pattern + 1;
	cin >> m;
	cin >> str + 1;

	// 计算next数组
	nxt[1] = 0;
	// i正在判断，j是已经判断成立才更新
	for (int i = 2, j = 0; i <= n; i++)
	{
		// 当前正在判断pattern[i]和pattern[j + 1]
		while (j && pattern[i] != pattern[j + 1])
			j = nxt[j];
		if (pattern[i] == pattern[j + 1])
			j++;
		nxt[i] = j;
	}

	// KMP 匹配
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && pattern[j + 1] != str[i])
			j = nxt[j];
		if (pattern[j + 1] == str[i])
			j++;
		if (j == n)
		{
			// 下表从0开始所以不 + 1
			printf("%d ", i - n);

			// 继续匹配
			j = nxt[j];
		}
	}
	return 0;
}