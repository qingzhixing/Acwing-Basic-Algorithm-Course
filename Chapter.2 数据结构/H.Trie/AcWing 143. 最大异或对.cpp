#include <iostream>
using namespace std;

struct Node
{
	Node *children[2]{};
} root;

void Insert(int num)
{
	// printf("Inserting: %d\n", num);
	Node *ptr = &root;
	for (int bit = 31; bit >= 0; bit--)
	{
		bool current_child = (num >> bit) & 1;
		// printf("\t%d\n", current_child);
		if (ptr->children[current_child] == nullptr)
		{
			ptr->children[current_child] = new Node;
		}
		ptr = ptr->children[current_child];
	}
}

int Query(int num)
{
	// printf("Querying: %d\n", num);
	Node *ptr = &root;
	int result{};
	for (int bit = 31; bit >= 0; bit--)
	{
		bool current_child = !((num >> bit) & 1);
		// printf("\ttarget: %d ", current_child);
		if (ptr->children[current_child] != nullptr)
		{
			// printf("find: %d\n", current_child);
			result |= current_child << bit;
			ptr = ptr->children[current_child];
		}
		else
		{
			// printf("find: %d\n", !current_child);
			result |= (!current_child) << bit;
			ptr = ptr->children[!current_child];
		}
	}
	return result;
}

const int MAX_N = 1e5 + 10;

int main()
{
	int n;
	cin >> n;
	int nums[MAX_N]{};
	for (int index = 1; index <= n; index++)
	{
		cin >> nums[index];
		Insert(nums[index]);
	}
	int max_result = -2147483648;
	for (int index = 1; index <= n; index++)
	{
		max_result = max(max_result, nums[index] ^ Query(nums[index]));
	}

	cout << max_result << endl;
	return 0;
}