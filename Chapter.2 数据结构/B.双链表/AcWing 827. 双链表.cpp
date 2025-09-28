#include <iostream>
#include <string>
using namespace std;

static const int MAX_N = (1e5 + 10);

struct Node
{
	int value;
	int left, right;
} list[MAX_N];

int head, tail, inserted;

/*
 * @return 当前node的索引
 */
int generate_new_node(int value, int left = 0, int right = 0)
{
	inserted++;
	list[inserted].value = value;
	list[inserted].left = left;
	list[inserted].right = right;

	if (head == 0)
		head = inserted;
	if (tail == 0)
		tail = inserted;

	return inserted;
}

void print_list()
{
	return;

	int iterator = head;
	if (iterator)
	{
		printf("(%d, %d) ", iterator, list[iterator].value);
	}
	while (list[iterator].right)
	{
		iterator = list[iterator].right;
		printf("(%d, %d) ", iterator, list[iterator].value);
	}
	cout << endl;
	if (head || tail)
	{
		printf("Head val: %d, Tail val: %d\n", list[head].value, list[tail].value);
	}
}

int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		string operation;
		cin >> operation;
		if (operation == "R")
		{
			int value;
			cin >> value;

			auto index = generate_new_node(value, tail, 0);
			if (tail != index)
			{
				list[tail].right = index;
			}
			tail = index;

			print_list();
			continue;
		}
		if (operation == "L")
		{
			int value;
			cin >> value;

			auto index = generate_new_node(value, 0, head);
			if (head != index)
			{
				list[head].left = index;
			}
			head = index;
			print_list();

			continue;
		}
		if (operation == "D")
		{
			int index;
			cin >> index;

			auto left_index = list[index].left;
			auto right_index = list[index].right;

			list[left_index].right = right_index;
			list[right_index].left = left_index;

			if (head == index)
				head = list[index].right;
			if (tail == index)
				tail = list[index].left;
			print_list();

			continue;
		}
		if (operation == "IL")
		{
			int index, value;
			cin >> index >> value;

			auto new_node_index = generate_new_node(value, list[index].left, index);
			list[list[index].left].right = new_node_index;
			list[index].left = new_node_index;

			if (head == index)
			{
				head = new_node_index;
			}
			print_list();

			continue;
		}
		if (operation == "IR")
		{
			int index, value;
			cin >> index >> value;

			auto new_node_index = generate_new_node(value, index, list[index].right);
			list[list[index].right].left = new_node_index;
			list[index].right = new_node_index;

			if (tail == index)
			{
				tail = new_node_index;
			}
			print_list();

			continue;
		}
	}
	int iterator = head;
	if (iterator)
	{
		cout << list[iterator].value << ' ';
	}
	while (list[iterator].right)
	{
		iterator = list[iterator].right;
		cout << list[iterator].value << ' ';
	}
	cout << endl;
	return 0;
}