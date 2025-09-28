#include <iostream>
using namespace std;

static const int MAX_N = (1e5 + 10);

int m;
int node_value[MAX_N];
int node_next[MAX_N];
int head = 0;
int inserted_node;

int main()
{
	cin >> m;
	while (m--)
	{
		char operation;
		cin >> operation;
		switch (operation)
		{
		case 'I':
		{
			int k, x;
			cin >> k >> x;
			inserted_node++;
			node_value[inserted_node] = x;
			node_next[inserted_node] = node_next[k];
			node_next[k] = inserted_node;
			break;
		}
		case 'D':
		{
			int x;
			cin >> x;
			node_next[x] = node_next[node_next[x]];
			break;
		}
		case 'H':
		{
			int x;
			cin >> x;
			inserted_node++;
			node_value[inserted_node] = x;
			node_next[inserted_node] = node_next[head];
			node_next[head] = inserted_node;
			break;
		}
		}
	}

	int iterator = head;
	while (node_next[iterator])
	{
		iterator = node_next[iterator];
		cout << node_value[iterator] << ' ';
	}
	cout << endl;
	return 0;
}