#include <iostream>
#include <vector>
using namespace std;

static const int MAX_N = 10;
bool used[MAX_N];
vector<int> arrangement;
int n;

void generate_arrangement(int depth)
{
	if (depth > n)
	{
		for (auto item : arrangement)
		{
			cout << item << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			used[i] = true;
			arrangement.push_back(i);
			generate_arrangement(depth + 1);
			arrangement.pop_back();
			used[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	generate_arrangement(1);
	return 0;
}