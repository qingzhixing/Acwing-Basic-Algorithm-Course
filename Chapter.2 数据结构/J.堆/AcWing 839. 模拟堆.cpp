#include <iostream>
#include <string>
using namespace std;

static const int MAX_N = (1e5 + 10);

#define LEFT_CHILD_IDX(idx) (2 * idx)
#define RIGHT_CHILD_IDX(idx) (2 * idx + 1)
#define PARENT_IDX(idx) (idx >> 1)

int n;
int number_idx_to_heap_idx[MAX_N];
int heap_idx_to_number_idx[MAX_N];
int number_tail = 0;
int heap_data[MAX_N];
int heap_tail = 0;

// 维护一个 小根堆，保证 二叉堆的根节点 始终 小于等于 子节点

void heap_swap(int heap_idx1, int heap_idx2)
{
	int number_idx1 = heap_idx_to_number_idx[heap_idx1];
	int number_idx2 = heap_idx_to_number_idx[heap_idx2];

	// 交换 heap_idx_to_number_idx
	swap(heap_idx_to_number_idx[heap_idx1], heap_idx_to_number_idx[heap_idx2]);

	// 交换 number_idx_to_heap_idx
	swap(number_idx_to_heap_idx[number_idx1], number_idx_to_heap_idx[number_idx2]);

	// 交换数据
	swap(heap_data[heap_idx1], heap_data[heap_idx2]);
}

void spread_up(int heap_idx)
{
	// 如果当前节点是根节点则停止传播
	if (heap_idx <= 1)
		return;

	// 如果当前节点小于父节点，则需要向上传播
	if (heap_data[heap_idx] < heap_data[PARENT_IDX(heap_idx)])
	{
		heap_swap(heap_idx, PARENT_IDX(heap_idx));
		spread_up(PARENT_IDX(heap_idx));
	}
}

void spread_down(int heap_idx)
{
	// 无左子节点，则同时一定没有右子节点，停止传播
	if (LEFT_CHILD_IDX(heap_idx) > heap_tail)
	{
		return;
	}

	// 有左子节点但是无右子节点
	if (RIGHT_CHILD_IDX(heap_idx) > heap_tail)
	{
		// 如果左子节点比当前节点小，则需要交换并继续传播
		if (heap_data[LEFT_CHILD_IDX(heap_idx)] < heap_data[heap_idx])
		{
			heap_swap(heap_idx, LEFT_CHILD_IDX(heap_idx));
			spread_down(LEFT_CHILD_IDX(heap_idx));
		}
		else
		{
			// 否则停止传播
			return;
		}
	}
	// 有左子节点且有右子节点
	else
	{
		int min_child_idx =
			heap_data[LEFT_CHILD_IDX(heap_idx)] < heap_data[RIGHT_CHILD_IDX(heap_idx)]
				? LEFT_CHILD_IDX(heap_idx)
				: RIGHT_CHILD_IDX(heap_idx);

		// 尝试和最小的子节点交换并且继续传播
		if (heap_data[min_child_idx] < heap_data[heap_idx])
		{
			heap_swap(heap_idx, min_child_idx);
			spread_down(min_child_idx);
		}
		else
		{
			// 停止传播
			return;
		}
	}
}

void insert(int value)
{
	// 插入到堆的最后一个节点
	number_tail++;
	heap_tail++;
	heap_data[heap_tail] = value;
	number_idx_to_heap_idx[number_tail] = heap_tail;
	heap_idx_to_number_idx[heap_tail] = number_tail;
	// 向上传播影响
	spread_up(heap_tail);
}

int top()
{
	return heap_data[1];
}

void erase(int heap_idx)
{
	// 和队尾元素交换并弹出
	heap_swap(heap_idx, heap_tail);
	// 删除映射
	number_idx_to_heap_idx[heap_idx_to_number_idx[heap_tail]] = -1;
	// 弹出
	heap_tail--;
	// 传播影响
	spread_down(heap_idx);
	spread_up(heap_idx);
}

void modify(int heap_idx, int value)
{
	heap_data[heap_idx] = value;

	// 传播影响
	spread_down(heap_idx);
	spread_up(heap_idx);
}

void pop()
{
	erase(1);
}

/*
	I x，插入一个数 x
	PM，输出当前集合中的最小值
	DM，删除当前集合中的最小值（数据保证此时的最小值唯一）
	D k，删除第 k 个插入的数
	C k x，修改第 k 个插入的数，将其变为 x
*/
int main()
{
	cin >> n;
	while (n--)
	{
		string operation;
		cin >> operation;

		if (operation == "I")
		{
			int num;
			cin >> num;
			insert(num);
			continue;
		}
		if (operation == "PM")
		{
			printf("%d\n", top());
			continue;
		}
		if (operation == "DM")
		{
			pop();
			continue;
		}
		if (operation == "D")
		{
			int num_idx;
			cin >> num_idx;
			int heap_idx = number_idx_to_heap_idx[num_idx];
			erase(heap_idx);
			continue;
		}
		if (operation == "C")
		{
			int num_idx, num;
			cin >> num_idx >> num;
			int heap_idx = number_idx_to_heap_idx[num_idx];
			modify(heap_idx, num);
			continue;
		}
		puts("Invalid operation!!!");
	}
	return 0;
}