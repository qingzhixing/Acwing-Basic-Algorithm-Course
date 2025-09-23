#include <iostream>
using namespace std;

static const int MAX_N = (1e5 + 10);

int main()
{
	int len1, len2, x;
	int array1[MAX_N]{}, array2[MAX_N]{};

	cin >> len1 >> len2 >> x;

	for (auto index = 1; index <= len1; index++)
	{
		cin >> array1[index];
	}

	for (auto index = 1; index <= len2; index++)
	{
		cin >> array2[index];
	}

	int pointer1 = 1,
		pointer2 = len2;

	while (pointer1 <= len1)
	{

		// 移动pointer2直到和小于等于x
		while (pointer2 >= 1 && array1[pointer1] + array2[pointer2] > x)
			pointer2--;

		if ((array1[pointer1] + array2[pointer2]) == x)
		{
			printf("%d %d\n", pointer1 - 1, pointer2 - 1);
			return 0;
		}

		pointer1++;
	}
	printf("No Solution\n");
	return 0;
}