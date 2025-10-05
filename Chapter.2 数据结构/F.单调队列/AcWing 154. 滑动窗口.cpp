#include <iostream>
#include <deque>
using namespace std;

static const int MAX_N = (1e6 + 10);

int n, k;
int numbers[MAX_N];

// 队列中存储元素的下标，方便比较大小和判断前后位置关系
deque<int> mono_min_index_queue, mono_max_index_queue;

int main()
{
	cin >> n >> k;
	for (int index = 1; index <= n; index++)
	{
		cin >> numbers[index];
	}

	/*
	 *	我们维护有如下性质的队列:从队头到队尾元素大小以及下标递增
	 */
	for (int index = 1; index <= n; index++)
	{
		// 队头超过范围的弹出
		while (mono_min_index_queue.size() && mono_min_index_queue.front() < index - k + 1)
			mono_min_index_queue.pop_front();

		/*
		 * 当前元素编号靠后，若其同时比队尾元素小，则可认定当前窗口内，队尾元素永远不可能输出
		 */
		while (mono_min_index_queue.size() && numbers[mono_min_index_queue.back()] >= numbers[index])
		{
			mono_min_index_queue.pop_back();
		}

		mono_min_index_queue.push_back(index);

		// 左端点在数列中
		if (index - k + 1 >= 1)
		{
			cout << numbers[mono_min_index_queue.front()] << ' ';
		}
	}
	cout << endl;

	/*
	 *	我们维护有如下性质的队列:从队头到队尾元素大小递减，下标递增
	 */
	for (int index = 1; index <= n; index++)
	{
		// 队头超过范围的弹出
		while (mono_max_index_queue.size() && mono_max_index_queue.front() < index - k + 1)
			mono_max_index_queue.pop_front();

		/*
		 * 当前元素编号靠后，若其同时比队尾元素大，则可认定当前窗口内，队尾元素永远不可能输出
		 */
		while (mono_max_index_queue.size() && numbers[mono_max_index_queue.back()] <= numbers[index])
		{
			mono_max_index_queue.pop_back();
		}

		mono_max_index_queue.push_back(index);

		// 左端点在数列中
		if (index - k + 1 >= 1)
		{
			cout << numbers[mono_max_index_queue.front()] << ' ';
		}
	}
	cout << endl;
	return 0;
}