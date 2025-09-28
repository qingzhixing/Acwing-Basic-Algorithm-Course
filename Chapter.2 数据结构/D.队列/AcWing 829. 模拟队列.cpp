#include <iostream>
#include <string>
using namespace std;

static const int MAX_N = (1e5 + 10);

int queue[MAX_N];
int head, tail = -1;

int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		string operation;
		cin >> operation;
		if (operation == "push")
		{
			int value;
			cin >> value;

			queue[++tail] = value;
			continue;
		}
		if (operation == "pop")
		{
			head++;
			continue;
		}
		if (operation == "empty")
		{
			cout << ((tail < head) ? "YES" : "NO") << endl;
			continue;
		}
		if (operation == "query")
		{
			cout << queue[head] << endl;
			continue;
		}
	}
	return 0;
}