#include <iostream>
#include <stack>
using namespace std;

/*
 * 该栈用于维护一段序列，使栈底到栈顶数字递增:
 *	每当插入一个数时与栈顶比较，栈顶较大则弹出栈顶, 直到条件不满足或栈空时插入该数
 */
stack<int> monotonic_stack;

int main()
{
	int n;
	cin >> n;
	int value;
	while (n--)
	{
		cin >> value;
		while (monotonic_stack.size() && monotonic_stack.top() >= value)
		{
			monotonic_stack.pop();
		}
		if (!monotonic_stack.size())
		{
			cout << -1 << ' ';
		}
		else
		{
			cout << monotonic_stack.top() << ' ';
		}
		monotonic_stack.push(value);
	}
	return 0;
}