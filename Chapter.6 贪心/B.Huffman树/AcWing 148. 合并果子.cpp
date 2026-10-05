#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<>> q;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		q.push(num);
	}

	int result = 0;

	while (q.size() > 1)
	{
		auto a = q.top();
		q.pop();
		auto b = q.top();
		q.pop();
		q.push(a + b);
		result += a + b;
	}

	cout << result << endl;
	return 0;
}