#include <iostream>
#include <string>
using namespace std;

struct Node
{
	Node *next[30]{};
	int end_count = 0;
};

Node root;

void Insert(string str)
{
	Node *ptr = &root;
	for (int index = 0; index < str.length(); index++)
	{
		int char_index = str[index] - 'a';
		if (!ptr->next[char_index])
		{
			ptr->next[char_index] = new Node;
		}
		ptr = ptr->next[char_index];
	}
	ptr->end_count++;
}

int Query(string str)
{
	Node *ptr = &root;
	for (int index = 0; index < str.length(); index++)
	{
		int char_index = str[index] - 'a';
		if (!ptr->next[char_index])
		{
			return 0;
		}
		ptr = ptr->next[char_index];
	}
	return ptr->end_count;
}

int main()
{
	int n;
	cin >> n;
	char operation;
	string str;
	while (n--)
	{
		cin >> operation >> str;
		switch (operation)
		{
		case 'I':
		{
			Insert(str);
			break;
		}
		case 'Q':
		{
			cout << Query(str) << endl;
			break;
		}
		}
	}
	return 0;
}