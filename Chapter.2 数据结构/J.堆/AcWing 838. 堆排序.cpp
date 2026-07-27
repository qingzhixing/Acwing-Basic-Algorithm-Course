#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue<int, vector<int>, greater<int>> heap;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		heap.push(num);
	}

	for (int i = 0; i < m; i++)
	{
		printf("%d ", heap.top());
		heap.pop();
	}
	return 0;
}