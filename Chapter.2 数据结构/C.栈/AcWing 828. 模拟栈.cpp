#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int m;
	cin >> m;
	vector<int> stack;
	while (m--)
	{
		string operation;
		cin >> operation;
		if (operation == "push")
		{
			int value;
			cin >> value;

			stack.push_back(value);

			continue;
		}
		if (operation == "query")
		{
			cout << stack.back() << endl;
			continue;
		}
		if (operation == "pop")
		{
			stack.pop_back();
			continue;
		}
		if (operation == "empty")
		{
			cout << (stack.size() ? "NO" : "YES") << endl;
			continue;
		}
	}
	return 0;
}